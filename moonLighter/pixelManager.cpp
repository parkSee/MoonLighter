#include "stdafx.h"
#include "pixelManager.h"

bool pixelManager::collision(image* playerImg,image* _img, Direction::Enum dir, float& x, float& y)
{
	//RECT _rc = playerImg->boudingBoxWithFrame();

	switch (dir)
	{
		case Direction::LEFT:
		{
			for (int i = x + 35; i >= x - 35; --i)
			{
				COLORREF color = GetPixel(_img->getMemDC(), i, y);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					x = i + 35;
					return true;
				}
			}
		}
			break;
		case Direction::TOP:
		{
			for (int i = y + 35; i >= y - 35; i--)
			{
				COLORREF color = GetPixel(_img->getMemDC(), x, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					y = i + 35;
					return true;
				}
			}

		}
			break;
		case Direction::RIGHT:
		{
			
			for (int i = x - 35; i <= x + 5; ++i)
			{
				COLORREF color = GetPixel(_img->getMemDC(), i, y);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					x = i - 35;
					return true;
				}
			}
		}
			break;
		case Direction::BOTTOM:
		{
			//_probeY = probeY;

			for (int i = y - 10; i < y + 10; ++i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("redZone")->getMemDC(), x, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					y = i - 35;
					return true;
				}
			}
		}
			break;

	}
	

}

HRESULT pixelManager::init()
{
	return S_OK;
}

void pixelManager::release()
{
}
