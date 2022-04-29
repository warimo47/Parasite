#pragma once

#include <atlimage.h>

class SceneManager
{
private:
	// 화면 사이즈
	int winWidth;
	int winHeight;

	// Image resource
	CImage background;
	CImage gameStartButton;

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

