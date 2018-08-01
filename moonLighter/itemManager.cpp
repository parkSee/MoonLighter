#include "stdafx.h"
#include "itemManager.h"
#include "gameObject.h"


// csyADD [아이템 매니저 cpp - 동적할당 해제 누락된 부분 수정, 아이템과 캐릭터 충돌 시 인벤토리에 아이템 들어가도록 처리]


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
	SAFE_DELETE(_potion);
	SAFE_DELETE(_liquidItem);
	SAFE_DELETE(_redCristal);
	SAFE_DELETE(_rebar);
	SAFE_DELETE(_twig);
	SAFE_DELETE(_golemCore);
	SAFE_DELETE(_inven);
}

void itemManager::update()
{
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");

	RECT rcTemp;
	mItemIter miter;
	for (miter = _mItem.begin(); miter != _mItem.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); i++)
		{
			if (IntersectRect(&rcTemp, &_player->getRcBody(), &miter->second[i]->get_collisionBox()))
			{
				switch (miter->first)
				{
				case itemType::POTION:
					_inven->addItem(itemType::POTION, miter->second[i]);
					miter->second[i]->release();
					miter->second.erase(miter->second.begin() + i);
					break;
				case itemType::LIQUIDITEM:
					_inven->addItem(itemType::LIQUIDITEM, miter->second[i]);
					miter->second[i]->release();
					miter->second.erase(miter->second.begin() + i);
					break;
				case itemType::REBAR:
					_inven->addItem(itemType::REBAR, miter->second[i]);
					miter->second[i]->release();
					miter->second.erase(miter->second.begin() + i);
					break;
				case itemType::TWIG:
					_inven->addItem(itemType::TWIG, miter->second[i]);
					miter->second[i]->release();
					miter->second.erase(miter->second.begin() + i);
					break;
				case itemType::REDCRISTAL:
					_inven->addItem(itemType::REDCRISTAL, miter->second[i]);
					miter->second[i]->release();
					miter->second.erase(miter->second.begin() + i);
					break;
				case itemType::GOLEMCORE:
					_inven->addItem(itemType::GOLEMCORE, miter->second[i]);
					miter->second[i]->release();
					miter->second.erase(miter->second.begin() + i);
					break;
				default:
					break;

				}
			}
		}

	}

}

void itemManager::render()
{
	mItemIter miter;
	for (miter = _mItem.begin(); miter != _mItem.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); i++)

		{
			miter->second[i]->render();
		}
	}


}
