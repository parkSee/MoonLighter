#include "stdafx.h"
#include "player.h"



HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);




	//============================== �Ȱǵ������
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

	//============================== �Ȱǵ������
	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	//==========================================


}

void player::render(void)
{
	//��Ʈ Ȯ���Ҷ� ��
	RECT cam = CAMERAMANAGER->getRenderRc();

	//�̷������� ī�޶� ��Ʈ ��ŭ �� ���ּ��� ���ŷӰ�����.. ��Ź�帳�ϴ�
	//Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top,rc.right - cam.left, rc.bottom - cam.top); 
	



	

}

