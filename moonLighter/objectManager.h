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

	//������Ʈ �Ŵ����� ������Ʈ�� �߰��Ѵ�.
	void addObject(objectType type, gameObject* obj)
	{
		//totalList[type].clear();
		totalList[type].push_back(obj);
	}

	//�ش� �̸��� ���� ������Ʈ �ϳ��� ã�Ƽ� ��ȯ�Ѵ�. ������ NULL�� ��ȯ
	gameObject* findObject(objectType _type, string _name);

	//�ش� �̸��� ���� ������Ʈ�� ��� ã�Ƽ� vector�� ��� ��ȯ�Ѵ�.
	vector<gameObject*> findObjects(objectType _type, string _name);

	//��ü ��� ������Ʈ�� ���Ϳ� ��Ƽ� ��ȯ ���ش�.
	vector<gameObject*>* getObjectList(objectType _type);


	objectManager() {}
	~objectManager() {}
};

