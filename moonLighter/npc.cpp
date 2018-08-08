#include "stdafx.h"
#include "npc.h"
#include "player.h"

HRESULT npc::init(tagFloat pos, image* img)
{
	_talkImg = IMAGEMANAGER->findImage("talking");
	_talkBox = IMAGEMANAGER->findImage("talkBox");
	_pos = pos;
	_img = img;
	_rc = RectMakeCenter(_pos.x, _pos.y, _img->getFrameWidth(), _img->getFrameHeight());
	

	_timer = 0;
	_count = _index = 0;
	_count2 = _index2 = 0;
	_isFrame = false;
	_isCollision = false;
	_istalk = false;


	_txtCount = _txtIndex = 0;
	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	

	//�ð��Ǹ� ������ ������
	_timer++;
	if (_timer % 200 == 0)
	{
		_isFrame = true;
	}
	if (_isFrame)
		this->frame();

	


}

void npc::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_img->frameRender(getMemDC(), _pos.x - cam.left, _pos.y - cam.top);
	
	
	RectangleCam(getMemDC(), _talkRc,cam);
	
	if (_isCollision)
	{
		//_talkImg->frameRender(getMemDC(), 427 - cam.left, 1880 - cam.top);
		_talkImg->frameRender(getMemDC(), _taklUiPos.x - cam.left, _taklUiPos.y - cam.top);
	}
	if (_istalk)
	{
		
		_talkBox->render(getMemDC(), _talkBoxUiPos.x - cam.left, _talkBoxUiPos.y - cam.top);
	}

}

void npc::frame()
{
	_count++;

	if (_count % 10 == 0)
	{
		_index++;

		_img->setFrameX(0);
		if (_index > _img->getMaxFrameX())
		{
			_index = 0;
			_isFrame = false;
		}

		_img->setFrameX(_index);
	}


}

void npc::talkingFrame()
{

	_count2++;

	if (_count2 % 10 == 0)
	{
		_index2++;

		//_talkImg->setFrameX(0);
		if (_index2 > _talkImg->getMaxFrameX())
		{
			_index2 = _talkImg->getMaxFrameX();
			
		}
		_talkImg->setFrameX(_index2);

	}


}

void npc::talkingRECT(RECT rc, tagFloat talkUi, tagFloat talkBoxUi)
{
	//_talkRc = RectMakeCenter(356, 1983)
	RECT temp;
	player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	_talkRc = rc;
	_taklUiPos = talkUi;
	_talkBoxUiPos = talkBoxUi;
	if (IntersectRect(&temp, &_player->rc, &_talkRc))
	{
		_isCollision = true;
		
		if (_istalk == false)
		{
			if (KEYMANAGER->isOnceKeyDown('J'))
			{
				//��ȭâ�� ���´�
				_istalk = true;
			}
		}
	}
	else
	{
		_isCollision = false;
		_index2 = 0;
	}

	if (_isCollision)
		this->talkingFrame();
	
}

void npc::talkingRender(const char *a)
{
	/*
	font = CreateFont(
	���� ũ��, ���� ��, ���� ����, ���� ����, ���� ����,
	����(bool), ����(bool), ��Ҽ�(bool),
	���� ����, ��� ��Ȯ��, Ŭ���� ��Ȯ��, ����� ��, �ڰ�, ��Ʈ
	)
	*/
	// ���� ���� ����ũ�⿡ ���� ����ϰ� ǥ��. 0���� �δ� ���� ����

	/* ��Ʈ ����
	RECT rcTextArea = { 200,200,300,300 };
	RECT �� ���� ���� ����.

	DrawText(hdc,szTemp, strlen(szTemp) ,&rcTextArea, DT_SINGLELINE  |  DT_VCENTER );
	(�ڵ�, ���ڿ� , ���ڿ��� ����  , ���� ũ��    , ��ο� �ؽ�Ʈ _ ��� ��Ÿ�� )  ;
	�ش� �����ȿ� ���ڸ� ��Ÿ�Ͽ� ���� ������ش�.  or (  |  ) �������� �ߺ��� ��Ÿ���� �����ִ�.

	���־��� ��Ÿ��

	DT_LEFT			���� ����
	DT_CENTER		�߾� ����
	DT_WORDBREAK	���� �Ѿ�� �ܾ� ������ �ٹٲ�
	DT_SINGLELINE	���� ���
	DT_NOCLIP		���� ���� ���
	DT_VCENTER		���� ���߾ӿ� �����(�ݵ�� DT_SINGLELINE�̶� ���� ����Ѵ�)
	*/
	//strcpy(text , a);
	RECT cam = CAMERAMANAGER->getRenderRc();

	strcpy_s(text, a);


	_txtCount = (_txtCount + 1) % 10;
	if (_txtCount == 0)
	{
		_txtIndex += 2;
		if (_txtIndex > 50)
		{
			_txtIndex = 50;
			//if (_istalk == true)
			//{
				if (KEYMANAGER->isOnceKeyDown('J'))
				{
					_istalk = false;
					_txtIndex = 0;
				}
			//}
		}
	}
	SetTextColor(getMemDC(), RGB(156, 143, 120));
	HFONT font;
	HFONT oldFont;
	font = CreateFont(20, 0, 0, 0, 600, false, false, false, HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("DX������ü��B"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);
	char str[256];

	strncpy_s(str, text, _txtIndex);
	RECT textrc = RectMake(_talkBoxUiPos.x + 200, _talkBoxUiPos.y + 75 - cam.top,300,600);
	
	DrawText(getMemDC(), str, strlen(str), &textrc, DT_WORDBREAK);
	//TextOut(getMemDC(), (_talkBoxUiPos.x + 200 - cam.left), (_talkBoxUiPos.y + 75 - cam.top), str, strlen(str));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);



}
