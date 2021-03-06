#pragma once
#include "gameNode.h"
#include "player.h"

#include "AIKids.h"
#include "AIGirl.h"
#include"AILink.h"
#include "furnitureContainer.h"
#include "display.h"


class shopScene : public gameNode
{
private:

	player * _player;
	RECT _enterRc;


	AIKids* _aiKid;
	AILink* _aiLink;
	AIGirl* _aiGirl;

	inventory* _inven;
	furnitureContainer* _furniture;
	//image* _counter;
	//image* _display;
	image* _shopDoor;

	image* _buttonUi;
	image* _buttonAction;

	image* _jButton;
	image* _layer;
	
	image* _uiOnDP;
	image* _register;

	display* _display;

	int _exitCount;
	bool _isExit , _isOpen;

	int _count, _index;
	int _count2,_index2;
	int _outCount;
	int _count3, _index3;
	
	int _AICount;

	int _OnDPCount, _OnDPIndex;

	int _RGCount, _RGIndex;

	bool _j;
	bool _button;
	bool _ui;

	float _vol;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void uiFrame();
	void buttonActionFrame();
	void doorFrame();
	void RdoorFrame();
	void OnDP();
	void RegisterMotion();

	shopScene(){}
	~shopScene(){}
};

