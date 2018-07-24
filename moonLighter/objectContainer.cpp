#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init()
{


	for (int i = 0; i < 4; ++i)
	{
		_house[i] = new house;
	}
		_house[0]->init("house", tagFloat(10, 288), IMAGEMANAGER->findImage("build_Retaile"));
		_house[1]->init("house", tagFloat(971, 235), IMAGEMANAGER->findImage("build_Top1"));
		_house[2]->init("house", tagFloat(1491, 193), IMAGEMANAGER->findImage("build_Shop"));
		_house[3]->init("house", tagFloat(10, 1294), IMAGEMANAGER->findImage("build_Enchant"));
	for (int i = 0; i < 4; ++i)
	{
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _house[i]);
	}
		//OBJECTMANAGER->addObject(objectType::OBJECT, _house[1]);
	
	return S_OK;
}

void objectContainer::release()
{
}

void objectContainer::update()
{
	//if()
}

void objectContainer::render()
{
	
}
