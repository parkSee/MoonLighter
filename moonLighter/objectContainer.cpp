#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init()
{
	//IMAGEMANAGER->addImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));


	for (int i = 0; i < 11; ++i)
	{
		_house[i] = new house;
		_tree[i] = new tree;
	}
	//집오브젝트
		_house[0]->init("house", tagFloat(332, 530), IMAGEMANAGER->findImage("build_Retaile"));
		_house[1]->init("house", tagFloat(1201, 425), IMAGEMANAGER->findImage("build_Top1"));
		_house[2]->init("house", tagFloat(1812, 442), IMAGEMANAGER->findImage("build_Shop"));
		_house[3]->init("house", tagFloat(323, 1679), IMAGEMANAGER->findImage("build_Enchant"));
		_house[4]->init("house", tagFloat(1000, 1816), IMAGEMANAGER->findImage("build_Bottom1"));
		_house[5]->init("house", tagFloat(1900, 1725), IMAGEMANAGER->findImage("build_Bottom2"));
		_house[6]->init("house", tagFloat(2642, 1653), IMAGEMANAGER->findImage("build_Bottom3"));
		_house[7]->init("house", tagFloat(2620, 1031), IMAGEMANAGER->findImage("build_Forge"));
		_house[8]->init("house", tagFloat(2429, 2052), IMAGEMANAGER->findImage("build_Well"));
		_house[9]->init("house", tagFloat(1676, 1124), IMAGEMANAGER->findImage("build_Board"));
		_house[10]->init("house", tagFloat(465, 899), IMAGEMANAGER->findImage("build_fountain"));
		
	//나무 오브젝트
		_tree[0]->init("tree", tagFloat(2196, 425), IMAGEMANAGER->findImage("tree"));
		_tree[1]->init("tree", tagFloat(1926, 746), IMAGEMANAGER->findImage("tree"));
		_tree[2]->init("tree", tagFloat(1922, 1280), IMAGEMANAGER->findImage("tree"));
		_tree[3]->init("tree", tagFloat(2131, 1581), IMAGEMANAGER->findImage("tree"));
		_tree[4]->init("tree", tagFloat(1108, 756), IMAGEMANAGER->findImage("tree"));
		_tree[5]->init("tree", tagFloat(851, 980), IMAGEMANAGER->findImage("tree"));
		_tree[6]->init("tree", tagFloat(1072, 1292), IMAGEMANAGER->findImage("tree"));
		_tree[7]->init("tree", tagFloat(126, 770), IMAGEMANAGER->findImage("tree"));
		_tree[8]->init("tree", tagFloat(120, 1284), IMAGEMANAGER->findImage("tree"));
		_tree[9]->init("tree", tagFloat(132, 2202), IMAGEMANAGER->findImage("tree"));
		_tree[10]->init("tree", tagFloat(1074, 2160), IMAGEMANAGER->findImage("tree"));

	
	for (int i = 0; i < 11; ++i)
	{
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _house[i]);
		OBJECTMANAGER->addObject(objectType::HOUSE_OBJECT, _tree[i]);
	}
	
	_witch = new npc;
	_witch->init(tagFloat(337,1867),IMAGEMANAGER->findImage("npc_witch"),IMAGEMANAGER->findImage("talkBox"));

	_forge = new npc;
	_forge->init(tagFloat(2411, 985), IMAGEMANAGER->findImage("npc_요성"),IMAGEMANAGER->findImage("요성_talkBox"));
	
	_merchant = new npc;
	_merchant->init(tagFloat(310, 670), IMAGEMANAGER->findImage("npc_응주"), IMAGEMANAGER->findImage("응주_talkBox"));
	
	_bird = new npc;
	_bird->init(tagFloat(1415, 1204), IMAGEMANAGER->findImage("npc_수윤"), IMAGEMANAGER->findImage("수윤_talkBox"));

	return S_OK;
}

void objectContainer::release()
{
	
}

void objectContainer::update()
{
	_witch->talkingRECT(RectMake(356, 1983, 70, 70),tagFloat(427,1880),tagFloat(410,1935));
	_witch->update();

	_forge->talkingRECT(RectMake(2397, 1105, 70, 70), tagFloat(2509, 991), tagFloat(2411, 1000));
	_forge->update();

	_merchant->talkingRECT(RectMake(485, 745, 70, 70), tagFloat(556, 666), tagFloat(548, 679));
	_merchant->update();

	_bird->update();
	_bird->talkingRECT(RectMake(1415, 1204, 70, 70), tagFloat(1444, 1117), tagFloat(1444, 1117));

}

void objectContainer::render()
{
	_witch->render();
	if (_witch->getIstalk() == true)
	{
		_witch->talkingRender("살려주세요...허리가 부서질것 같습니다");
	}

	_forge->render();
	if (_forge->getIstalk() == true)
	{
		_forge->talkingRender("더이상..이미지  작업은  그만...");
	}

	_merchant->render();
	if (_merchant->getIstalk() == true)
	{
		_merchant->talkingRender("실질적  디렉터는  나다.");
	}
	_bird->render();
	if (_bird->getIstalk() == true)
	{
		_bird->talkingRender("이제  한의원에  침맞으러  가자..");
	}
}
