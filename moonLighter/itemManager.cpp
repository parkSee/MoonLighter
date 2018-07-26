#include "stdafx.h"
#include "itemManager.h"
#include "gameObject.h"

// csyADD [아이템 매니저 cpp - 플레이어 동적할당 (렉트 충돌 위한) , 인벤토리 동적할당 (아이템 획득처리 용)]

HRESULT itemManager::init()
{
	_potion = new potion;
	_potion->init();
	_vPotion.push_back(_potion);
	_mItem.insert(make_pair(itemType::POTION, _vPotion));
	
	_liquidItem = new liquidItem;
	_liquidItem->init();
	_vLiquidItem.push_back(_liquidItem);
	_mItem.insert(make_pair(itemType::LIQUIDITEM, _vLiquidItem));
	
	_redCristal = new redCristal;
	_redCristal->init();
	_vRedCristal.push_back(_redCristal);
	_mItem.insert(make_pair(itemType::REDCRISTAL, _vRedCristal));
	
	_rebar = new rebar;
	_rebar->init();
	_vRebar.push_back(_rebar);
	_mItem.insert(make_pair(itemType::REBAR, _vRebar));
	
	_twig = new twig;
	_twig->init();
	_vTwig.push_back(_twig);
	_mItem.insert(make_pair(itemType::TWIG, _vTwig));
	
	_golemCore = new golemCore;
	_golemCore->init();
	_vGolemCore.push_back(_golemCore);
	_mItem.insert(make_pair(itemType::GOLEMCORE, _vGolemCore));	

	_player = new player;
	_inven = new inventory;
	

	//_liquidItem = new item;
	/*_potion->init("potion", tagFloat(WINSIZEX / 2, WINSIZEY / 2));	
	_mItem.insert(make_pair(itemType::POTION, _potion));*/

	/*
	_liquidItem->init("liquidItem", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	_mItem.insert(make_pair(itemType::LIQUIDITEM, _liquidItem));
	*/
	/*OBJECTMANAGER->addObject(ITEM, _potion);

	OBJECTMANAGER->addObject(ITEM, _liquidItem);*/

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	RECT rcTemp;
	mItemIter miter;
	for (miter = _mItem.begin(); miter != _mItem.end(); ++miter)
	{			
			switch (miter->first)
			{
			case itemType::POTION:					
				for (int i = 0; i < _vPotion.size(); i++)
				{
					if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
					{
						_inven->addItem(miter->second[i]);
						miter->second[i]->release();
						SAFE_DELETE(miter->second[i]);
						break;
					}
				}
				break;
			case itemType::LIQUIDITEM:
				for (int i = 0; i < _vLiquidItem.size(); i++)
				{
					if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
					{
						_inven->addItem(miter->second[i]);
						miter->second[i]->release();
						SAFE_DELETE(miter->second[i]);
						break;
					}
				}
				break;
			case itemType::REBAR:
				for (int i = 0; i < _vRebar.size(); i++)
				{
					if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
					{
						_inven->addItem(miter->second[i]);
						miter->second[i]->release();
						SAFE_DELETE(miter->second[i]);
						break;
					}
				}
				break;
			case itemType::TWIG:
				for (int i = 0; i < _vTwig.size(); i++)
				{
					if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
					{
						_inven->addItem(miter->second[i]);
						miter->second[i]->release();
						SAFE_DELETE(miter->second[i]);
						break;
					}
				}
				break;
			case itemType::GOLEMCORE:
				for (int i = 0; i < _vGolemCore.size(); i++)
				{
					if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
					{
						_inven->addItem(miter->second[i]);
						miter->second[i]->release();
						SAFE_DELETE(miter->second[i]);
						break;
					}
				}
				break;
			case itemType::REDCRISTAL:
				for (int i = 0; i < _vRedCristal.size(); i++)
				{
					if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
					{
						_inven->addItem(miter->second[i]);
						miter->second[i]->release();
						SAFE_DELETE(miter->second[i]);
						break;
					}
				}
				break;
			default:
				break;
			}		
	}
	

}

void itemManager::render()
{
	mItemIter miter;
	for (miter = _mItem.begin(); miter != _mItem.end(); ++miter)
	{	
		switch (miter->first)
		{
		case itemType::POTION:
			for (int i = 0; i < _vPotion.size(); i++)
			{
				miter->second[i]->render();
			}
			break;
		case itemType::LIQUIDITEM:
			for (int i = 0; i < _vLiquidItem.size(); i++)
			{
				miter->second[i]->render();
			}
			break;
		case itemType::REBAR:
			for (int i = 0; i < _vRebar.size(); i++)
			{
				miter->second[i]->render();
			}
			break;
		case itemType::TWIG:
			for (int i = 0; i < _vTwig.size(); i++)
			{
				miter->second[i]->render();
			}
			break;
		case itemType::GOLEMCORE:
			for (int i = 0; i < _vGolemCore.size(); i++)
			{
				miter->second[i]->render();
			}
			break;
		case itemType::REDCRISTAL:
			for (int i = 0; i < _vRedCristal.size(); i++)
			{
				miter->second[i]->render();
			}
			break;
		default:
			break;
		}

		
	}

}
