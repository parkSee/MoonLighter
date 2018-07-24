#pragma once
#include "gameNode.h"
#include "loading.h"

class loadingScene : public gameNode
{
private:
	loading * _loading;
	image* _img;
	
public:

	HRESULT init();
	void release();
	void update();
	void render();


	//�ε��̹��� �Լ�(�̰��� �̹����� ���� �־��)
	void loadingImage();
	//�ε����� �Լ�(�̰��� ���带 ���� �־��)
	void loadingSound();

	void psyImageLoading();
	void lejImageLoading();
	void csyImageLoading();
	void lysImageLoading();


	loadingScene(){}
	~loadingScene(){}
};

