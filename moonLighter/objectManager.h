#pragma once
#include "singletonBase.h"
#include <unordered_map>

class gameObject;

enum objectType
{
	PLAYER, ENEMY, ITEM, OBJECT, END
};


class objectManager : public singletonBase<objectManager>
{
private:

	unordered_map<objectType, vector<gameObject*>> totalList;
	typedef unordered_map<objectType, vector<gameObject*>>::iterator mIter;

public:

	HRESULT init();
	void release();
	void update();
	void render(HDC getMemDC);
	void reset();

	//오브젝트 매니저에 오브젝트를 추가한다.
	void addObject(objectType type, gameObject* obj)
	{
		//totalList[type].clear();
		totalList[type].push_back(obj);
	}

	//해당 이름을 가진 오브젝트 하나를 찾아서 반환한다. 없으면 NULL을 반환
	gameObject* findObject(objectType _type, string _name);

	//해당 이름을 가진 오브젝트를 모드 찾아서 vector에 담아 반환한다.
	vector<gameObject*> findObjects(objectType _type, string _name);

	//전체 모든 오브젝트를 벡터에 담아서 반환 해준다.
	vector<gameObject*>* getObjectList(objectType _type);


	objectManager() {}
	~objectManager() {}
};

