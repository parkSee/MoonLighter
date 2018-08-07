#pragma once
#include "gameNode.h"
//=============================================================
//	## progressBar ## (���α׷����� = ü�¹�)
//=============================================================

class progressBar : public gameNode
{
private:
	RECT _rcProgress;			//ü�¹� ��Ʈ
	int _x, _y;					//ü�¹� ��ġ��ǥ
	float _width;				//ü�¹� ���α���
	float _height;				//ü�¹� ���α���

	float _hpWidth;				//ü�¹� ��ü ���α���					���� �߰��Ѱ�(lysADD)
	float _hpHeight;			//ü�¹� ���α���							���� �߰��Ѱ�
	float _currentHpWidth;		//���� ü��								���� �߰��Ѱ�
	float _beforeHpWidth;		//���� �ĸ��� �� ü��						���� �߰��Ѱ�
	float _hpDifferential;      //�ĸ±� �� ü�°� �ĸ��� �� ü�� ����		���� �߰��Ѱ�

	int _heal;
	int _damage;				
	int _count;					
	float _speed;
	bool _isHit;				
	bool _isHealed;
	image* _progressBar;		//ü�¹� �̹���(���� �Ѱ�)
								
	image* _progressBarFront;	//ü�¹� �� �̹���
	image* _progressBarBack;	//ü�¹� �� �̹���

public:
	//ü�¹� �ʱ�ȭ(���̹���Ű, ���̹���Ű, x, y, ���α���, ���α���)
	HRESULT init(const char* frontImageKey, const char* backImageKey, int x, int y, int width, int height);
	HRESULT init(const char* ImageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight); //���� �߰��� ��
	void release(void);
	void update(void);
	void update_jyp(void);
	void render(void);
	void render_jyp(void);

	//���� ���α׷����� �׽�Ʈ
	void renderHeight();
	void setHeightGuge(float currentHp, float maxHp);

	//ü�¹� ������ �����ϱ�
	void setGauge(float currentHp, float maxHp);
	//���� �������� ü�¹� ������ �����ϱ�
	void setGaugeOfDamage(float currentHp, float maxHp, int damage, float speed = 0.2);
	void setGaugeOfHeal(float currentHp, float maxHp, int heal, float speed = 0.2);
	//ü�¹� ��ġ ��ǥ �����ϱ�
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	//ü�¹� ��Ʈ ��������
	RECT getRect() { return _rcProgress; }

	//hpü�¹ٸ��� ��Ʈ �����ϱ�
	void setRect(int x, int y);

	//�ĸ¾Ҵ��� �����ϱ�
	void setIsHit(bool isHit = true) { _isHit = isHit; }
	void setIsHealed(bool isHealed = true) { _isHealed = isHealed; }
	void setHpWidth(int hpWidth) { _hpWidth = hpWidth; }

	progressBar() {}
	~progressBar() {}
};

