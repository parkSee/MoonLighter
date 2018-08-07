#pragma once
#include "singletonBase.h"

class saveData : public singletonBase <saveData>
{
private:
	int _hp;
	float _volume;

public:
	HRESULT init();
	void release();

	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	float getVolume() { return _volume; }
	void setVolume(float vol) { _volume = vol; }

	saveData() {}
	~saveData() {}
};

