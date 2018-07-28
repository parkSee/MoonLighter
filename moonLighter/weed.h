#pragma once
#include "gameObject.h"
#include"progressBar.h"
// lejADD ���� Ŭ���� ����

class weed : public gameObject
{
private:
	image * _weed;
	image* _attackedWeed[2];
	progressBar* _hp;
	int _currentHp;
	int _count;
	int _weedFrameX;
	int _weedFrameY;

	int _rc0X;
	int _rc0Y;
	int _rc1X;
	int _rc1Y;
	int _rc2X;
	int _rc2Y;
	int _rc3X;
	int _rc3Y;

	float angle;
	float speed;

	bool _xCollision;
	bool _yCollision;

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
	void weedFrame();
	void move();
	void pixelCollision();
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }

	weed() {}
	~weed() {}
};
