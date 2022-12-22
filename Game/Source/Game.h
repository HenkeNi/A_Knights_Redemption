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
	void			ProcessEvents(); // Maybe buffer events (put them in a Queue, and the ProceesEvents at the beginning of each frame?)
	void			Update();
	void			LateUpdate();
	void			Draw();		
	void			Shutdown();
	bool			IsRunning()	const;

private:
	void			SetupOpenGL();
	void			RegisterScenes();
	void			MapControlls();

	SceneManager	m_sceneManager;
	ShaderManager	m_shaderManager;
	TextureManager	m_textureManager;
	TextRenderer	m_textRenderer;
	SpriteRenderer	m_spriteRenderer; 
	InputHandler	m_inputHandler;
	Window			m_window;
	CU::Timer		m_timer;
};
