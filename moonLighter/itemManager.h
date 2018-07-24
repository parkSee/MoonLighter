#pragma once

class gameObject;

class itemManager :
	public gameObject
{


public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	itemManager() {}
	~itemManager() {}
};

