#pragma once
#include "InputHandler.h"
#include "SceneManager/SceneManager.h"
#include "Shader/Shader.h"
#include "Textures/Texture2D.h"
#include "Window/Window.h"


struct SharedContext
{
	Window&				m_window;
	SceneManager&		m_sceneManager;
	InputHandler&		m_inputHandler;
	//TextureManager&	m_textureManager;
	//ShaderManager&	m_shaderManager;
};

struct SpriteRenderData
{
	Texture2D&			m_texture;
	CU::Vector3<float>	m_color;
	CU::Vector2<float>	m_position, m_size;
	float				m_rotation;
};

struct TextRenderData
{
	std::string			m_text;
	CU::Vector3<float>	m_color;
	CU::Vector2<float>	m_position;
	float				m_scale;
};

struct Character
{
	CU::Vector2<unsigned>	m_size; // change to position (size)??
	CU::Vector2<int>		m_bearing; // change to position (size)??
	unsigned				m_textureID, m_advanced;
};



struct Vertex
{
	glm::vec3	Position;  // float Position[3];		// Change to CU::Vector3 instead??
	glm::vec4	Color;	   // float Color[4];			
	glm::vec2	TexCoords; // float TexCoords[2];		
	float		TexIndex;
	//GLint		TexIndex;
};

struct RenderContext
{
	class Shader* Shader = nullptr;
	Vertex* Buffer = nullptr;
	Vertex* CurrentVertex = nullptr;		// unsigned	m_currentBufferIndex;
	uint16_t			IndexCount = 0;
	unsigned			VAO, VBO, EBO;
};

struct RenderStats
{
	unsigned TotalDraws = 0;
	unsigned TotalQuads = 0;
};