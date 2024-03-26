#include "Cube.h"
#include "drawcall.h"
#include "buffers.h"

Cube::Cube(
	ID3D11Device* dxdevice,
	ID3D11DeviceContext* dxdevice_context)
	: Model(dxdevice, dxdevice_context)
{
	// Vertex and index arrays
	// Once their data is loaded to GPU buffers, they are not needed anymore
	std::vector<Vertex> vertices;
	std::vector<unsigned> indices;

	Vertex v;
	
	default_material.AmbientColour = vec3f(0.1f, 0.0f, 0.1f);

	//Face 1
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

	//Face 2
	v0.Position = { -0.5, -0.5f, 0.0f };
	v0.Normal = { -1, 0, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { -0.5, 0.5f, 0.0f };
	v1.Normal = { -1, 0, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { -0.5, -0.5f, -1.0f };
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
	indices.push_back(7);
	indices.push_back(6);
	indices.push_back(4);

	//Face 3
	v0.Position = { -0.5, -0.5f, -1.0f };
	v0.Normal = { 0, 0, -1 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { -0.5, 0.5f, -1.0f };
	v1.Normal = { 0, 0, -1 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, -0.5f, -1.0f };
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
	indices.push_back(11);
	indices.push_back(10);
	indices.push_back(8);

	//Face 4
	v0.Position = { 0.5, -0.5f, 0.0f };
	v0.Normal = { 1, 0, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { 0.5, 0.5f, 0.0f };
	v1.Normal = { 1, 0, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, -0.5f, -1.0f };
	v2.Normal = { 1, 0, 0 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { 0.5, 0.5f, -1.0f };
	v3.Normal = { 1, 0, 0 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(15);
	indices.push_back(13);
	indices.push_back(12);
	// Triangle #2
	indices.push_back(12);
	indices.push_back(14);
	indices.push_back(15);

	//Face 5
	v0.Position = { 0.5, 0.5f, 0.0f };
	v0.Normal = { 0, 1, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { -0.5, 0.5f, 0.0f };
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
	indices.push_back(19);
	indices.push_back(17);
	indices.push_back(16);
	// Triangle #2
	indices.push_back(16);
	indices.push_back(18);
	indices.push_back(19);

	//Face 6
	v0.Position = { 0.5, -0.5f, 0.0f };
	v0.Normal = { 0, -1, 0 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { -0.5, -0.5f, 0.0f };
	v1.Normal = { 0, -1, 0 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5, -0.5f, -1.0f };
	v2.Normal = { 0, -1, 0 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { -0.5, -0.5f, -1.0f };
	v3.Normal = { 0, -1, 0 };
	v3.TexCoord = { 1, 0 };
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(23);
	indices.push_back(22);
	indices.push_back(21);
	// Triangle #2
	indices.push_back(20);
	indices.push_back(21);
	indices.push_back(22);


	// Vertex array descriptor
	D3D11_BUFFER_DESC vertexbufferDesc{ 0 };
	vertexbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexbufferDesc.CPUAccessFlags = 0;
	vertexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexbufferDesc.MiscFlags = 0;
	vertexbufferDesc.ByteWidth = (UINT)(vertices.size() * sizeof(Vertex));
	// Data resource
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = &vertices[0];
	// Create vertex buffer on device using descriptor & data
	dxdevice->CreateBuffer(&vertexbufferDesc, &vertexData, &m_vertex_buffer);
	SETNAME(m_vertex_buffer, "VertexBuffer");

	//  Index array descriptor
	D3D11_BUFFER_DESC indexbufferDesc = { 0 };
	indexbufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexbufferDesc.CPUAccessFlags = 0;
	indexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexbufferDesc.MiscFlags = 0;
	indexbufferDesc.ByteWidth = (UINT)(indices.size() * sizeof(unsigned));
	// Data resource
	D3D11_SUBRESOURCE_DATA indexData{ 0 };
	indexData.pSysMem = &indices[0];
	// Create index buffer on device using descriptor & data
	dxdevice->CreateBuffer(&indexbufferDesc, &indexData, &m_index_buffer);
	SETNAME(m_index_buffer, "IndexBuffer");

	m_number_of_indices = (unsigned int)indices.size();
}


void Cube::Render() const
{
	// Bind our vertex buffer
	const UINT32 stride = sizeof(Vertex); //  sizeof(float) * 8;
	const UINT32 offset = 0;
	m_dxdevice_context->IASetVertexBuffers(0, 1, &m_vertex_buffer, &stride, &offset);

	// Bind our index buffer
	m_dxdevice_context->IASetIndexBuffer(m_index_buffer, DXGI_FORMAT_R32_UINT, 0);

	//bind material buffer
	m_dxdevice_context->PSSetConstantBuffers(1, 1, &m_material_buffer);

	// Make the drawcall
	m_dxdevice_context->DrawIndexed(m_number_of_indices, 0, 0);

	

	D3D11_MAPPED_SUBRESOURCE resource;
	m_dxdevice_context->Map(m_material_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &resource);
	MaterialBuffer* materialbuffer = (MaterialBuffer*)resource.pData;
	materialbuffer->Ambient = default_material.AmbientColour;
	materialbuffer->Diffuse = default_material.DiffuseColour;
	materialbuffer->Specular = default_material.SpecularColour;
	m_dxdevice_context->Unmap(m_material_buffer, 0);
}