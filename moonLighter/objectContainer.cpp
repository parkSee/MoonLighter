#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init()
{
	//IMAGEMANAGER->addImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));


	for (int i = 0; i < 3; ++i)
	{
		_house[i] = new house;
	}
		_house[0]->init("house", tagFloat(332, 628), IMAGEMANAGER->findImage("build_Retaile"));
		_house[1]->init("house", tagFloat(1201, 425), IMAGEMANAGER->findImage("build_Top1"));
		//_house[2]->init("house", tagFloat())

	for (int i = 0; i < 3; ++i)
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
