#pragma once
#include "Pch.h"
#include "InputHandler.h"
#include "SceneManager/SceneManager.h"
#include "Time/Timer.h"
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
	void Draw()				const;
	void Shutdown();
	bool IsRunning()		const;

private:
	void RegisterScenes();
	void MapControlls();


	//ResourceManager<sf::Texture, std::string>	m_textures;
	//ResourceManager<sf::Font, std::string>		m_fonts;
	InputHandler	m_inputHandler;
	SceneManager	m_sceneManager;
	Window			m_window;
	CU::Timer		m_timer;
};
