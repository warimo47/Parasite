#pragma once

#include <atlimage.h>

class SceneManager
{
private:
	// ȭ�� ������
	int winWidth;
	int winHeight;

	// ��� Ÿ��
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

