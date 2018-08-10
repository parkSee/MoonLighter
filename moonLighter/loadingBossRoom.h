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


	//로딩이미지 함수(이곳에 이미지를 전부 넣어라)
	void loadingImage();
	//로딩사운드 함수(이곳에 사운드를 전부 넣어라)
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

