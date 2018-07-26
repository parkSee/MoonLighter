#pragma once
#include "singletonBase.h"

class cameraManager : public singletonBase<cameraManager>
{

private:
	tagInt _mapSize;	//�ʻ�����

	tagFloat _target;	//Ÿ���� ��ǥ
	tagFloat _oldPos;
	tagFloat _shakePos;	//ī�޶� ��鸲 ��ǥ
	bool _isShake;		//ī�޶� ��鸲 �Ұ�
	float _shakeTimer;	//ī�޶� ��鸲 �ð�
	float _shakeStrenth;//ī�޶� ��鸲 ����
	int _speed;
	float _angle;
	RECT _renderRc;		//ī�޶� ��Ʈ

public:

	tagFloat _pos;		//ī�޶� ��ǥ

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void cameraMove();	//ī�޶� ������

	void cameraSlideMove(float speed);

	//ī�޶� Ÿ�� ����, ������ Ÿ���� �ִٸ� ����Ÿ�ٿ��־�д�
	void connectTarget(float x, float y, float delayTime = 0.0f);
	
	//�ʻ����� ������
	void setMapSize(int width, int height) { _mapSize.x = width; _mapSize.y = height; }

	//�� ������ ������
	tagInt getMapSize() { return _mapSize; }

	//���� ��Ʈ ������
	RECT getRenderRc();
	void setNullTarget(int x, int y, int width, int height)
	{
		_pos.x = x;
		_pos.y = y;
		_renderRc = RectMakeCenter(_pos.x, _pos.y, width, height);
	}


	void shakeCamera(float strenth, float time);


	cameraManager(){}
	~cameraManager(){}
};

