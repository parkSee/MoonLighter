#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{

	//���߿� ���Ŵ��� �߰��ؼ� �Ű� �����̴ϴ�. 
	//���ʹ� �Ŵ��� �Ҵ�
	_em = new enemyController;
	_em->init();

	CAMERAMANAGER->setMapSize(3000, 2460);

	return S_OK;
}

void dungeonScene::release()
{
}

void dungeonScene::update()
{ 

	OBJECTMANAGER->update();
}

void dungeonScene::render()
{

	CAMERAMANAGER->render(getMemDC());

	OBJECTMANAGER->render(getMemDC());

}
