#include "stdafx.h"
#include "enemyController.h"

//���ʹ� ��Ʈ�ѷ����� ���ִ°� ��� �����Ұ�������
//������Ʈ �Ŵ����� �־��ִ°� 

//�Ѹ���� ���ʹ� ��ü�� �������� ���� �ϴ� ���ְ����� �����Դϴ�.

//����� ������Ʈ �Ŵ����� ���ΰ��ӿ��� �̹� ������Ʈ�� �����ְ� ����


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
