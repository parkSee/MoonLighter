#pragma once
#include "item.h"

// csyADD [포션 클래스 추가 - 아이템 클래스를 상속받는다]

class potion :	public item
{
public:
	potion();
	~potion();
};

