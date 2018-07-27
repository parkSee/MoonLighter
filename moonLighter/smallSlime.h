#pragma once
#include "gameObject.h"

// lejADD ���� ������ Ŭ���� ����
class smallSlime : public gameObject
{
private:
	image * _smallSlime;
	image* _attackedSmallSlime[2];
	int _count;
	int _currentX;
	int _currentY;

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

	void smallSlimeFrame();
	void move();

	smallSlime() {}
	~smallSlime() {}
};

