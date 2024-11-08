#pragma once
#include "Window.h"
#include "DXTimer.h"
#include "Box.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include <set>
#include "Model.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
	void ShowModelWindow();
private:
	ImguiManager imgui;
	Window wnd;
	Camera cam;
	DXTimer timer;
	Model nano{ wnd.Gfx(),"Models\\nanosuit.obj" };
	float speed_factor = 1.f;
	PointLight light;
	struct
	{
		float roll = 0.0f;
		float pitch = 0.0f;
		float yaw = 0.0f;
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	} pos;
};

