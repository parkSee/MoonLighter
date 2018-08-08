#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init()
{
	//IMAGEMANAGER->addImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));


	for (int i = 0; i < 10; ++i)
	{
		_house[i] = new house;
		_tree[i] = new tree;
	}
	//집오브젝트
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
		
	//나무 오브젝트
		_tree[0]->init("tree", tagFloat(2196, 425), IMAGEMANAGER->findImage("tree"));
		_tree[1]->init("tree", tagFloat(1926, 746), IMAGEMANAGER->findImage("tree"));
		_tree[2]->init("tree", tagFloat(1922, 1280), IMAGEMANAGER->findImage("tree"));
		_tree[3]->init("tree", tagFloat(2131, 1581), IMAGEMANAGER->findImage("tree"));
		_tree[4]->init("tree", tagFloat(1108, 756), IMAGEMANAGER->findImage("tree"));
		_tree[5]->init("tree", tagFloat(851, 980), IMAGEMANAGER->findImage("tree"));
		_tree[6]->init("tree", tagFloat(1072, 1292), IMAGEMANAGER->findImage("tree"));
		_tree[7]->init("tree", tagFloat(126, 762), IMAGEMANAGER->findImage("tree"));
		_tree[8]->init("tree", tagFloat(120, 1284), IMAGEMANAGER->findImage("tree"));
		_tree[9]->init("tree", tagFloat(132, 2202), IMAGEMANAGER->findImage("tree"));
	
	
	for (int i = 0; i < 10; ++i)
	{
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _house[i]);
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _tree[i]);
	}
	_witch = new npc;
	_witch->init(tagFloat(337,1867),IMAGEMANAGER->findImage("npc_witch"));
		
	return S_OK;
}

void objectContainer::release()
{
	
}

void objectContainer::update()
{
	_witch->talkingRECT(RectMake(356, 1983, 70, 70),tagFloat(427,1880),tagFloat(410,1935));
	_witch->update();
}

void objectContainer::render()
{
	_witch->render();
	if (_witch->getIstalk() == true)
	{
		_witch->talkingRender("살려주세요...허리가 부서질것 같습니다");
	}
}
