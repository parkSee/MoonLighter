#include "stdafx.h"
#include "player.h"



HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);




	//============================== 안건드려도됨
	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	
	return S_OK;
}

void player::release(void)
{
	gameObject::release();
}

void player::update(void)
{
	gameObject::update();

	//============================== 안건드려도됨
	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	//==========================================


}

void player::render(void)
{
	//렉트 확인할때 꼭
	RECT cam = CAMERAMANAGER->getRenderRc();

	//이런식으로 카메라 렉트 만큼 꼭 빼주세요 번거롭겟지만.. 부탁드립니당
	//Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top,rc.right - cam.left, rc.bottom - cam.top); 
	



	

}

