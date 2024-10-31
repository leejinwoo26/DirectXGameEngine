#pragma once
#include "Graphics.h"


class Camera
{
public:
	DirectX::XMMATRIX GetMatrix() const noexcept;
	void SpawnControlWindow() noexcept;
	void Reset() noexcept;
private:
	float r = 20.f;
	float theta = 0.f;
	float phi = 0.f;
	float pitch = 0.f;
	float yaw = 0.f;
	float roll = 0.f;
};

