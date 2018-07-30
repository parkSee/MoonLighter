#include "stdafx.h"
#include "gameNode.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT gameNode::init(void)
{
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);		//Ÿ�̸� �ʱ�ȭ
		KEYMANAGER->init();					//Ű�Ŵ��� �ʱ�ȭ
		RND->init();						//������� �ʱ�ȭ
		IMAGEMANAGER->init();				//�̹����Ŵ��� �ʱ�ȭ
		CAMERAMANAGER->init();				//ī�޶� �Ŵ��� �ʱ�ȭ
		SCENEMANAGER->init();
		SOUNDMANAGER->init();
		TXTDATA->init();
		INIDATA->init();
		OBJECTMANAGER->init();
		EFFECTMANAGER->init();
		TIMEMANAGER->init();
	}

	return S_OK;
}

//=============================================================
//	## ���� ## release(void)
//=============================================================
void gameNode::release(void)
{
	if (_managerInit)
	{
		//Ÿ�̸� ����
		KillTimer(_hWnd, 1);
		//Ű�Ŵ��� �̱��� ����
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();
		//������� �̱��� ����
		RND->release();
		RND->releaseSingleton();
		//�̹����Ŵ��� �̱��� ����
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		CAMERAMANAGER->release();
		CAMERAMANAGER->releaseSingleton();
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
		TXTDATA->release();
		TXTDATA->releaseSingleton();
		INIDATA->release();
		INIDATA->releaseSingleton();
		OBJECTMANAGER->release();
		OBJECTMANAGER->releaseSingleton();
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
	}

	//DC ����
	ReleaseDC(_hWnd, _hdc);
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void gameNode::update(void)
{
	//���ΰ�ħ (���߿� ���� Ÿ�̸Ӹ� ���� �Ŀ��� ������� �ʴ´�)
	//������۸� ���� ������� �ʴ´�(true => false)
	//InvalidateRect(_hWnd, NULL, FALSE);
}

//=============================================================
//	## ���� ## render(void)
//=============================================================
void gameNode::render(void)
{
}

//=============================================================
//	## �������ν��� ##
//=============================================================
LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;				
	PAINTSTRUCT ps;			

	switch (iMessage)
	{
	//case WM_TIMER:
	//	//this->update();
	//	break;
	//case WM_PAINT:			
	//	hdc = BeginPaint(hWnd, &ps);
	//	this->render();
	//	EndPaint(hWnd, &ps);
	//	break;
	case WM_MOUSEMOVE:		
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:		
		switch (wParam)
		{
		case VK_ESCAPE:		
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:		
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
