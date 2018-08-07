#pragma once
#include "singletonBase.h"
/*FMOD ����ϱ� ����*/
#include "SOUND/inc/fmod.hpp"
#pragma comment (lib, "SOUND/lib/fmodex_vc.lib")
using namespace FMOD;
//=============================================================
//	## soundManager ## (���� �Ŵ���)
//=============================================================

//����� ������� (���尹���� 30���� �Ѿ�� ũ�⸦ �� �÷���� �Ѵ�)
#define SOUNDBUFFER 30

class soundManager : public singletonBase <soundManager>
{
private:
	typedef map<string, Sound**> arrSound;
	typedef map<string, Sound**>::iterator arrSoundIter;

private:
	System* _system;		//�ý��� Ŭ����
	Sound** _sound;			//���� Ŭ����
	Channel** _channel;		//ä�� Ŭ����

	arrSound _mTotalSound;	//�ʿ� ��Ƶ� �����
	string _currentBGM;

public:
	HRESULT init(void);
	void release(void);
	void update(void);

	//���� �߰�(Ű��, �����̸�, BGM?, ������ų����?)
	void addSound(string keyName, string soundName, bool bgm = false, bool loop = false);

	//���� ���
	void play(string keyName, float volume = 1.0f);//������ 0.0f ~ 1.0f
	//���� ����
	void stop(string keyName);
	//���� �Ͻ�����
	void pause(string keyName);
	//���� �ٽ����
	void resume(string keyName);

	//�÷��� ���̳�?
	bool isPlaySound(string keyName);
	//�Ͻ����� ���̳�?
	bool isPauseSound(string keyName);

	void setVolume(float vol)
	{
		int count = 0;
		arrSoundIter iter = _mTotalSound.begin();
		for (iter; iter != _mTotalSound.end(); ++iter, count++)
		{
			if (_currentBGM == iter->first)
			{
				////���� �÷���
				//_system->playSound(FMOD_CHANNEL_FREE, *iter->second, false, &_channel[count]);

				//��������
				_channel[count]->setVolume(vol);
			}
		}
	}

	void playBGM(string keyName, float vol)
	{
		if (_currentBGM != "" && isPlaySound(_currentBGM))
			stop(_currentBGM);

		_currentBGM = keyName;

		play(keyName, vol);

	}

	soundManager() : _system(NULL), _sound(NULL), _channel(NULL) {}
	~soundManager() {}
};

