#include "DXWin.h"
#include "Window.h"
#include "WindowsMessageMap.h"
#include <sstream>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'D')
		{
			SetWindowTextW(hWnd, L"respect");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowTextW(hWnd, L"Hell");
		}
		break;
	case WM_CHAR:
		{
		static std::wstring title;
		title.push_back((char)wParam);
		SetWindowText(hWnd, title.c_str());
		}
		break;
	case WM_LBUTTONDOWN:
		{
		const POINTS pt = MAKEPOINTS(lParam);
		std::wostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Window wnd(800,300,L"DX3D_GameEngine");

	MSG msg;
	BOOL gResult;

	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	if (gResult == -1) {
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}