#include "stdafx.h"
#include "enemyController.h"

//에너미 컨트롤러에서 해주는건 몇마리 셋팅할것인지와
//오브젝트 매니저에 넣어주는것 

//한마디로 에너미 전체를 움직임을 관리 하는 지휘관같은 존재입니다.

//참고로 오브젝트 매니저는 메인게임에서 이미 업데이트를 돌려주고 있음


HRESULT enemyController::init()
{
	_golem = new golem;
	_golem->init("golem", tagFloat(WINSIZEX/2, WINSIZEY/2));
	
	
	OBJECTMANAGER->addObject(objectType::ENEMY, _golem);
	return S_OK;
}

void enemyController::release()
{


}

void enemyController::update()
{



}

void enemyController::render()
{
	

}
