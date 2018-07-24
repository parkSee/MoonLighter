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
	_weed = new weed;
	_weed->init("weed", tagFloat(500, 300));
	_smallSlime = new smallSlime;
	_smallSlime->init("smallSlime", tagFloat(200, 100));
	_bigSlime = new bigSlime;
	_bigSlime->init("bigSlime", tagFloat(600, 600));

	OBJECTMANAGER->addObject(objectType::ENEMY, _bigSlime);
	OBJECTMANAGER->addObject(objectType::ENEMY, _smallSlime);
	OBJECTMANAGER->addObject(objectType::ENEMY, _weed);
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
