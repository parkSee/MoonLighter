#include "stdafx.h"
#include "objectManager.h"
#include "gameObject.h"



HRESULT objectManager::init()
{
	//���� ������Ʈ�� ��������� ���Ϳ� �־��ش�.
	for (int i = 0; i < END; ++i)
	{
		vector<gameObject*> v;
		totalList.insert(make_pair((objectType)i, v));
	}

	return S_OK;
}

void objectManager::release()
{
	//���� ������Ʈ ��ȯ�ϸ鼭 ����� �����ش�
	mIter miter;

	for (miter = totalList.begin(); miter != totalList.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); ++i)
		{
			miter->second[i]->release();
			SAFE_DELETE(miter->second[i]);

			miter->second.erase(miter->second.begin() + i);
		}
	}

}

void objectManager::update()
{
	mIter miter;

	//���� ��ȯ�� �ϸ鼭
	for (miter = totalList.begin(); miter != totalList.end(); ++miter)
	{
		//���� �ι�°�� ������ ������ ��ŭ ������ ����
		for (int i = 0; i < miter->second.size(); ++i)
		{
			//���� ������Ʈ�� ��������ʴٸ�
			if (miter->second[i]->isLive() == false)
			{
				miter->second[i]->release();
				SAFE_DELETE(miter->second[i]);
				miter->second.erase(miter->second.begin() + i);
				--i;
				continue;
			}
			if (miter->second[i]->isActiveObject() == true)
			{
				miter->second[i]->update();
			}
		}
	}

	/*if (KEYMANAGER->isOnceKeyDown('M'))
	{
		_isDebug = true;
	}*/

}

void objectManager::render(HDC getMemDC)
{
	//multmap
	//firstŰ�� �ߺ�����
	//�������� ������ �մϴ�.
	multimap<float, gameObject*> zOderList;

	mIter miter;

	for (miter = totalList.begin(); miter != totalList.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); ++i)
		{
			//objectManager�ȿ� �ִ� gameObject��� gameObject�� ������ �ִ� y���� ���� ��Ƽ�ʿ� ������������ ����
			zOderList.insert(make_pair(miter->second[i]->pos.y, miter->second[i]));
		}
	}
	
	//foreach
	// �迭�̳� enum���� ���� ���ӵ� ������ ���������� ���� �� �� �ְ� ��� �ϴ� �ݺ��� �����̴�.
	
	/*	for���� �پ��� ������� �迭�� ���� ������ �� ������ for~each���� ���������θ� ���� �� �� �ִ�.

		- ������ �ϳ� ����� �迭�� ���� �����һ� ���� �迭�� �����ϴ°��� �ƴϴ�.

		- for���� �ӵ��鿡�� ���� �̼��ϰ� �������� ���߿��� �Ű澵 ������ �ƴϴ�.

		for each (auto iter in zOrder) {

		}
		for (auto iter : zOderList)
		{
		iter.second->render();
		}

	*/
	

	for (pair<float, gameObject*> iter : zOderList)
	{
		
		iter.second->render();
	}


}

void objectManager::reset()
{

	mIter miter;

	for (miter = totalList.begin(); miter != totalList.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); ++i)
		{
			miter->second[i]->release();
			//SAFE_RELEASE(miter->second[i]);
			SAFE_DELETE(miter->second[i]);

			miter->second.erase(miter->second.begin() + i);
			--i;
		}
	}


}

gameObject * objectManager::findObject(objectType _type, string _name)
{
	vector<gameObject*> v = totalList[_type];

	for (int i = 0; i < totalList[_type].size(); ++i)
	{
		if (_name == v[i]->name)
		{
			return totalList[_type][i];
		}
	}
	return NULL;
}

vector<gameObject*> objectManager::findObjects(objectType _type, string _name)
{
	vector<gameObject*> giftList;

	for (int i = 0; i < totalList[_type].size(); ++i)
	{
		if (_name == totalList[_type][i]->name)
		{
			giftList.push_back(totalList[_type][i]);
		}
	}
	return giftList;
}

vector<gameObject*>* objectManager::getObjectList(objectType _type)
{
	return &totalList[_type];
}
