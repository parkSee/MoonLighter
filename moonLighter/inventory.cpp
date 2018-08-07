#include "stdafx.h"
#include "inventory.h"

HRESULT inventory::init()
{
	_invenImg = IMAGEMANAGER->findImage("inventory");
	_openInven = false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0)
			{
				_invenSlot[i * 5 + j] = RectMake(191 + 69 * j, 160 + 69 * i, 57, 58);
			}
			if (i != 0)
			{
				_invenSlot[i * 5 + j] = RectMake(191 + 69 * j, 14 + 160 + 69 * i, 57, 58);
			}

			_invenPos[i * 5 + j].x = _invenSlot[i * 5 + j].left;
			_invenPos[i * 5 + j].y = _invenSlot[i * 5 + j].top;
		}
	}

	_slotNum = 0;
	_selectSlot = _invenSlot[_slotNum];

	_slotImg = IMAGEMANAGER->findImage("invenSlot");


	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		if (!_openInven)
		{
			_openInven = true;
		}
		else if (_openInven)
		{
			_openInven = false;
		}
	}

	if (_openInven)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (_slotNum < 20 && _slotNum >= 5)
			{
				_slotNum -= 5;
			}

		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			if (_slotNum >= 0 && _slotNum < 15)
			{
				_slotNum += 5;
			}

		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			if (_slotNum > 0)
			{
				_slotNum -= 1;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			if (_slotNum < 19)
			{
				_slotNum += 1;
			}
		}
	}

	_selectSlot = _invenSlot[_slotNum];
}

void inventory::render(HDC hdc)
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (!_openInven)
	{

	}
	else if (_openInven)
	{
		_invenImg->render(getMemDC(), 100, 100, 0, 0, _invenImg->getWidth(), _invenImg->getHeight());
		_slotImg->render(getMemDC(), _selectSlot.left - 5, _selectSlot.top - 5/*, 0, 0, _slotImg->getWidth(), _slotImg->getHeight()*/);

		for (int i = 0; i < _vInvenItem.size(); i++)
		{

			_vInvenItem[i]->_pos = tagFloat(_invenPos[i].x + 10, _invenPos[i].y + 10);
			//RectangleCam(getMemDC(), _vInvenItem[i]->_rc, cam);
			_vInvenItem[i]->_img->render(getMemDC(), _vInvenItem[i]->_pos.x, _vInvenItem[i]->_pos.y);

		}
	}

}

void inventory::addInven(item* _item)
{
	this->_vInvenItem.push_back(_item);
}

void inventory::subtractInven(int num)
{
	this->_vInvenItem.erase(_vInvenItem.begin() + num); //¥œ≤ø ªË¡¶«ÿ
}