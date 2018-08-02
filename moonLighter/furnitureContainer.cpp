#include "stdafx.h"
#include "furnitureContainer.h"

HRESULT furnitureContainer::init()
{

	for (int i = 0; i < 3; ++i)
	{
		_furniture[i] = new furniture;
	}
	_furniture[0]->init("counter", tagFloat(606, 894), IMAGEMANAGER->findImage("counter"));
	_furniture[1]->init("display", tagFloat(290, 950), IMAGEMANAGER->findImage("display"));
	_furniture[2]->init("display", tagFloat(_furniture[1]->pos.x + IMAGEMANAGER->findImage("display")->getWidth(), 950), IMAGEMANAGER->findImage("display"));
	for (int i = 0; i < 3; ++i)
	{
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _furniture[i]);
	}

	return S_OK;
}

void furnitureContainer::release()
{
}

void furnitureContainer::update()
{
}

void furnitureContainer::render()
{
}
