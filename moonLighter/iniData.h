#pragma once
#include "singletonBase.h"
//=============================================================
//	## iniData ## (INI 데이터)
//=============================================================

//ini데이터 구조체
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

	//데이터 추가하기(섹션, 키, 밸류)
	void addData(const char* section, const char* key, const char* value);
	//세이브(파일이름)
	void saveINI(const char* fileName);

	//문자로 값을 로드하기(파일이름, 섹션, 키)
	char* loadDataString(const char* fileName, const char* section, const char* key);
	//정수로 값을 로드하기(파일이름, 섹션, 키)
	int loadDataInteger(const char* fileName, const char* section, const char* key);
	//실수로 값을 로드하기(파일이름, 섹션, 키)
	float loadDataFloat(const char* fileName, const char* section, const char* key);

	iniData() {}
	~iniData() {}
};

