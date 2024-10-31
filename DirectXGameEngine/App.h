#pragma once
#include "Window.h"
#include "DXTimer.h"
#include "Box.h"
#include "ImguiManager.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	ImguiManager imgui;
	Window wnd;
	DXTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	float speed_factor = 1.f;
	static constexpr size_t nDrawables = 180;
};

