#pragma once

#include <atlimage.h>

class SceneManager
{
private:
	// ȭ�� ������
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

