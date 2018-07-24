#pragma once
#include "singletonBase.h"
//=============================================================
//	## iniData ## (INI ������)
//=============================================================

//ini������ ����ü
struct tagIniData
{
	char* section;
	char* key;
	char* value;
};

class iniData : public singletonBase <iniData>
{
private:
	vector<tagIniData> _vIniData;

public:
	HRESULT init(void);
	void release(void);

	//������ �߰��ϱ�(����, Ű, ���)
	void addData(const char* section, const char* key, const char* value);
	//���̺�(�����̸�)
	void saveINI(const char* fileName);

	//���ڷ� ���� �ε��ϱ�(�����̸�, ����, Ű)
	char* loadDataString(const char* fileName, const char* section, const char* key);
	//������ ���� �ε��ϱ�(�����̸�, ����, Ű)
	int loadDataInteger(const char* fileName, const char* section, const char* key);
	//�Ǽ��� ���� �ε��ϱ�(�����̸�, ����, Ű)
	float loadDataFloat(const char* fileName, const char* section, const char* key);

	iniData() {}
	~iniData() {}
};

