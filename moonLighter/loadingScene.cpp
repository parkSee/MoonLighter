#include "stdafx.h"
#include "loadingScene.h"


HRESULT loadingScene::init()
{

	_loading = new loading;
	_loading->init();

	_frame = IMAGEMANAGER->addFrameImage("loadingFrame", "./Image/Scene_img/loadingframe.bmp", 1650, 150, 11, 1, true, MAGENTA);

	//이미지 및 사운드 로딩
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
	//로딩완료후 씬변경
	if (_loading->loadingDone())
	{
		SCENEMANAGER->loadScene("startScene");
	}
}

void loadingScene::render()
{
	//로딩클래스 렌더
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


//로딩이미지 함수(이곳에 이미지를 전부 넣어라)
void loadingScene::loadingImage()
{
	this->psyImageLoading();
	this->lejImageLoading();
	this->csyImageLoading();
	this->lysImageLoading();

	
	//IMAGEMANAGER->addImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));

	//_loading->loadFrameImage();
	//_loading->loadSound();

	//로딩이 너무 빠르게 진행되서 천천히 돌아가도록 테스트용으로 만들기
	
	//IMAGEMANAGER->addImage("mountain", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//백그라운드 이미지
	//_loading->loadImage("mountain", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));



}

//로딩사운드 함수(이곳에 사운드를 전부 넣어라)
void loadingScene::loadingSound()
{
	this->psySoundLoading();
	this->lejSoundLoading();
	this->lysSoundLoading();
	this->csySoundLoading();
	
	
}

