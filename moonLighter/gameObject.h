#pragma once
#include "gameNode.h"

class gameObject : public gameNode
{
private:
	bool _isActive;
	bool _isLive;


public:
	tagFloat pos;
	string name;
	int hp;
	int attack;
	
	RECT rc;

	virtual HRESULT init(string _objName, tagFloat _pos = tagFloat());
	virtual void release();
	virtual void update();
	virtual void render();
	bool isActiveObject();								//활성화 상태인지에 대한 불값을 반환 해준다.
														//virtual void setDestroy(float time = 0.0f);					//오브젝트 삭제명령

	bool isLive() { return _isLive; }
	void setIsLive(bool isLive) { _isLive = isLive; }

	void setIsActive(bool isActive) { _isActive = isActive; }

	gameObject(){}
	virtual	~gameObject(){}
};

