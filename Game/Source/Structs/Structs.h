#pragma once
#include "SceneManager/SceneManager.h"
#include "Shader/Shader.h"
#include "Textures/Texture2D.h"
#include "Window/Window.h"


struct SharedContext
{
	Window&										m_window;
	SceneManager&								m_sceneManager;
	//ResourceManager<Texture2D, std::string>&	m_textureManager;
	//ResourceManager<Shader, std::string>&		m_shaderManager;
};