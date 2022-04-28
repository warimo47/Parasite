#pragma once

#include <atlimage.h>

class SceneManager
{
private:
	// 화면 사이즈
	int winWidth;
	int winHeight;

	// 배경 타일
	CImage map;

protected:

public:
	
private:

protected:

public:
	SceneManager();
	~SceneManager();

	void Render(HWND hWnd);

	void ImageAlphaSetting(CImage*);
};

