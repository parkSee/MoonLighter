#pragma once
#include "gameNode.h"
#include "item.h"
#include "potion.h"
#include "liquidItem.h"
#include "redCristal.h"
#include "twig.h"
#include "rebar.h"
#include "golemCore.h"
#include "player.h"
#include "inventory.h"

//csyADD [아이템 매니저 헤더 - 네임스페이스 삭제 (공유를 위해 유틸헤더로 이동)]



class itemManager : public gameNode
{

	item* _potion;
	item* _liquidItem;
	item* _twig;
	item* _redCristal;
	item* _rebar;
	item* _golemCore;
	
	vector<item*> _vPotion;
	vector<item*> _vLiquidItem;
	vector<item*> _vTwig;
	vector<item*> _vRedCristal;
	vector<item*> _vRebar;
	vector<item*> _vGolemCore;
	
	inventory* _inven;

	unordered_map<itemType::Enum , vector<item*>> _mItem;		//맵을 이용한 아이템 목록
	typedef unordered_map<itemType::Enum, vector<item*>>::iterator mItemIter;		// 맵을 이용한 아이템 반복자

public:

	HRESULT init();
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

