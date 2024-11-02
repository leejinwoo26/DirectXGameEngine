#include "PointLight.h"
#include "imgui/imgui.h"
PointLight::PointLight(Graphics& gfx, float radius):
	mesh(gfx,radius),
	cBuf(gfx)
{
}

void PointLight::SpawnControlWindow() noexcept
{
	if (ImGui::Begin("Light"))
	{
		ImGui::Text("Position");
		ImGui::SliderFloat("X", &pos.x, -60.f, 60.f, "%.1f");
		ImGui::SliderFloat("Y", &pos.y, -60.f, 60.f, "%.1f");
		ImGui::SliderFloat("Z", &pos.z, -60.f, 60.f, "%.1f");
		if (ImGui::Button("Reset"))
		{
			Reset();
		}
	}
	ImGui::End();
}

void PointLight::Reset() noexcept
{
	pos = {0.f,0.f ,0.f};
}

void PointLight::Draw(Graphics& gfx) const noexcept
{
	mesh.SetPos(pos);
	mesh.Draw(gfx);
}

void PointLight::Bind(Graphics& gfx) const noexcept
{
	cBuf.Update(gfx, PointLightCBuf{ pos });
	cBuf.Bind(gfx);
}
