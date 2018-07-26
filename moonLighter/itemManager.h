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

//csyADD [������ �Ŵ��� ��� - �÷��̾� Ŭ���� ������ ����]

namespace itemType
{
	enum Enum	//������ ���� �̳ѹ�
	{
		POTION, LIQUIDITEM, REDCRISTAL, TWIG, REBAR, GOLEMCORE, END
	};
}

class itemManager : public gameNode
{
	unordered_map<itemType::Enum , item*> _mItem;		//���� �̿��� ������ ���
	typedef unordered_map<itemType::Enum, item*>::iterator mItemIter;		// ���� �̿��� ������ �ݺ���

	item* _potion;
	item* _liquidItem;
	item* _twig;
	item* _redCristal;
	item* _rebar;
	item* _golemCore;
	player* _player;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

