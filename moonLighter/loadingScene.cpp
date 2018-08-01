#include "stdafx.h"
#include "loadingScene.h"


HRESULT loadingScene::init()
{

	_loading = new loading;
	_loading->init();

	_frame = IMAGEMANAGER->addFrameImage("loadingFrame", "./Image/Scene_img/loadingframe.bmp", 1650, 150, 11, 1, true, MAGENTA);

	//�̹��� �� ���� �ε�
	this->loadingImage();
	this->loadingSound();

	_count = _index = 0;
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
	this->frame();
	//�ε��Ϸ��� ������
	if (_loading->loadingDone())
	{
		SCENEMANAGER->loadScene("startScene");
	}
}

void loadingScene::render()
{
	//�ε�Ŭ���� ����
	_loading->render();
	_frame->frameRender(getMemDC(), 200, 450);
}

void loadingScene::frame()
{
	_count++;
	if (_count % 3 == 0)
	{
		_frame->setFrameX(_index);
		_index++;

		if (_index >_frame->getMaxFrameX())
		{
			_index = 0;

		}
	}


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
	this->psySoundLoading();
	this->lejSoundLoading();
	this->lysSoundLoading();
	this->csySoundLoading();
	
	
}

