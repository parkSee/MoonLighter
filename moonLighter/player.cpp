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


//에너미와 충돌처리
void player::collision()
{
	RECT temp;
	//findObjects는 해당 타입과 키값을 가지고 있는 클래스를 벡터에 담아서 값을 반환 해주는 역할을 합니다.
	//포인터! 같은 주소값을 가르키고 있습니다. 
	vector<gameObject*> _mini = OBJECTMANAGER->findObjects(objectType::ENEMY, "enemy");

	
	for (int i = 0; i < _mini.size(); ++i)
	{
		if (IntersectRect(&temp, &rc, &_mini[i]->rc))
		{
			//오브젝트 매니저 업데이트로 가보면
			/*
			//만약 오브젝트가 살아있지않다면
			if (miter->second[i]->isLive() == false)
			{
				miter->second[i]->release();
				SAFE_DELETE(miter->second[i]);
				miter->second.erase(miter->second.begin() + i);
				--i;
				continue;
			}
			
			라는 코드가 있는데 충돌이 됬으면 mini는 죽었어! 라고 오브젝트 매니저쪽에 Set함수로 신호를 보냅니다 
			그럼 오브젝트 매니저 쪽에서 벡터를 삭제 합니다. 
			고로 우린 일일히 벡터를 지우고 어쩌고 안해도 죽었다고 isLive = false로 바꿔주는것만으로도 벡터를 삭제해줍니다.

			참고로 우린 에너미에게 직접접근이 아닌 오브젝트 매니저로 간접접근을 하고 있기에 객체지향에 맞는 코딩을 하고 있는것입니다.

			*/
			_mini[i]->setIsLive(false);
			
		}
	}


}
