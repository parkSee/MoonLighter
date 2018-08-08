#include "stdafx.h"
#include "display.h"
#include "player.h"
#include "inventory.h"
// csyADD [진열 클래스 추가]


HRESULT display::init()
{
	_displaySlot[3] = RectMake(290, 950, 100, 76);
	_displaySlot[2] = RectMake(390, 950, 100, 76);
	_displaySlot[1] = RectMake(290, 1026, 100, 76);
	_displaySlot[0] = RectMake(390, 1026, 100, 76);

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
						switch (_vDisplayItem.size())
						{
						case 1:
							this->_vDisplayItem[0]->_isActive = true;
							break;
						case 2:
							this->_vDisplayItem[0]->_isActive = true;
							this->_vDisplayItem[1]->_isActive = true;
							break;
						case 3:
							this->_vDisplayItem[0]->_isActive = true;
							this->_vDisplayItem[1]->_isActive = true;
							this->_vDisplayItem[2]->_isActive = true;
							break;
						case 4:
							this->_vDisplayItem[0]->_isActive = true;
							this->_vDisplayItem[1]->_isActive = true;
							this->_vDisplayItem[2]->_isActive = true;
							this->_vDisplayItem[3]->_isActive = true;
							break;
						default:
							break;
						}
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
			if (_vDisplayItem[i]->_isActive == true)
			{
				this->_vDisplayItem[i]->_img->render(getMemDC(), _displaySlot[i].left - cam.left, _displaySlot[i].top - cam.top);
			}
		}
	}
}

void display::addDisplayItem(item * _item)
{
	_item->_isActive == true;
	this->_vDisplayItem.push_back(_item);	
}

void display::dp_SetActiveFalse(int num)
{
	if (_vDisplayItem.size() > num)
	_vDisplayItem[num]->_isActive = false;
}

void display::dp_SetActiveTrue(int num)
{
	if (_vDisplayItem.size() > num)
	_vDisplayItem[num]->_isActive = true;
}

void display::dp_setPos(int num, float x, float y)
{
	_displaySlot[num] = RectMake(x,y, 300, 104);
}



void display::subtractDisplay(int num)
{
	if (_vDisplayItem.size() > num)
	{
		this->_vDisplayItem.erase(_vDisplayItem.begin() + num); //니꼬 삭제해
	}
}
