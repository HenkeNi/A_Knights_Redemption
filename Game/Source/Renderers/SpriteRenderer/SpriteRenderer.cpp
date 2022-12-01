#include "Pch.h"
#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(Shader& aShader)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Init()
{
	// Configure VAO/VBO
	unsigned VBO;
	float vertices[] = {
		// pos      // tex
		0.f, 1.f,	0.f, 1.f,
		1.f, 0.f,	1.f, 0.f,
		0.f, 0.f,	0.f, 0.f,

		0.f, 1.f,	0.f, 1.f,
		1.f, 1.f,	1.f, 1.f,
		1.f, 0.f,	1.f, 0.f
	};

	glGenVertexArrays(1, &m_quadVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(m_quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SpriteRenderer::DrawSprite(Texture2D& aTexture, const CU::Vector2<float>& aRotation, const CU::Vector2<float>& aSize, const CU::Vector3<float>& aColor)
{
	m_shader.Activate();
	//CU::Vec
}
