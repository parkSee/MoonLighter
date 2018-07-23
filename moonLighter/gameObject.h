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
	RECT rc;

	virtual HRESULT init(string _objName, tagFloat _pos = tagFloat());
	virtual void release();
	virtual void update();
	virtual void render();
	bool isActiveObject();								//Ȱ��ȭ ���������� ���� �Ұ��� ��ȯ ���ش�.
														//virtual void setDestroy(float time = 0.0f);					//������Ʈ ��������

	bool isLive() { return _isLive; }
	void setIsLive(bool isLive) { _isLive = isLive; }

	gameObject(){}
	virtual	~gameObject(){}
};
