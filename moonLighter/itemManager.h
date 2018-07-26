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

//csyADD [������ �Ŵ��� ��� - �÷��̾�, �κ��丮 Ŭ���� ���� ����]

namespace itemType
{
	enum Enum	//������ ���� �̳ѹ�
	{
		POTION, LIQUIDITEM, REDCRISTAL, TWIG, REBAR, GOLEMCORE, END
	};
}

class itemManager : public gameNode
{
	unordered_map<itemType::Enum , vector<item*>> _mItem;		//���� �̿��� ������ ���
	typedef unordered_map<itemType::Enum, vector<item*>>::iterator mItemIter;		// ���� �̿��� ������ �ݺ���

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
	player* _player;
	inventory* _inven;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

