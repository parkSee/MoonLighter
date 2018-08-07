#pragma once

class item
{
public:
	image * _img;
	tagFloat _pos;
	itemType::Enum _itemKind;
	int _price;
	RECT _rc;
	bool _isActive;

public:

	HRESULT init(tagFloat pos,image* _im);
	void release();
	void update();
	void render(HDC hdc);

	bool getActive() { return _isActive; }
	void setActive(bool active) { _isActive = active; }

	item(){}
	~item(){}
};


