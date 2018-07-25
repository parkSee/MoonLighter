#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"

HRESULT effectManager::init(void)
{
	return S_OK;
}

void effectManager::release(void)
{
	miEffect iter = _mEffect.begin();
	for (iter; iter != _mEffect.end(); ++iter)
	{
		viEffect vIter = iter->second.begin();
		for (int i = 0; i < iter->second.size(); i++)
		{
			iter->second[i]->release();
			SAFE_DELETE(iter->second[i]);
		}
	}
	_mEffect.clear();
}

void effectManager::update(void)
{
	miEffect mIter;
	mIter = _mEffect.begin();
	for (mIter; mIter != _mEffect.end(); ++mIter)
	{
		for (int i = 0; i < mIter->second.size(); i++)
		{
			mIter->second[i]->update();
		}
	}
}

void effectManager::render(void)
{
	miEffect mIter;
	mIter = _mEffect.begin();
	for (mIter; mIter != _mEffect.end(); ++mIter)
	{
		for (int i = 0; i < mIter->second.size(); i++)
		{
			mIter->second[i]->render();
		}
	}
}

void effectManager::addEffect(string effectName, const char * imageName, float effectFPS, int buffer)
{
	image* img;
	vEffect vEffectBuffer;

	img = IMAGEMANAGER->findImage(imageName);
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effect);
		vEffectBuffer[i]->init(img, effectFPS);
	}

	//����Ʈ���� ���͸� �ʿ� ���
	_mEffect.insert(make_pair(effectName, vEffectBuffer));
}

void effectManager::play(string effectName, int x, int y)
{
	miEffect mIter;
	
	for (mIter = _mEffect.begin(); mIter != _mEffect.end(); ++mIter)
	{
		if (!(mIter->first == effectName)) break;

		//����ƮŰ�� ��ġ�ϸ� ����Ʈ ����
		for (int i = 0; i < mIter->second.size(); i++)
		{
			if (mIter->second[i]->getIsRunning()) continue;
			mIter->second[i]->startEffect(x, y);
			return;
		}
	}
}
