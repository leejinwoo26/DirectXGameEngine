#include "App.h"
#include <sstream>

App::App(): 
    wnd(800,500,L"DX3D_GameEngine")
{
}

int App::Go()
{
	while (true)
	{
		Sleep(1);
		if (const auto ecode = Window::ProcessMessage())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::wostringstream oss;
	oss << "Time Elapsed: " << std::setprecision(1) << std::fixed << t << std::endl;
	wnd.SetTitle(oss.str());
}
