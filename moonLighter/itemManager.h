#pragma once
#include "gameNode.h"
#include "item.h"
#include "potion.h"


//csyADD [������ �Ŵ��� ���� �� '��' ���]
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
	//item* _liquidItem;
	
public:

	HRESULT init();
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

