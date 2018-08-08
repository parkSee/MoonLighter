#include "stdafx.h"
#include "npc.h"

HRESULT npc::init(tagFloat pos, image* img)
{

	_pos = pos;
	_img = img;
	_rc = RectMakeCenter(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());



	_count = _index = 0;
	return S_OK;
}

void npc::release()
{
}

void npc::update()
{



}

void npc::render()
{
	_img->frameRender(getMemDC(), _pos.x, _pos.y);

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
		}

		_img->setFrameX(_index);
	}


}
