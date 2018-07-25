#pragma once
#include "gameNode.h"
#include "item.h"
#include "potion.h"
#include "liquidItem.h"
#include "redCristal.h"
#include "twig.h"
#include "rebar.h"
#include "golemCore.h"

//csyADD [아이템 매니저 헤더 - 아이템 _liquidItem, _twig, _redCristal, _rebar, _golemCore 추가]

namespace itemType
{
	enum Enum	//아이템 종류 이넘문
	{
		POTION, LIQUIDITEM, REDCRISTAL, TWIG, REBAR, GOLEMCORE, END
	};
}

class itemManager : public gameNode
{
	unordered_map<itemType::Enum , item*> _mItem;		//맵을 이용한 아이템 목록
	typedef unordered_map<itemType::Enum, item*>::iterator mItemIter;		// 맵을 이용한 아이템 반복자

	item* _potion;
	item* _liquidItem;
	item* _twig;
	item* _redCristal;
	item* _rebar;
	item* _golemCore;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

