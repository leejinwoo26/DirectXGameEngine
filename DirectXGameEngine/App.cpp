#include "App.h"
#include <sstream>

App::App(): 
    wnd(800,600,L"DX3D_GameEngine")
{
}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessage())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.f);
	wnd.Gfx().DrawTestTriangle();
	wnd.Gfx().EndFrame();
}
