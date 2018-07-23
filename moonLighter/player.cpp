#include "stdafx.h"
#include "player.h"
#include "mini.h"


HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	
	pos.x = _pos.x;
	pos.y = _pos.y;

	_time = 0.0f;

	rc = RectMakeCenter(pos.x,pos.y, 70, 70);
	


	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	
	return S_OK;
}

void player::release(void)
{
	gameObject::release();
}

void player::update(void)
{
	gameObject::update();

	CAMERAMANAGER->connectTarget(pos.x, pos.y);


	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		pos.x -= 5;

		_probeX = pos.x - 35;

		for (int i = _probeX + 5; i >= _probeX - 5; --i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), i, pos.y);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.x = i + 35;
				break;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		pos.x += 5;

		_probeX = pos.x + 35;

		for (int i = _probeX - 5; i < _probeX + 5; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), i, pos.y);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.x = i - 35;
				break;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		pos.y -= 5;

		_probeY = pos.y - 35;

		for (int i = pos.y + 35; i >= pos.y - 35; i--)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), pos.x, i);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.y = i + 35;
				break;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		pos.y += 5;

		_probeY = pos.y+ 35;

		for (int i = _probeY - 10; i < _probeY + 10; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), pos.x, i);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.y = i - 35;
				break;
			}
		}


	}
	if (KEYMANAGER->isStayKeyDown('T'))
	{
		CAMERAMANAGER->shakeCamera(5.0f, 11.0f);
	}


	rc = RectMakeCenter(pos.x, pos.y, 70, 70);
	
	
	this->collision();
}

void player::render(void)
{
	
	RECT cam = CAMERAMANAGER->getRenderRc();

	//RectangleMake(getMemDC(), pos.x - cam.left, pos.y - cam.top, 70, 70);
	Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	//RectangleMake(getMemDC(), pos.x - cam.left, _probeY - cam.top, 10, 10);
	//RectangleMake(getMemDC(),_probeX- cam.left, pos.y - cam.top, 10, 10);


}


//���ʹ̿� �浹ó��
void player::collision()
{
	RECT temp;
	//findObjects�� �ش� Ÿ�԰� Ű���� ������ �ִ� Ŭ������ ���Ϳ� ��Ƽ� ���� ��ȯ ���ִ� ������ �մϴ�.
	//������! ���� �ּҰ��� ����Ű�� �ֽ��ϴ�. 
	vector<gameObject*> _mini = OBJECTMANAGER->findObjects(objectType::ENEMY, "enemy");

	
	for (int i = 0; i < _mini.size(); ++i)
	{
		if (IntersectRect(&temp, &rc, &_mini[i]->rc))
		{
			//������Ʈ �Ŵ��� ������Ʈ�� ������
			/*
			//���� ������Ʈ�� ��������ʴٸ�
			if (miter->second[i]->isLive() == false)
			{
				miter->second[i]->release();
				SAFE_DELETE(miter->second[i]);
				miter->second.erase(miter->second.begin() + i);
				--i;
				continue;
			}
			
			��� �ڵ尡 �ִµ� �浹�� ������ mini�� �׾���! ��� ������Ʈ �Ŵ����ʿ� Set�Լ��� ��ȣ�� �����ϴ� 
			�׷� ������Ʈ �Ŵ��� �ʿ��� ���͸� ���� �մϴ�. 
			��� �츰 ������ ���͸� ����� ��¼�� ���ص� �׾��ٰ� isLive = false�� �ٲ��ִ°͸����ε� ���͸� �������ݴϴ�.

			����� �츰 ���ʹ̿��� ���������� �ƴ� ������Ʈ �Ŵ����� ���������� �ϰ� �ֱ⿡ ��ü���⿡ �´� �ڵ��� �ϰ� �ִ°��Դϴ�.

			*/
			_mini[i]->setIsLive(false);
			
		}
	}


}
