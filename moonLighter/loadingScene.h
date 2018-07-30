#pragma once
#include "gameNode.h"
#include "loading.h"

class loadingScene : public gameNode
{
private:
	loading * _loading;
	image* _img;
	image* _frame;
	int _count, _index;
	
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

	void frame();



	loadingScene(){}
	~loadingScene(){}
};

