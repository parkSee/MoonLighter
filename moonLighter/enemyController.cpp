#include "stdafx.h"
#include "enemyController.h"

//에너미 컨트롤러에서 해주는건 몇마리 셋팅할것인지와
//오브젝트 매니저에 넣어주는것 

//한마디로 에너미 전체를 움직임을 관리 하는 지휘관같은 존재입니다.

//참고로 오브젝트 매니저는 메인게임에서 이미 업데이트를 돌려주고 있음


HRESULT enemyController::init()
{
	for (int i = 0; i < 2; ++i)
	{
		mini* Mini = new mini;
		Mini->init("enemy", tagFloat(WINSIZEX / 2 + 100 * i, WINSIZEY / 2 + 100));
		
		_vMini.push_back(Mini);
		OBJECTMANAGER->addObject(objectType::ENEMY, Mini);
	}

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
