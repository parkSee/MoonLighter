#include "stdafx.h"
#include "gameObject.h"

//���ӿ�����Ʈ�� ���� ������ 
//1. �ڵ��� ���� ���ϼ� �ִ�.(�Ƚ������� �������� �������� �����ϳ� �����帮�ڽ��ϴ�)
//2. ���, ������ 
// ��ü������ �����սô� ������

HRESULT gameObject::init(string _objName, tagFloat _pos)
{
	name = _objName;

	pos = _pos;

	_isLive = true;
	_isActive = true;

	return S_OK;
}

void gameObject::release()
{
}

void gameObject::update()
{

}

void gameObject::render()
{
}
bool gameObject::isActiveObject()
{

	if (!_isLive)				//������Ʈ�� �׾��ִٸ� ������ false
	{
		return false;
	}
	if (!_isActive)				//Ȱ��ȭ�� ���������� false
	{
		return false;
	}

	return true;
}

