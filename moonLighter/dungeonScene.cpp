#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{

	//lejADD 던전 맵 추가
	//player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	//_player->init("player", tagFloat(WINSIZEX - WINSIZEX / 4, WINSIZEY / 2));
	
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_em = new enemyController;
	_em->init();
	
	_im = new itemManager;
	_im->init();

	IMAGEMANAGER->addImage("Dungeon","./image/Dungeon/던전.bmp",WINSIZEX,WINSIZEY);
	CAMERAMANAGER->setMapSize(WINSIZEX, WINSIZEY);

	

	return S_OK;
}

void dungeonScene::release()
{
}

void dungeonScene::update()
{ 
	CAMERAMANAGER->update();
	OBJECTMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
	}

}

void dungeonScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("Dungeon", getMemDC(),0,0,cam.left,cam.top,WINSIZEX,WINSIZEY);

	OBJECTMANAGER->render(getMemDC());
<<<<<<< HEAD


=======
	_im->render();
>>>>>>> �븘�씠�뀥 �씠誘몄�� 珥덇린�솕 / �븘�씠�뀥 �긽�냽 愿��젴 �뀒�뒪�듃 / 媛� �븘�씠�뀥 �븯�쐞�겢�옒�뒪 �깮�꽦 [二쇱꽍 �븞�떖�븯�뼱�슂 二꾩넚]
}
