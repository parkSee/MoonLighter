#pragma once
#include "gameObject.h"
#define golemMaxImg 4

class golem : public gameObject
{
private:
	//lejADD [�� Ŭ���� ����]
	image * _golem[4];
	
	
	

	int _currentX[4]; // ���� X ������ ��ǥ�� ����
	int _currentY;
	
	int _count;

	int _attackCount[4];
	bool _attackCountBool[4];
	

	bool _left;
	bool _right;
	bool _down;
	bool _up;

	int _alpha; //�򽽶��� ĳ���� �������� ���İ�




public:
	HRESULT init(string _objName, tagFloat _pos );
	void release();
	void update();
	void render();

	void golemFrame();
	void bigSlimeFrame();

	void key();

	golem() {}
	~golem() {}
};

