#pragma once
#include "gameNode.h"
#include "loading.h"

class loadingBossRoom : public gameNode
{
private:

	loading * _loading;
	image* _img;
	image* _loadingFrame;
	int _count, _index;


	int textCount;
	int textIndex;


public:


	HRESULT init();
	void release();
	void update();
	void render();


	//�ε��̹��� �Լ�(�̰��� �̹����� ���� �־��)
	void loadingImage();
	//�ε����� �Լ�(�̰��� ���带 ���� �־��)
	void loadingSound();

	void psyDungeonLoading();
	//void psySoundLoading();
	void lejDungeonLoading();
	//void lejSoundLoading();
	void csyDungeonLoading();
	//void csySoundLoading();
	void lysDungeonLoading();
	//void lysSoundLoading();

	void frame();
	void textLoading();

	loadingBossRoom(){}
	~loadingBossRoom(){}
};

