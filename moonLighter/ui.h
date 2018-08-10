#pragma once
#include "gameNode.h"

namespace uiState
{
	enum Enum
	{
		IDLE,
		SOUND,
		SOUNDON,
		SOUNDOFF,
		VOLUME,
		END
	};

}

struct volRect
{
	image* blockImg;
	RECT rc;
	bool isActive;

};

class ui : public gameNode
{
private:
	image * _bookImg;
	image* _selectImg[2];
	image* _soundImg[2];
	image* _inActiveSoundImg[2];

	image* _currSound;
	image* _currSelect;
	tagInt _selecPos;
	tagInt _onoffPos;

	volRect _volRect[9];
	RECT _rc[2];
	bool _isOpen;
	POINT _pos;
	uiState::Enum _state;
	bool _isOn;

	float _vol;
	float _effectVol;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	bool getIsOpen() { return _isOpen; }
	void setIsOpen(bool open) { _isOpen = open; }

	float getVolume() { return _vol; }
	void setVolume(float vol) { _vol = vol; }

	float getEffectVol() { return _effectVol; }
	void setEffectVol(float _eff) { _effectVol = _eff; }

	ui(){}
	~ui(){}
};

