#include "Pch.h"
#include "Renderer.h"
#include "DataTypes/Constants.h"


void GenerateIndices(uint32_t* someIndices)
{
	uint32_t offset = 0;

	/* Generate all available indices */
	for (auto i = 0; i < Constants::MaxIndexCount; i += 6)
	{
		// first triangle
		someIndices[i + 0] = 0 + offset;
		someIndices[i + 1] = 1 + offset;
		someIndices[i + 2] = 2 + offset;

		// second triangle
		someIndices[i + 3] = 2 + offset;
		someIndices[i + 4] = 3 + offset;
		someIndices[i + 5] = 0 + offset;

		offset += 4;
	}
}


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Init()
{
	/* Create vertex array object */
	glGenVertexArrays(1, &m_quadContext.VAO);
	glBindVertexArray(m_quadContext.VAO);

	/* Create vertex buffer object */
	glGenBuffers(1, &m_quadContext.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_quadContext.VBO);
	glBufferData(GL_ARRAY_BUFFER, Constants::MaxVertexCount * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

	/* Specify layout of the vertex data */

	/* Position Attribute */
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));

	/* Color Attribute */
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));

	/* Texture Coord Attribute */
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

	/* Texture Index */
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexIndex));

	/* Populate indices */
	uint32_t indices[Constants::MaxIndexCount];
	GenerateIndices(indices);

	/* Create element buffer object */
	glCreateBuffers(1, &m_quadContext.EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_quadContext.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* Unbind VBO and VAO */
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Renderer::Shutdown()
{
	glDeleteVertexArrays(1, &m_quadContext.VAO);
	glDeleteBuffers(1, &m_quadContext.VBO);
	glDeleteBuffers(1, &m_quadContext.EBO);

	// Todo; Delete texture ??
	// glDeleteTextures(1, &m_whiteTexture); // MOVE later?

	delete[] m_quadContext.Buffer;
}

void Renderer::DrawSprite()
{
}

void Renderer::DrawQuad()
{
}

void Renderer::BeginFrame()
{
}

void Renderer::Display()
{
}

void Renderer::EndFrame()
{
}
