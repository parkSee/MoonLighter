#include "stdafx.h"
#include "itemManager.h"
#include "gameObject.h"

HRESULT itemManager::init()
{

	_potion = new potion;
	_potion->init();
	_mItem.insert(make_pair(itemType::POTION, _potion));


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
