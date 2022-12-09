#pragma once
#include "InputHandler.h"
#include "SceneManager/SceneManager.h"
#include "SpriteRenderer/SpriteRenderer.h"
#include "Time/Timer.h"
#include "ResourceManager/ResourceManager.hpp"
#include "Window/Window.h"


class Game
{
public:
	Game();
	~Game();

	bool Init();
	void ProcessEvents(); // Maybe buffer events (put them in a Queue, and the ProceesEvents at the beginning of each frame?)
	void Update();
	void LateUpdate();
	void Draw();		
	void Shutdown();
	bool IsRunning() const;

private:
	void RegisterScenes();
	void MapControlls();

	//ResourceManager<sf::Font, std::string>		m_fonts;
	SpriteRenderer								m_spriteRenderer; 
	InputHandler								m_inputHandler;
	ResourceManager<Texture2D, std::string>		m_textureManager;
	ResourceManager<Shader, std::string>		m_shaderManager;
	SceneManager								m_sceneManager;
	Window										m_window;
	CU::Timer									m_timer;
};
