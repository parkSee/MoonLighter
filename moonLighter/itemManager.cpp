#include "stdafx.h"
#include "itemManager.h"
#include "gameObject.h"

// csyADD [아이템 매니저 cpp -  아이템 _liquidItem, _twig, _redCristal, _rebar, _golemCore 맵에 insert]

HRESULT itemManager::init()
{
	_potion = new potion;
	_potion->init();
	_mItem.insert(make_pair(itemType::POTION, _potion));

	_liquidItem = new liquidItem;
	_liquidItem->init();
	_mItem.insert(make_pair(itemType::LIQUIDITEM, _liquidItem));

	_redCristal = new redCristal;
	_redCristal->init();
	_mItem.insert(make_pair(itemType::REDCRISTAL, _redCristal));

	_rebar = new rebar;
	_rebar->init();
	_mItem.insert(make_pair(itemType::REBAR, _rebar));

	_twig = new twig;
	_twig->init();
	_mItem.insert(make_pair(itemType::TWIG, _twig));

	_golemCore = new golemCore;
	_golemCore->init();
	_mItem.insert(make_pair(itemType::GOLEMCORE, _golemCore));

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
}

void itemManager::render()
{
	mItemIter miter;
	for (miter = _mItem.begin(); miter != _mItem.end(); ++miter)
	{
		miter->second->render();
	}

}
