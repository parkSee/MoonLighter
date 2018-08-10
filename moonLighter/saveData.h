#pragma once
#include "singletonBase.h"

class display;

class saveData : public singletonBase <saveData>
{
private:
	int _hp;
	float _volume;
	float _effectVolume;

	display* _display;

public:
	HRESULT init();
	void release();

	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	float getVolume() { return _volume; }
	void setVolume(float vol) { _volume = vol; }

	//
	float getEffectVolume() { return _effectVolume; }
	void setEffectVolume(float _eff) { _effectVolume = _eff; }

	void set_display(display* display) { _display = display; }
	display* get_display() { return _display; }

	saveData() {}
	~saveData() {}
};

