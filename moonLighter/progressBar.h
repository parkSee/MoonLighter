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

	int _damage;				//���� �߰��� ��
	int _count;					//���� �߰��� ��
	int _isHit;					//���� �߰��� ��
	image* _progressBar;		//ü�¹� �̹���(���� �Ѱ�)
								
	image* _progressBarFront;	//ü�¹� �� �̹���
	image* _progressBarBack;	//ü�¹� �� �̹���

public:
	//ü�¹� �ʱ�ȭ(���̹���Ű, ���̹���Ű, x, y, ���α���, ���α���)
	HRESULT init(const char* frontImageKey, const char* backImageKey, int x, int y, int width, int height);
	HRESULT init(const char* ImageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight); //���� �߰��� ��
	void release(void);
	void update(void);
	void update_isHit(void);
	void render(void);
	void render_isHit(void);

	//���� ���α׷����� �׽�Ʈ
	void renderHeight();
	void setHeightGuge(float currentHp, float maxHp);

	//ü�¹� ������ �����ϱ�
	void setGauge(float currentHp, float maxHp);
	//���� �������� ü�¹� ������ �����ϱ�
	void setGaugeOfDamage(float currentHp, float maxHp, int damage);

	//ü�¹� ��ġ ��ǥ �����ϱ�
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	//ü�¹� ��Ʈ ��������
	RECT getRect() { return _rcProgress; }

	//hpü�¹ٸ��� ��Ʈ �����ϱ�
	void setRect(int x, int y);

	//�ĸ¾Ҵ��� �����ϱ�
	void setIsHit(bool isHit = true) { _isHit = isHit; }
	void setHpWidth(int hpWidth) { _hpWidth = hpWidth; }

	progressBar() {}
	~progressBar() {}
};

