#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## 초기화 ## init(void)
//=============================================================

HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	
	//인트로 씬
	SCENEMANAGER->addScene("startScene", new startScene);
	SCENEMANAGER->addScene("loadingScene", new loadingScene);
	SCENEMANAGER->addScene("townScene", new townScene);
	SCENEMANAGER->addScene("shopScene", new shopScene);
	SCENEMANAGER->addScene("dungeonScene", new dungeonScene);
	SCENEMANAGER->addScene("dungeonLobby", new dungeonLobby);

	/*현재씬 설정*/
	SCENEMANAGER->loadScene("loadingScene");


	
	return S_OK;
}

//=============================================================
//	## 해제 ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();

	
}

//=============================================================
//	## 업데이트 ## update(void)
//=============================================================
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	SOUNDMANAGER->update();
	EFFECTMANAGER->update();

}

//=============================================================
//	## 렌더 ## render(void)
//=============================================================
void mainGame::render(void)
{
	//흰색 빈 비트맵(이것도 렌더에 그냥 둘것!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================
	


	SCENEMANAGER->render();
	EFFECTMANAGER->render();
//=============================================================
	//백버퍼의 내용을 HDC에 그린다 (이것도 렌더에 그냥 둘것!!)
	this->getBackBuffer()->render(getHDC());
}
