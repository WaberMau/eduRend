#include "Cube.h"
#include "drawcall.h"
#include "buffers.h"

Cube::Cube(
	ID3D11Device* dxdevice,
	ID3D11DeviceContext* dxdevice_context)
	: Model(dxdevice, dxdevice_context)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned> indices;

	//Face 1 Front
	Vertex v0, v1, v2, v3, v4;
	v0.Position = { -0.5, -0.5f, 0.0f };
	v0.Normal = { 0, 0, 1 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { 0.5, -0.5f, 0.0f };
	v1.Normal = { 0, 0, 1 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, 0.5f, 0.0f };
	v2.Normal = { 0, 0, 1 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { -0.5, 0.5f, 0.0f };
	v3.Normal = { 0, 0, 1 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	// Triangle #2
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	//Face 2 Left Side
	v0.Position = { -0.5, -0.5f, -1.0f };
	v0.Normal = { -1, 0, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { -0.5, -0.5f, 0.0f };
	v1.Normal = { -1, 0, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { -0.5, 0.5f, 0.0f };
	v2.Normal = { -1, 0, 0 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { -0.5, 0.5f, -1.0f };
	v3.Normal = { -1, 0, 0 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(7);
	// Triangle #2
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);

	//Face 3 Back
	v0.Position = { 0.5, -0.5f, -1.0f };
	v0.Normal = { 0, 0, -1 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { -0.5, -0.5f, -1.0f };
	v1.Normal = { 0, 0, -1 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { -0.5, 0.5f, -1.0f };
	v2.Normal = { 0, 0, -1 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { 0.5, 0.5f, -1.0f };
	v3.Normal = { 0, 0, -1 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(8);
	indices.push_back(9);
	indices.push_back(11);
	// Triangle #2
	indices.push_back(9);
	indices.push_back(10);
	indices.push_back(11);

	//Face 4 Right Side
	v0.Position = { 0.5, -0.5f, 0.0f };
	v0.Normal = { 1, 0, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { 0.5, -0.5f, -1.0f };
	v1.Normal = { 1, 0, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, 0.5f, -1.0f };
	v2.Normal = { 1, 0, 0 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { 0.5, 0.5f, 0.0f };
	v3.Normal = { 1, 0, 0 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(12);
	indices.push_back(13);
	indices.push_back(15);
	// Triangle #2
	indices.push_back(13);
	indices.push_back(14);
	indices.push_back(15);

	//Face 5 Top
	v0.Position = { -0.5, 0.5f, 0.0f };
	v0.Normal = { 0, 1, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { 0.5, 0.5f, 0.0f };
	v1.Normal = { 0, 1, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, 0.5f, -1.0f };
	v2.Normal = { 0, 1, 0 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { -0.5, 0.5f, -1.0f };
	v3.Normal = { 0, 1, 0 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(16);
	indices.push_back(17);
	indices.push_back(19);
	// Triangle #2
	indices.push_back(17);
	indices.push_back(18);
	indices.push_back(19);

	//Face 6 Bottom
	v0.Position = { -0.5, -0.5f, -1.0f };
	v0.Normal = { 0, -1, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { 0.5, -0.5f, -1.0f };
	v1.Normal = { 0, -1, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, -0.5f, 0.0f };
	v2.Normal = { 0, -1, 0 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { -0.5, -0.5f, 0.0f };
	v3.Normal = { 0, -1, 0 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(20);
	indices.push_back(21);
	indices.push_back(23);
	// Triangle #2
	indices.push_back(21);
	indices.push_back(22);
	indices.push_back(23);

	//Compute tangents and binormals
	for (int i = 0; i < indices.size(); i += 3) // For all triangles
		Compute_TB(
			vertices[indices[i + 0]],
			vertices[indices[i + 1]],
			vertices[indices[i + 2]]);


	D3D11_BUFFER_DESC vertexbufferDesc{ 0 };
	vertexbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexbufferDesc.CPUAccessFlags = 0;
	vertexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexbufferDesc.MiscFlags = 0;
	vertexbufferDesc.ByteWidth = (UINT)(vertices.size() * sizeof(Vertex));

	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = &vertices[0];

	dxdevice->CreateBuffer(&vertexbufferDesc, &vertexData, &m_vertex_buffer);
	SETNAME(m_vertex_buffer, "VertexBuffer");


	D3D11_BUFFER_DESC indexbufferDesc = { 0 };
	indexbufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexbufferDesc.CPUAccessFlags = 0;
	indexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexbufferDesc.MiscFlags = 0;
	indexbufferDesc.ByteWidth = (UINT)(indices.size() * sizeof(unsigned));

	D3D11_SUBRESOURCE_DATA indexData{ 0 };
	indexData.pSysMem = &indices[0];

	dxdevice->CreateBuffer(&indexbufferDesc, &indexData, &m_index_buffer);
	SETNAME(m_index_buffer, "IndexBuffer");

	m_number_of_indices = (unsigned int)indices.size();

	HRESULT hr;

	default_material.AmbientColour = vec3f(0.1f, 0.1f, 0.1f);
	default_material.DiffuseTextureFilename = "assets/textures/stone.png";

	if (default_material.DiffuseTextureFilename.size()) {
		hr = LoadTextureFromFile(dxdevice, dxdevice_context, default_material.DiffuseTextureFilename.c_str(), &default_material.DiffuseTexture);

		std::cout << "\t" << default_material.DiffuseTextureFilename << (SUCCEEDED(hr) ? " - OK" : "- FAILED") << std::endl;
	}

	default_material.NormalTextureFilename = "assets/textures/stoneNormal.png";

	if (default_material.NormalTextureFilename.size()) {
		hr = LoadTextureFromFile(dxdevice, dxdevice_context, default_material.NormalTextureFilename.c_str(), &default_material.NormalTexture);

		std::cout << "\t" << default_material.NormalTextureFilename << (SUCCEEDED(hr) ? " - OK" : "- FAILED") << std::endl;
	}
		
}


void Cube::Render() const
{

	const UINT32 stride = sizeof(Vertex); 
	const UINT32 offset = 0;
	m_dxdevice_context->IASetVertexBuffers(0, 1, &m_vertex_buffer, &stride, &offset);
	m_dxdevice_context->IASetIndexBuffer(m_index_buffer, DXGI_FORMAT_R32_UINT, 0);

	m_dxdevice_context->PSSetConstantBuffers(1, 1, &m_material_buffer);
	m_dxdevice_context->PSSetShaderResources(0, 1, &default_material.DiffuseTexture.TextureView);
	m_dxdevice_context->PSSetShaderResources(1, 1, &default_material.NormalTexture.TextureView);

	m_dxdevice_context->DrawIndexed(m_number_of_indices, 0, 0);

	D3D11_MAPPED_SUBRESOURCE resource;
	m_dxdevice_context->Map(m_material_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	MaterialBuffer* materialbuffer = (MaterialBuffer*)resource.pData;
	materialbuffer->Ambient = default_material.AmbientColour;
	materialbuffer->Diffuse = default_material.DiffuseColour;
	materialbuffer->Specular = default_material.SpecularColour;
	m_dxdevice_context->Unmap(m_material_buffer, 0);
}