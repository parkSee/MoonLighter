#include "stdafx.h"
#include "npc.h"
#include "player.h"

HRESULT npc::init(tagFloat pos, image* img)
{
	_talkImg = IMAGEMANAGER->findImage("talking");
	_pos = pos;
	_img = img;
	_rc = RectMakeCenter(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());
	

	_timer = 0;
	_count = _index = 0;
	_count2 = _index2 = 0;
	_isFrame = false;
	_isCollision = false;
	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	

	//시간되면 프레임 돌리기
	_timer++;
	if (_timer % 200 == 0)
	{
		_isFrame = true;
	}
	if (_isFrame)
		this->frame();

	


}

void npc::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_img->frameRender(getMemDC(), _pos.x - cam.left, _pos.y - cam.top);
	
	
	RectangleCam(getMemDC(), _talkRc,cam);
	
	if (_isCollision)
	{
		_talkImg->frameRender(getMemDC(), 427 - cam.left, 1880 - cam.top);
	}


}

void npc::frame()
{
	_count++;

	if (_count % 10 == 0)
	{
		_index++;

		_img->setFrameX(0);
		if (_index > _img->getMaxFrameX())
		{
			_index = 0;
			_isFrame = false;
		}

		_img->setFrameX(_index);
	}


}

void npc::talkingFrame()
{

	_count2++;

	if (_count2 % 10 == 0)
	{
		_index2++;

		//_talkImg->setFrameX(0);
		if (_index2 > _talkImg->getMaxFrameX())
		{
			_index2 = _talkImg->getMaxFrameX();
			
		}
		_talkImg->setFrameX(_index2);

	}


}

void npc::talkingRECT(RECT rc)
{
	//_talkRc = RectMakeCenter(356, 1983)
	RECT temp;
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	_talkRc = rc;
	if (IntersectRect(&temp, &_player->rc, &_talkRc))
	{
		_isCollision = true;
		
		if (KEYMANAGER->isOnceKeyDown('J'))
		{
			//대화창이 나온다
		}
	}
	else
	{
		_isCollision = false;
		_index2 = 0;
	}

	if (_isCollision)
		this->talkingFrame();
}
