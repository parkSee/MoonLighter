#include "stdafx.h"
#include "itemManager.h"
#include "player.h"
#include "inventory.h"
#include "display.h"

HRESULT itemManager::init()
{

	return S_OK;
}

void itemManager::release()
{


}

void itemManager::update()
{
	this->collision();	
}

void itemManager::render(HDC hdc)
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	
	for (int i = 0; i < _vItem.size(); ++i)
	{
		//if (_vItem[i]->_isActive == true)
		//{
			_vItem[i]->render(hdc);
		//}
	}
	
}

void itemManager::appear(itemType::Enum type, tagFloat pos)
{
	
	switch (type)
	{
		case itemType::POTION:
		{
			item* _item;
			_item = new item;
			_item->init(pos, IMAGEMANAGER->findImage("potion"));
			_item->setActive(true);
			_vItem.push_back(_item);
		
		}
		break;
		case itemType::LIQUIDITEM:
		{
			item* _item;
			_item = new item;
			_item->init(pos, IMAGEMANAGER->findImage("liquidItem"));
			_item->setActive(true);
			_vItem.push_back(_item);

		}
		break;
		case itemType::REDCRISTAL:
		{
			item* _item;
			_item = new item;
			_item->init(pos, IMAGEMANAGER->findImage("redCristal"));
			_item->setActive(true);
			_vItem.push_back(_item);
		}
		break;
		case itemType::TWIG:
		{
			item* _item;
			_item = new item;
			_item->init(pos, IMAGEMANAGER->findImage("twig"));
			_item->setActive(true);
			_vItem.push_back(_item);
		}
		break;
		case itemType::REBAR:
		{
			item* _item;
			_item = new item;
			_item->init(pos, IMAGEMANAGER->findImage("rebar"));
			_item->setActive(true);
			_vItem.push_back(_item);
		}
		break;
		case itemType::GOLEMCORE:
		{
			item* _item;
			_item = new item;
			_item->init(pos, IMAGEMANAGER->findImage("golemCore"));
			_item->setActive(true);
			_vItem.push_back(_item);
		}
		break;
		case itemType::END:
		break;
	
	}


}

void itemManager::collision()
{
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	inventory* _inventory = _player->getInven();

	RECT temp;
	
	for (int i = 0; i < _vItem.size(); ++i)
	{
		if(_vItem[i]->_isActive == true)
		{
			if(IntersectRect(&temp,&_player->getRcBody(),&_vItem[i]->_rc))
			{
				if (_inventory->get_vInvenItem().size() < 20)
				{
					_inventory->addInven(_vItem[i]);
					_vItem[i]->setActive(false);
				}
			}
			
		}
	}	

}


