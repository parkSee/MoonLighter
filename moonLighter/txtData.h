#pragma once
#include "singletonBase.h"

class txtData : public singletonBase <txtData>
{
public:
	HRESULT init(void);
	void release(void);

	//세이브
	void txtSave(const char* fileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);
	//1,2,100
	
	//로드
	vector<string> txtLoad(const char* fileName);
	vector<string> charArraySeparation(char charArray[]);


	txtData() {}
	~txtData() {}
};

