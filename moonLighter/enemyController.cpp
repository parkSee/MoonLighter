#include "stdafx.h"
#include "enemyController.h"

//���ʹ� ��Ʈ�ѷ����� ���ִ°� ��� �����Ұ�������
//������Ʈ �Ŵ����� �־��ִ°� 

//�Ѹ���� ���ʹ� ��ü�� �������� ���� �ϴ� ���ְ����� �����Դϴ�.

//����� ������Ʈ �Ŵ����� ���ΰ��ӿ��� �̹� ������Ʈ�� �����ְ� ����


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
