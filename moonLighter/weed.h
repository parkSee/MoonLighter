#pragma once
#include "gameObject.h"
#include"progressBar.h"
// lejADD ���� Ŭ���� ����

class weed : public gameObject
{
private:
	image * _weed;
	image* _attackedWeed[2];
	image* _dmgFontTen;
	image* _dmgFontOne;
	RECT _dmgFontRc[2];
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
	bool _damaaged;
	int _dmgCount;
	int _dmgImgCount;
	bool _dmg;
	bool _dmgImgCountBool;
	float _dmgImgY;

	bool _noneAttacked;//���ݾȹ޾�����
	bool _isAttacked; // ���ݹ޾Ҵٴ� ��ȣ
	bool _isAttacked2;
	bool _isAttacked3;
	bool _deadEffectBool;
	bool _deadBool;
	int _attackedCount;
	image* _pixelImg;
	RECT _rc[4];
	RECT _rc2; //ü�±��̴� ��Ʈ
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void imgRectMake();
	void damagged();
	void hp();
	void weedFrame();
	void move();
	void pixelCollision();
	RECT getRect() { return rc; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void dead();

	weed() {}
	~weed() {}
};
