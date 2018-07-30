#include "stdafx.h"
#include "inventory.h"

// csyADD [인벤토리 cpp - additem함수 내용 수정 (벡터x 맵 사용o)]

HRESULT inventory::init()
{
	_invenImg = IMAGEMANAGER->findImage("inventory");
	_openInven = false;
	_onceOpen = false;
	return S_OK;

	_invenSlot[0] = RectMake(91, 60, 57, 58);
}

void inventory::release()
{
}

void inventory::update()
{
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		if (!_onceOpen)
		{
			_onceOpen = true;
			_openInven = true;
		}
		else if (_onceOpen)
		{
			_onceOpen = false;
			_openInven = false;
		}
	}

}

void inventory::render()
{
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char str[367];
		sprintf(str, " 포션개수 : %d ", _mItem[itemType::POTION].size());
		TextOut(getMemDC(), 10, 20, str, strlen(str));
		sprintf(str, "%g", _player->pos.x);
		TextOut(getMemDC(), 80, 100, str, strlen(str));
		sprintf(str, "%g", _player->pos.y);
		TextOut(getMemDC(), 40, 100, str, strlen(str));

	}

	RECT cam = CAMERAMANAGER->getRenderRc();

	if (!_openInven)
	{

	}
	else if (_openInven && _onceOpen)
	{
		_invenImg->render(getMemDC(),/* _player->pos.x - cam.left -*/ 100,/* _player->pos.y - cam.top - */100, 0, 0, _invenImg->getWidth(), _invenImg->getHeight());
		//Rectangle(getMemDC(), _invenImg->getX() + _invenSlot[0].left - cam.left, _invenImg->getY() + _invenSlot[0].top - cam.top,
		//	_invenImg->getX() + _invenImg->getWidth() + _invenSlot[0].right, _invenImg->getY() + _invenImg->getHeight() + _invenSlot[0].bottom);
		RectangleCam(getMemDC(), _invenSlot[0], cam);

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