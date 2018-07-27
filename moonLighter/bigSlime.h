#pragma once
#include "gameObject.h"


// lejADD ū ������ Ŭ���� ���� 
class bigSlime : public gameObject
{
private:
	image * _bigSlime;
	image* _attackedBigSlime[2];
	int _count;
	int _currentX;
	int _currentY;
	int _alpha;
	bool _slimeBool;

	float angle;
	float speed;

	bool _noneAttacked;//���ݾȹ޾�����
	bool _isAttacked; // ���ݹ޾Ҵٴ� ��ȣ
	bool _isAttacked2;
	int _attackedCount;


public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void bigSlimeFrame();
	void move();

	bigSlime() {}
	~bigSlime() {}
};

