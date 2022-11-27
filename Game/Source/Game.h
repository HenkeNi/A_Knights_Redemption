#pragma once
#include "Pch.h"
#include "Window/Window.h"


class Game
{
public:
	Game();
	~Game();

	bool Init();
	void ProcessInput(); // Maybe buffer events (put them in a Queue, and the ProceesEvents at the beginning of each frame?)
	void Update();
	void LateUpdate();
	void Draw();
	void Shutdown();
	bool IsRunning()			const;

private:
	void RegisterScenes();
	void MapControlls();


	//Engine m_engine;
	//InputHandler								m_inputHandler;
	//SceneManager								m_sceneManager;
	//ResourceManager<sf::Texture, std::string>	m_textures;
	//ResourceManager<sf::Font, std::string>		m_fonts;
	Window		m_window;
	//CU::Timer									m_timer;
};
