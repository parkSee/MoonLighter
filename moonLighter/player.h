#pragma once
#include "gameNode.h"


class player : public gameNode
{
private:
	
	RECT rc;
	tagFloat pos;
	float _time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	

	player() {}
	~player() {}
};

