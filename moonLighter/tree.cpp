#include "stdafx.h"
#include "tree.h"

HRESULT tree::init(string _objName, tagFloat _pos, image * imgName)
{
	gameObject::init(_objName, _pos);

	_img = imgName;

	rc = RectMake(pos.x, pos.y, _img->getWidth(), _img->getHeight());

	_count = _index = 0;

	return S_OK;
}

void tree::release()
{
}

void tree::update()
{
	_count++;

	if (_count % 10 == 0)
	{
		_index++;

	//	_img->setFrameX(0);
		if (_index > _img->getMaxFrameX())
		{
			_index = 0;
		}
	//	_img->setFrameX(_index);
	}

}

void tree::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_img->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top,_index,0);

}
