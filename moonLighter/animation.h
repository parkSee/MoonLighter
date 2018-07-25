#pragma once
//=============================================================
//	## animation ## (�ִϸ��̼� Ŭ����)
//=============================================================

class animation
{
public:
	typedef vector<POINT> _vFrameList;	//������ ���������� �����ϵ��� �ۺ�����
	typedef vector<int>	_vPlayList;		//������ �÷��� ���(�ε���)

private:
	_vFrameList _frameList;		//������ ��ġ ����
	_vPlayList _playList;		//�÷��� ��� (�ε���)
	int _frameNum;				//������ ����
	int _frameWidth;			//�������� ���α���
	int _frameHeight;			//�������� ���α���
	bool _loop;					//������ų�ų�?

	float _frameUpdateSec;		//������ ������Ʈ��
	float _elapsedSec;			//������ �����
	DWORD _nowPlayIdx;			//���� �÷��� �ε���(�÷��� ��ϰ� ����)
	bool _play;					//�÷��� ���̳�?

public:
	//�ʱ�ȭ(�̹��� ��ü ���α���, ���α���, ���ΰ���, ���ΰ���)
	HRESULT init(int totalW, int totalH, int frameX, int frameY);
	void release();

	//ó������ ������ �ִϸ��̼� ����
	void setPlayFrame(bool reverse = false, bool loop = false);
	//�迭�� ��Ƽ� ����ִ°͸� �ִϸ��̼� ����
	void setPlayFrame(int* playArr, int arrLen, bool loop = false);
	//����, �� ������ ���ؼ� �ִϸ��̼� ����
	void setPlayFrame(int start, int end, bool reverse = false, bool loop = false);

	//�ʴ� ����Ƚ��
	void setFPS(int framePerSec);
	//������ ������Ʈ
	void frameUpdate(float elapsedTime);

	//�÷��� ����
	void start();
	//�÷��� ����
	void stop();
	//�Ͻ�����
	void pause();
	//�ٽ����
	void resume();

	//�ʿ��� �����Լ�
	bool isPlay() { return _play; }
	POINT getFramePos() { return _frameList[_playList[_nowPlayIdx]]; }
	int getFrameWidth() { return _frameWidth; }
	int getFrameHeight() { return _frameHeight; }

	animation() : _frameNum(0), _frameWidth(0), _frameHeight(0), _loop(false), _elapsedSec(0), _nowPlayIdx(0), _play(false) {}
	~animation() {}
};

