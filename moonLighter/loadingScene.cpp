#include "stdafx.h"
#include "loadingScene.h"


HRESULT loadingScene::init()
{

	_loading = new loading;
	_loading->init();

	//�̹��� �� ���� �ε�
	this->loadingImage();
	this->loadingSound();


	return S_OK;
}

void loadingScene::release()
{
	_loading->release();
	SAFE_DELETE(_loading);
}

void loadingScene::update()
{
	_loading->update();
	
	//�ε��Ϸ��� ������
	if (_loading->loadingDone())
	{
		SCENEMANAGER->loadScene("townScene");
	}
}

void loadingScene::render()
{
	//�ε�Ŭ���� ����
	_loading->render();
}

//�ε��̹��� �Լ�(�̰��� �̹����� ���� �־��)
void loadingScene::loadingImage()
{
	this->psyImageLoading();
	this->lejImageLoading();
	this->csyImageLoading();
	this->lysImageLoading();

	
	//IMAGEMANAGER->addImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));

	//_loading->loadFrameImage();
	//_loading->loadSound();

	//�ε��� �ʹ� ������ ����Ǽ� õõ�� ���ư����� �׽�Ʈ������ �����
	
	//IMAGEMANAGER->addImage("mountain", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//��׶��� �̹���
	//_loading->loadImage("mountain", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));



}

//�ε����� �Լ�(�̰��� ���带 ���� �־��)
void loadingScene::loadingSound()
{
	_loading->loadSound("townBGM", "./gameSound/townBGM.mp3", true, true);
	_loading->loadSound("shopBGM", "./gameSound/shopBGM.mp3", true, true);
	_loading->loadSound("will_damaged", "./gameSound/will_damaged.wav", false, false);
	_loading->loadSound("will_shortSwordAttack", "./gameSound/will_shortSwordAttack.wav", false, false);
	_loading->loadSound("will_roll", "./gameSound/will_roll.wav", false, false);
}

