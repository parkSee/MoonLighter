#pragma once
#include "gameObject.h"
#include"progressBar.h"

// lejADD ���� ������ Ŭ���� ����
class smallSlime : public gameObject
{
private:
	image * _smallSlime;
	image* _attackedSmallSlime[2];
	progressBar* _hp;
	int _currentHp;
	int _count;
	int _currentX;
	int _currentY;

	float angle;
	float speed;

	bool _xCollision;
	bool _yCollision;
	int _rc0X;
	int _rc0Y;
	int _rc1X;
	int _rc1Y;
	int _rc2X;
	int _rc2Y;
	int _rc3X;
	int _rc3Y;

	bool _damaaged;
	int _dmgCount;
	
	bool _noneAttacked;//���ݾȹ޾�����
	bool _isAttacked; // ���ݹ޾Ҵٴ� ��ȣ
	bool _isAttacked2;
	int _attackedCount;
	image* _pixelImg;
	RECT _rc[4];

public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void imgRectMake();
	void hp();
	void damagged();
	void smallSlimeFrame();
	void pixelCollision();
	RECT getRect() { return rc; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void move();

	smallSlime() {}
	~smallSlime() {}
};

