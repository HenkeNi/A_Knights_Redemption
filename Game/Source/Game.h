#pragma once
#include "InputHandler.h"
#include "SceneManager/SceneManager.h"
#include "SpriteRenderer/SpriteRenderer.h"
#include "TextRenderer/TextRenderer.h"
#include "Time/Timer.h"
#include "ResourceManager/ResourceManager.hpp"
#include "Window/Window.h"


class Game
{
public:
	Game();
	~Game();

	bool			Init();
	void			GameLoop();
	void			Shutdown();

private:
	void			RegisterScenes();
	void			MapControlls();

	SceneManager	m_sceneManager;
	InputHandler	m_inputHandler;
	Window			m_window;

	ShaderManager	m_shaderManager;
	TextureManager	m_textureManager;
	TextRenderer	m_textRenderer;
	SpriteRenderer	m_spriteRenderer; 
};
