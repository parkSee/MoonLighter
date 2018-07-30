#include "stdafx.h"
#include "lobbyContainer.h"

HRESULT lobbyContainer::init()
{

	for (int i = 0; i < 9; ++i)
	{
		_lobbyObj[i] = new stone;
	}

	_lobbyObj[0]->init("lobbyObj", tagFloat(1104, 2050), IMAGEMANAGER->findImage("bottomLeftRock"));
	_lobbyObj[1]->init("lobbyObj", tagFloat(1476, 1974), IMAGEMANAGER->findImage("bottomRight2Rock"));
	_lobbyObj[2]->init("lobbyObj", tagFloat(939, 1836), IMAGEMANAGER->findImage("middleLeftRock"));
	_lobbyObj[3]->init("lobbyObj", tagFloat(1366, 1694), IMAGEMANAGER->findImage("middleRighttRock"));
	_lobbyObj[4]->init("lobbyObj", tagFloat(1111, 1389), IMAGEMANAGER->findImage("topLeft3Rock"));
	_lobbyObj[5]->init("lobbyObj", tagFloat(1400, 1391), IMAGEMANAGER->findImage("topRightRock"));
	_lobbyObj[6]->init("lobbyObj", tagFloat(1322, 1180), IMAGEMANAGER->findImage("entryStructure"));
	_lobbyObj[7]->init("lobbyObj", tagFloat(1244, 470), IMAGEMANAGER->findImage("top3LongBoard"));
	_lobbyObj[8]->init("lobbyObj", tagFloat(683, 1100), IMAGEMANAGER->findImage("bottomLeftTent"));

	for (int i = 0; i < 9; ++i)
	{
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _lobbyObj[i]);
	}
	return S_OK;
}

void lobbyContainer::release()
{
}

void lobbyContainer::update()
{
}

void lobbyContainer::render()
{
}
