#include "Model.h"

Model::Model(ID3D11Device* dxdevice, ID3D11DeviceContext* dxdevice_context)
	: m_dxdevice(dxdevice), m_dxdevice_context(dxdevice_context) {
	
	HRESULT hr;
	D3D11_BUFFER_DESC matrixBufferDesc = { 0 };
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MaterialBuffer);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;
	ASSERT(hr = m_dxdevice->CreateBuffer(&matrixBufferDesc, nullptr, &m_material_buffer));

	sd =
	{
		D3D11_FILTER_ANISOTROPIC,
		D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_WRAP,
		D3D11_TEXTURE_ADDRESS_WRAP,
		0.0f,
		16,
		D3D11_COMPARISON_NEVER,
		{ 1.0f, 1.0f, 1.0f },
		-FLT_MAX,
		FLT_MAX,
	};
	ASSERT(hr = m_dxdevice->CreateSamplerState(&sd, &samplerState));
}