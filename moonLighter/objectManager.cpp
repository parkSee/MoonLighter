#include "stdafx.h"
#include "objectManager.h"
#include "gameObject.h"



HRESULT objectManager::init()
{
	//게임 오브젝트가 만들어질때 벡터에 넣어준다.
	for (int i = 0; i < END; ++i)
	{
		vector<gameObject*> v;
		totalList.insert(make_pair((objectType)i, v));
	}

	return S_OK;
}

void objectManager::release()
{
	//게임 오브젝트 순환하면서 대상을 지워준다
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

	//맵을 순환을 하면서
	for (miter = totalList.begin(); miter != totalList.end(); ++miter)
	{
		//맵의 두번째값 벡터의 사이즈 만큼 포문을 돈다
		for (int i = 0; i < miter->second.size(); ++i)
		{
			//만약 오브젝트가 살아있지않다면
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
	//first키값 중복가능
	//오름차순 정렬을 합니다.
	multimap<float, gameObject*> zOderList;

	mIter miter;

	for (miter = totalList.begin(); miter != totalList.end(); ++miter)
	{
		for (int i = 0; i < miter->second.size(); ++i)
		{
			//objectManager안에 있는 gameObject들과 gameObject가 가지고 있는 y축의 값을 멀티맵에 오름차순으로 삽입
			zOderList.insert(make_pair(miter->second[i]->pos.y, miter->second[i]));
		}
	}
	
	//foreach
	// 배열이나 enum문과 같이 연속된 값들을 순차적으로 접근 할 수 있게 사용 하는 반복문 문법이다.
	
	/*	for문은 다양한 방법으로 배열의 값을 접근할 수 있지만 for~each문은 순차적으로만 접근 할 수 있다.

		- 변수를 하나 만들어 배열의 값을 참조할뿐 직접 배열에 접근하는것은 아니다.

		- for문이 속도면에서 아주 미세하게 빠르지만 개발에서 신경쓸 정도는 아니다.

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
