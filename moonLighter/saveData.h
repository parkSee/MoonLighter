#pragma once
#include "singletonBase.h"

class saveData : public singletonBase <saveData>
{
private:
	int _hp;

public:
	HRESULT init();
	void release();

	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	saveData() {}
	~saveData() {}
};

