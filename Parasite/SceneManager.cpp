#include "SceneManager.h"

SceneManager::SceneManager()
{
    winWidth = GetSystemMetrics(SM_CXSCREEN);
    winHeight = GetSystemMetrics(SM_CYSCREEN);

	// map.Load(L"map.png");

	// ImageAlphaSetting(&map);
}

SceneManager::~SceneManager() {}

void SceneManager::Render(HWND hWnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);

    // Double buffering
    HBITMAP hViewBit = CreateCompatibleBitmap(hdc, winWidth, winHeight);
    HDC hViewdc = CreateCompatibleDC(hdc);
    SelectObject(hViewdc, hViewBit);
    Rectangle(hViewdc, 0, 0, winWidth, winHeight);



    // Double buffering
    BitBlt(hdc, 0, 0, winWidth, winHeight, hViewdc, 0, 0, SRCCOPY);
    DeleteDC(hViewdc);
    DeleteObject(hViewBit);

    EndPaint(hWnd, &ps);
}

void SceneManager::ImageAlphaSetting(CImage* Img)
{
	unsigned char* pCol = 0;

	long w = Img->GetWidth();
	long h = Img->GetHeight();

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			pCol = (unsigned char*)
				Img->GetPixelAddress(x, y);

			unsigned char alpha = pCol[3];

			if (alpha != 255)
			{
				pCol[0] = (pCol[0] * alpha + 128) >> 8;
				pCol[1] = (pCol[1] * alpha + 128) >> 8;
				pCol[2] = (pCol[2] * alpha + 128) >> 8;
			}
		}
	}
}