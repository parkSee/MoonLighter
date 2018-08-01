#pragma once
#include "gameNode.h"
//=============================================================
//	## progressBar ## (프로그래스바 = 체력바)
//=============================================================

class progressBar : public gameNode
{
private:
	RECT _rcProgress;			//체력바 렉트
	int _x, _y;					//체력바 위치좌표
	float _width;				//체력바 가로길이
	float _height;				//체력바 세로길이

	float _hpWidth;				//체력바 자체 가로길이					내가 추가한거(lysADD)
	float _hpHeight;			//체력바 세로길이							내가 추가한거
	float _currentHpWidth;		//현재 체력								내가 추가한거
	float _beforeHpWidth;		//현재 쳐맞은 후 체력						내가 추가한거
	float _hpDifferential;      //쳐맞기 전 체력과 쳐맞은 후 체력 차이		내가 추가한거

	int _damage;				//내가 추가한 거
	int _count;					//내가 추가한 거
	int _isHit;					//내가 추가한 거
	image* _progressBar;		//체력바 이미지(내가 한거)
								
	image* _progressBarFront;	//체력바 앞 이미지
	image* _progressBarBack;	//체력바 뒤 이미지

public:
	//체력바 초기화(앞이미지키, 백이미지키, x, y, 가로길이, 세로길이)
	HRESULT init(const char* frontImageKey, const char* backImageKey, int x, int y, int width, int height);
	HRESULT init(const char* ImageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight); //내가 추가한 거
	void release(void);
	void update(void);
	void update_isHit(void);
	void render(void);
	void render_isHit(void);

	//세로 프로그래스바 테스트
	void renderHeight();
	void setHeightGuge(float currentHp, float maxHp);

	//체력바 게이지 세팅하기
	void setGauge(float currentHp, float maxHp);
	//맞은 데미지로 체력바 게이지 세팅하기
	void setGaugeOfDamage(float currentHp, float maxHp, int damage);

	//체력바 위치 좌표 세팅하기
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	//체력바 렉트 가져오기
	RECT getRect() { return _rcProgress; }

	//hp체력바만의 렉트 세팅하기
	void setRect(int x, int y);

	//쳐맞았는지 세팅하기
	void setIsHit(bool isHit = true) { _isHit = isHit; }
	void setHpWidth(int hpWidth) { _hpWidth = hpWidth; }

	progressBar() {}
	~progressBar() {}
};

