#pragma once
#include "singletonBase.h"

namespace Direction
{
	enum Enum
	{
		LEFT,TOP,RIGHT,BOTTOM,END
	};
}

class pixelManager : public singletonBase<pixelManager>
{
private:
	int _probeX;
	int _probeY;

	Direction::Enum dir;

public:


	bool collision( image* playerImg,image* _img, Direction::Enum dir,float& x,float& y);

	HRESULT init();
	void release();

	pixelManager(){}
	~pixelManager(){}
};

