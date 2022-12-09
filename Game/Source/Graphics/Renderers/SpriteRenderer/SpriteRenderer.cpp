#include "Pch.h"
#include "SpriteRenderer.h"
#include "Textures/Texture2D.h"


SpriteRenderer::SpriteRenderer(/*Shader& aShader*/)
	: m_shader{ nullptr }, m_quadVAO{ 0 }
{
}

SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &m_quadVAO);
}

void SpriteRenderer::Init()
{
	// TODO: Create a Vertex Struct??  

	float vertices[] = {
		// Position			// Texture Coords 
		  0.5f,  0.5f,		1.f, 1.f,
		  0.5f, -0.5f,		1.f, 0.f,
		 -0.5f, -0.5f,		0.f, 0.f,
		 -0.5f,  0.5f,		0.f, 1.f 
	};

	unsigned indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned VBO, EBO;
	glGenVertexArrays(1, &m_quadVAO);  
	glBindVertexArray(m_quadVAO);

	/* Create vertex buffer object */
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* Create Element array */
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* Specify layout of the vertex data */
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float))); // TODO: use same vec2 in shader??

	/* Unbind VBO and VAO */
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SpriteRenderer::SetShader(Shader* aShader)
{
	m_shader = aShader;
}

void SpriteRenderer::DrawSprite(Texture2D& aTexture, const CU::Vector2<float>& aPosition, const CU::Vector2<float>& aSize, const CU::Vector3<float>& aColor, float aRotation)
{
	assert(m_shader);

	m_shader->Activate();

	glm::mat4 model = glm::mat4(1.f);
	model = glm::translate(model, glm::vec3(aPosition.x, aPosition.y, 0.f)); // Use own math library!?

	model = glm::translate( model, glm::vec3(0.5f * aSize.x, 0.5f * aSize.y, 0.f));
	model = glm::rotate(model, glm::radians(aRotation), glm::vec3(0.f, 0.f, 1.f));
	model = glm::translate(model, glm::vec3(-0.5f * aSize.x, -0.5f * aSize.y, 0.f));

	model = glm::scale(model, glm::vec3(aSize.x, aSize.y, 1.f));

	m_shader->SetMatrix4("model", model);
	m_shader->SetVector3f("spriteColor", aColor);
	


	//CU::Matrix4x4<float> 
	//m_shader->SetMatrix4("model", )


	glActiveTexture(GL_TEXTURE0); 
	aTexture.Bind();

	glBindVertexArray(m_quadVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
