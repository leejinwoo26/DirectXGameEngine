#pragma once
#include "Bindable.h"
#include "GraphicsThrowMacros.h"
#include "Vertex.h"

namespace Bind
{
	class VertexBuffer : public Bindable
	{
	public:
		VertexBuffer(Graphics& gfx, const std::string& tag, const DXexp::VertexBuffer& vbuf);
		VertexBuffer(Graphics& gfx, const DXexp::VertexBuffer& vbuf);
		void Bind(Graphics& gfx) noexcept override;

		static std::shared_ptr<VertexBuffer> Resolve(Graphics& gfx, const std::string& tag,
			const DXexp::VertexBuffer& vbuf);
		template<typename...Ignore>
		static std::string GenerateUID(const std::string& tag, Ignore&&...ignore)
		{
			return GenerateUID_(tag);
		}
		std::string GetUID() const noexcept override;
	private:
		static std::string GenerateUID_(const std::string& tag);
	protected:
		std::string tag;
		UINT stride;
		Microsoft::WRL::ComPtr<ID3D11Buffer> pVertexBuffer;
	};
}
