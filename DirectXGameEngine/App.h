#pragma once
#include "Window.h"
#include "DXTimer.h"


class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	DXTimer timer;
};

