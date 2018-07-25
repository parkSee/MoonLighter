#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init()
{
	//IMAGEMANAGER->addImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));


	for (int i = 0; i < 10; ++i)
	{
		_house[i] = new house;
	}
		_house[0]->init("house", tagFloat(332, 628), IMAGEMANAGER->findImage("build_Retaile"));
		_house[1]->init("house", tagFloat(1201, 425), IMAGEMANAGER->findImage("build_Top1"));
		_house[2]->init("house", tagFloat(1812, 442), IMAGEMANAGER->findImage("build_Shop"));
		_house[3]->init("house", tagFloat(323, 1679), IMAGEMANAGER->findImage("build_Enchant"));
		_house[4]->init("house", tagFloat(1000, 1816), IMAGEMANAGER->findImage("build_Bottom1"));
		_house[5]->init("house", tagFloat(1900, 1725), IMAGEMANAGER->findImage("build_Bottom2"));
		_house[6]->init("house", tagFloat(2642, 1653), IMAGEMANAGER->findImage("build_Bottom3"));
		_house[7]->init("house", tagFloat(2620, 1031), IMAGEMANAGER->findImage("build_Forge"));
		_house[8]->init("house", tagFloat(2429, 2052), IMAGEMANAGER->findImage("build_Well"));
		_house[9]->init("house", tagFloat(1676, 1124), IMAGEMANAGER->findImage("build_Board"));
	for (int i = 0; i < 10; ++i)
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
	
}

void objectContainer::render()
{
	
}
