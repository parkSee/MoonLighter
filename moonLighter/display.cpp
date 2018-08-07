#include "stdafx.h"
#include "display.h"
#include "player.h"
#include "inventory.h"
// csyADD [진열 클래스 추가]


HRESULT display::init()
{
	_displaySlot[0] = RectMake(290, 950, 100, 76);
	_displaySlot[1] = RectMake(390, 950, 100, 76);
	_displaySlot[2] = RectMake(290, 1026, 100, 76);
	_displaySlot[3] = RectMake(390, 1026, 100, 76);

	return S_OK;
}

void display::release()
{

}

void display::update()
{
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	inventory* _inventory = _player->getInven();
	

	RECT rcTemp;
	for (int i = 0; i < 4; i++)
	{
		if (IntersectRect(&rcTemp, &_displaySlot[i], &_player->getRcProbe()))
		{
			if (_player->getInven()->get_openInven() == true)
			{
				if (KEYMANAGER->isOnceKeyDown('J'))
				{
					if (_inventory->get_vInvenItem().size() > 0 && this->_vDisplayItem.size() < 4)
					{
						this->addDisplayItem(_inventory->get_vInvenItem()[0]);
						_inventory->subtractInven(0);
					}
				}
			}
		}
	}
}

void display::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	for (int i = 0; i < _vDisplayItem.size(); i++)
	{
		if (_vDisplayItem.size() < 5)
		{
			this->_vDisplayItem[i]->_img->render(getMemDC(), _displaySlot[i].left - cam.left, _displaySlot[i].top -cam.top);
		}
	}
}

void display::addDisplayItem(item * _item)
{
	this->_vDisplayItem.push_back(_item);	
}

void display::subtractDisplay(int num)
{
	this->_vDisplayItem.erase(_vDisplayItem.begin() + num); //니꼬 삭제해
}
