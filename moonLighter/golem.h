#pragma once
#include "gameObject.h"
#include"progressBar.h"
#define golemMaxImg 4

class golem : public gameObject
{
private:
	//lejADD [�� Ŭ���� ����]
	image * _golem[4];
	image* _attackedGolem[8];
	progressBar* _hp;
	int _currentHp;

	int _currentX[4]; // ���� X ������ ��ǥ�� ����
	int _currentY[4];
	int _tempCurrent;
	int _count;
	float tempX;
	float tempY;
	int _attackCount[4];
	bool _attackCountBool[4];
	bool _startAttack;//�� ���ݽ��۽�ȣ
	bool _isAttack;//���� �������ִ���

	bool _noneAttacked;//���ݾȹ޾�����
	bool _isAttacked; // ���ݹ޾Ҵٴ� ��ȣ
	bool _isAttacked2;
	bool _isDead;
	int _attackedCount;


	bool _left;
	bool _right;
	bool _down;
	bool _up;


	
	float speed;
	float angle;
	float distance;



public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	RECT getRect() { return rc; }
	void imgRectMake();
	void hp();
	void golemFrame();
	void golemAttack();
	void move();


	void key();

	golem() {}
	~golem() {}
};
