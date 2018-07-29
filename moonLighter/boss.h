#pragma once
#include "gameObject.h"
#include"progressBar.h"

class boss :public gameObject
{
private:
	image * _boss[9];
	image* _attackedBoss[16];
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


	bool _leftUp;
	bool _rightUp;
	bool _leftDown;
	bool _rightDown;



	float speed;
	float angle;
	float distance;
	image* _pixelImg;
	RECT _rc[4];
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void imgRectMake();
	void damagged();
	void hp();
	void bossFrame();
	void bossAttack();
	void move();
	void pixelCollision();
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }

	boss() {}
	~boss() {}
};

