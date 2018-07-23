#include "stdafx.h"
#include "gameObject.h"

//게임오브젝트를 쓰는 이유는 
//1. 코드의 줄을 줄일수 있다.(안썼을때와 썼을때의 차이점은 월요일날 보여드리겠습니다)
//2. 상속, 다형성 
// 객체지향을 공부합시다 ㅋㅋㅋ

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

	if (!_isLive)				//오브젝트가 죽어있다면 무조건 false
	{
		return false;
	}
	if (!_isActive)				//활성화가 꺼져있으면 false
	{
		return false;
	}

	return true;
}

