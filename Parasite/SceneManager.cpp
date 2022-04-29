#include "SceneManager.h"

SceneManager::SceneManager()
{
    winWidth = GetSystemMetrics(SM_CXSCREEN);
    winHeight = GetSystemMetrics(SM_CYSCREEN);

	background.Load(L"Resource/Background.png");
	gameStartButton.Load(L"Resource/GameStartButton.png");

	ImageAlphaSetting(&gameStartButton);
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

	int gsbAnim = 0;

	RECT rect;
	rect.left = 120;
	rect.top = 640;
	rect.right = rect.left + gameStartButton.GetWidth();
	rect.bottom = rect.top + gameStartButton.GetHeight();
	POINT point;
	point.x = 120;
	point.y = 640;

	background.BitBlt(hViewdc, 0, 0);
	// gameStartButton.TransparentBlt(hViewdc, 120, 640, gameStartButton.GetWidth(), gameStartButton.GetHeight() / 3, 0, gsbAnim, gameStartButton.GetWidth(), gameStartButton.GetHeight() / 3, RGB(255, 0, 255));
	gameStartButton.AlphaBlend(hViewdc, point, 255U);

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