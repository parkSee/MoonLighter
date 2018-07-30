#include "stdafx.h"
#include "inventory.h"

//csyADD [인벤 cpp - 인벤 아이템 선택용 박스 테스트]

HRESULT inventory::init()
{
	_invenImg = IMAGEMANAGER->findImage("inventory");
	_openInven = false;
	_onceOpen = false;

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
				_invenSlot[i * 5 + j] = RectMake(191 + 69 * j, 14+160 + 69 * i, 57, 58);
			}
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
		if (!/*_onceOpen*/_openInven)
		{
			//_onceOpen = true;
			_openInven = true;
		}
		else if (/*_onceOpen*/_openInven)
		{
			//_onceOpen = false;
			_openInven = false;
		}
	}

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

	_selectSlot = _invenSlot[_slotNum];
}

void inventory::render()
{
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char str[367];
		sprintf_s(str, " 포션개수 : %d ", _mItem[itemType::POTION].size());
		TextOut(getMemDC(), 10, 20, str, strlen(str));
		//sprintf(str, "%g", _player->pos.x);
		//TextOut(getMemDC(), 80, 100, str, strlen(str));
		//sprintf(str, "%g", _player->pos.y);
		//TextOut(getMemDC(), 40, 100, str, strlen(str));

	}

	RECT cam = CAMERAMANAGER->getRenderRc();

	if (!_openInven)
	{

	}
	else if (_openInven/* && _onceOpen*/)
	{
		_invenImg->render(getMemDC(), 100, 100, 0, 0, _invenImg->getWidth(), _invenImg->getHeight());
		//Rectangle(getMemDC(), _invenImg->getX() + _invenSlot[0].left, _invenImg->getY() + _invenSlot[0].top,
		//	_invenImg->getX() + _invenSlot[0].right, _invenImg->getY() + _invenSlot[0].bottom);		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//Rectangle(getMemDC(), _invenSlot[i*5+j]);
				//char str[1111];
				//sprintf_s(str, "%d", i*5+j);
				//TextOut(getMemDC(), _invenSlot[i * 5 + j].left, _invenSlot[i * 5 + j].top, str, strlen(str));
			}
		}

		//HBRUSH brush;
		//brush = CreateSolidBrush(RGB(123, 0, 0));
		//Rectangle(getMemDC(), _selectSlot);
		//FillRect(getMemDC(), &_selectSlot, brush);
		//DeleteObject(brush);

		_slotImg->render(getMemDC(), _selectSlot.left -5, _selectSlot.top-5/*, 0, 0, _slotImg->getWidth(), _slotImg->getHeight()*/);
	}



}

void inventory::addItem(itemType::Enum _itemType, item* _item)
{

	vector<item*> temp;
	if (_itemType == itemType::GOLEMCORE)
	{
		temp.push_back(_item);
	}
	_mItem.insert(make_pair(_itemType, temp));

}