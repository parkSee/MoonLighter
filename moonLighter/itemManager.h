#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [������ �Ŵ��� Ŭ���� �߰�]

// ������ Ÿ�� �̳ѹ�
enum itemType
{
	POTION, RIQUIDITEM, REDCRISTAL, TWIG, REBAR, GOLEMCORE, END
};


class itemManager : public gameObject
{
	unordered_map<itemType, vector<item*>> _mItem;					// ���� �̿��� ������ 
	typedef unordered_map<itemType, vector<item*>>::iterator mItemIter;	// ������ �ݺ���

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

