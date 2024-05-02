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

void Model::Compute_TB(Vertex& v0, Vertex& v1, Vertex& v2)
{
	vec3f tangent, binormal;

	vec3f D, E; 
	vec2f F, G;

	D = v1.Position - v0.Position;
	E = v2.Position - v0.Position;
	F = v1.TexCoord - v0.TexCoord;
	G = v2.TexCoord - v0.TexCoord;

	

	tangent.x = G.y * D.x + -F.y * E.x;
	tangent.y = G.y * D.y + -F.y * E.y;
	tangent.z = G.y * D.z + -F.y * E.z;

	binormal.x = -G.x * D.x + F.x * E.x;
	binormal.y = -G.x * D.y + F.x * E.y;
	binormal.z = -G.x * D.z + F.x * E.z;

	vec3f determinant = 1 / ((F.x * G.y) - (F.y * G.x));
	tangent *= determinant;
	binormal *= determinant;

	tangent.normalize();
	binormal.normalize();

	// Now assign the newly computed vectors to the vertices
	v0.Tangent = v1.Tangent = v2.Tangent = tangent;
	v0.Binormal = v1.Binormal = v2.Binormal = binormal;
}

//void Model::Compute_TB(Vertex& v0, Vertex& v1, Vertex& v2) {
//
//	vec3f tangent, binormal;
//
//	vec3f D = v1.Position - v0.Position;
//	vec3f E = v2.Position - v0.Position;
//	vec2f F = v1.TexCoord - v0.TexCoord;
//	vec2f G = v2.TexCoord - v0.TexCoord;
//
//	//linalg::mat2f FG = { F.x, F.y, G.x, G.y };
//	linalg::mat3f DE = { D.x, D.y, D.z, E.x, E.y, E.z, 0,0,0 };
//
//	float number = 1.0f / (F.x * G.y - F.y * G.x);
//
//	linalg::mat2f FG = { G.y * number, -F.y * number, -G.x * number, F.x * number };
//
//	tangent.x = FG.m11 * DE.m11 + FG.m12 * DE.m21;
//	tangent.y = FG.m11 * DE.m12 + FG.m12 * DE.m22;
//	tangent.z = FG.m11 * DE.m13 + FG.m12 * DE.m23;
//
//	binormal.x = FG.m21 * DE.m11 + FG.m22 * DE.m21;
//	binormal.y = FG.m21 * DE.m12 + FG.m22 * DE.m22;
//	binormal.z = FG.m21 * DE.m13 + FG.m22 * DE.m23;
//
//	// Gram-Schmidt orthogonalization
//	/*tangent = tangent - v0.Normal * dot(tangent, v0.Normal);
//	binormal = binormal - v0.Normal * dot(binormal, v0.Normal) - tangent * dot(binormal, tangent);*/
//	// TODO: compute the 'tangent' and 'binormal' vectors
//	//       using Lengyel’s method, as given in lecture
//
//	//binormal = CustomNormalize(binormal);
//	//tangent = CustomNormalize(tangent);
//
//	// Now assign the newly computed vectors to the vertices
//	v0.Tangent = v1.Tangent = v2.Tangent = tangent;
//	v0.Binormal = v1.Binormal = v2.Binormal = binormal;
//};
