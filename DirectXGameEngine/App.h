#pragma once
#include "Window.h"
#include "DXTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include <set>
#include "Mesh.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
	void ShowImguiDemoWindow();
private:
	bool showDemoWindow = false;
	ImguiManager imgui;
	Window wnd;
	Camera cam;
	DXTimer timer;
	Model nano{ wnd.Gfx(),"Models\\nano_hierarchy.gltf" };
	float speed_factor = 1.f;
	PointLight light;
};

