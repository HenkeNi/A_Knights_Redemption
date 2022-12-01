#include "Pch.h"
#include "Game.h"
#include "Structs.h"


Game::Game() 
{
}

Game::~Game()
{
}

bool Game::Init()
{
	if (!glfwInit() || !m_window.Init() || glewInit() != GLEW_OK)
		return false; 
	
	m_inputHandler.Init(m_window.GetWindow());
	m_textureManager.Init("../Assets/Json/Textures.json");

	// m_textures.Init("../Assets/Json/Textures.json", "textures");
	// m_fonts.Init("../Assets/Json/Fonts.json", "fonts");

	RegisterScenes();
	MapControlls();

	return true;
}

void Game::ProcessEvents()
{
	glfwPollEvents(); 
	m_sceneManager.ProcessEvents();
}

void Game::Update()
{
	m_timer.Update();
	m_sceneManager.Update(m_timer.GetDeltaTime());
}

void Game::LateUpdate()
{
	m_sceneManager.LateUpdate(m_timer.GetDeltaTime());
}

void Game::Draw() const
{
	//m_window.BeginDraw();

	m_sceneManager.Draw();
	m_window.Draw(); // - remove...

	//m_window.EndDraw();
}

void Game::Shutdown()
{
	glfwTerminate();
}

bool Game::IsRunning() const
{
	return m_window.IsOpen();
}

void Game::RegisterScenes()
{
	/*auto sharedContext = SharedContext{ m_window, m_sceneManager };

	m_sceneManager.RegisterScene(std::make_unique<TitleScene>(sharedContext), eSceneType::Title);
	m_sceneManager.RegisterScene(std::make_unique<LoadingScene>(sharedContext), eSceneType::Loading);
	m_sceneManager.RegisterScene(std::make_unique<MenuScene>(sharedContext), eSceneType::Menu);
	m_sceneManager.RegisterScene(std::make_unique<GameScene>(sharedContext), eSceneType::Game);
	m_sceneManager.RegisterScene(std::make_unique<PauseScene>(sharedContext), eSceneType::Pause);

	m_sceneManager.Init({ eSceneType::Game, eSceneType::Menu, eSceneType::Loading, eSceneType::Title });*/
}

void Game::MapControlls()
{

}