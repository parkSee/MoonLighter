#pragma once
#include "item.h"

// csyADD [���� Ŭ���� �߰� - ������ Ŭ������ ��ӹ޴´�]

class potion :	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	potion(){}
	~potion(){}
};

