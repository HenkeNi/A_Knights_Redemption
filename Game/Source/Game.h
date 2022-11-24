#pragma once
#include "Pch.h"
#include "../../Engine/Source/Engine.h"
#include "../../Engine/Source/Application.h"





class GameApp : public Engine::Application
{
public:

	//inline Engine::Application* CreateApplication() override
	//{
	//	return new GameApp;
	//}

private:

};

Engine::Application* Engine::CreateApplication()
{
	return new GameApp;
}


class Game
{
public:
	Game();
	~Game();

	void Init();
	void ProcessInput();
	void Update();
	void LateUpdate();
	void Draw();
	void Shutdown();
	bool IsRunning() const;

private:
	void RegisterScenes();
	void MapControlls();

	//Engine m_engine;

	//InputHandler								m_inputHandler;
	//SceneManager								m_sceneManager;
	//ResourceManager<sf::Texture, std::string>	m_textures;
	//ResourceManager<sf::Font, std::string>		m_fonts;
	//Window										m_window;
	//CU::Timer									m_timer;
};



// GameApp : inherits from Application (in engine??)