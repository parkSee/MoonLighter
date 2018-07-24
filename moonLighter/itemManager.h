#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [아이템 매니저 클래스 추가]

// 아이템 타입 이넘문
enum itemType
{
	POTION, RIQUIDITEM, REDCRISTAL, TWIG, REBAR, GOLEMCORE, END
};


class itemManager : public gameObject
{
	unordered_map<itemType, vector<item*>> _mItem;					// 맵을 이용한 아이템 
	typedef unordered_map<itemType, vector<item*>>::iterator mItemIter;	// 아이템 반복자

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

