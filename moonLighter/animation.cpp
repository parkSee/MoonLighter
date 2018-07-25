#include "stdafx.h"
#include "animation.h"

HRESULT animation::init(int totalW, int totalH, int frameX, int frameY)
{
	//���������� ����ũ��
	_frameWidth = totalW / frameX;

	//���������� ����ũ��
	_frameHeight = totalH / frameY;

	//���������� ����
	_frameNum = frameX * frameY;

	//�̹��� ��ġ ����
	_frameList.clear();
	for (int i = 0; i < frameY; i++)
	{
		for (int j = 0; j < frameX; j++)
		{
			POINT framePos;
			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;

			//������ ��ġ ��� ���Ϳ� ���
			_frameList.push_back(framePos);
		}
	}

	//�⺻ ���������� ����
	setPlayFrame();

	return S_OK;
}

void animation::release()
{
}

//ó������ ������ �ִϸ��̼� ����
void animation::setPlayFrame(bool reverse, bool loop)
{
	//��������
	_loop = loop;
	//�÷��� ��� �ʱ�ȭ
	_playList.clear();

	if (reverse)
	{
		if (loop)
		{
			//������
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//������
			for (int i = _frameNum - 2; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//������
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//������
			for (int i = _frameNum - 2; i >= 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else//�������� �ƴϴ�
	{
		//������
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}
	}
}
//�迭�� ��Ƽ� ����ִ°͸� �ִϸ��̼� ���� (���� ���� ���)
void animation::setPlayFrame(int * playArr, int arrLen, bool loop)
{
	//��������
	_loop = loop;
	//�÷��� ��� �ʱ�ȭ
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

//����, �� ������ ���ؼ� �ִϸ��̼� ����
void animation::setPlayFrame(int start, int end, bool reverse, bool loop)
{
	//��������
	_loop = loop;
	//�÷��� ��� �ʱ�ȭ
	_playList.clear();

	//���۰� �� ������ ������ ������� ����� �ʿ� ����
	if (start == end)
	{
		stop();
		_playList.clear();
		return;
	}

	//������������ ���������Ӻ��� ū���
	if (start > end)
	{
		int temp = start;
		start = end;
		end = temp;
	}

	if (reverse)
	{
		if (loop)
		{
			//������
			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
			//������
			for (int i = end - 1; i > start; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			//������
			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
			//������
			for (int i = end - 1; i >= start; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else//������ �ƴ�
	{
		//������
		for (int i = start; i <= end; i++)
		{
			_playList.push_back(i);
		}
	}
}

void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}

void animation::frameUpdate(float elapsedTime)
{
	//�÷��� ���̳�?
	if (_play)
	{
		_elapsedSec += elapsedTime;
		//������ ������Ʈ �ð��� �ٵǾ��ٸ�
		if (_elapsedSec >= _frameUpdateSec)
		{
			_elapsedSec -= _frameUpdateSec;
			_nowPlayIdx++;
			if (_nowPlayIdx == _playList.size())
			{
				if (_loop)
				{
					_nowPlayIdx = 0;
				}
				else
				{
					_nowPlayIdx--;
					_play = false;
				}
			}
		}
	}
}

void animation::start()
{
	_play = true;
	_nowPlayIdx = 0;
}

void animation::stop()
{
	_play = false;
	_nowPlayIdx = 0;
}

void animation::pause()
{
	_play = false;
}

void animation::resume()
{
	_play = true;
}
