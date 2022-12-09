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
	if (!m_window.Init() || glewInit() != GLEW_OK) // TODO: Instead of passing in a keycallback function -> send an event??? -> mark as handled??
		return false;  
	
	m_window.SetKeyCallback(m_inputHandler.KeyCallback); // OR Pass into Window.Init()??
	//m_window.SetIcon("../Assets/Textures/wall.jpg");	// TODO: read from json...
	m_textureManager.FetchAll("../Assets/Json/Textures.json");
	m_shaderManager.FetchAll("../Assets/Json/Shaders.json");
	m_inputHandler.Init(); 
	m_spriteRenderer.Init();

	m_spriteRenderer.SetShader(&m_shaderManager.GetResource("sprite"));

	// Set projection and image in shader -> TODO: Move elsewhere???
	glm::mat4 projection = glm::ortho(0.f, (float)m_window.GetSize().x, (float)m_window.GetSize().y, 0.f, -1.f, 1.f);
	m_shaderManager.GetResource("sprite").Activate().SetInt("image", 0);
	m_shaderManager.GetResource("sprite").SetMatrix4("projection", projection);

	RegisterScenes();
	MapControlls();

	return true;
}

void Game::ProcessEvents()
{
	m_window.PollEvents();
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

void Game::Draw()
{
	m_window.BeginDraw();



	m_spriteRenderer.DrawSprite(m_textureManager.GetResource("Wall"), CU::Vector2<float>{ 110.1f, 110.1f }, 
		CU::Vector2<float>{ 100.f, 100.f }, { 1.f, 1.f, 1.f }, 0.f);


	
	//m_sceneManager.Draw();
	
	
	//m_window.Draw(); // - remove...

	m_window.EndDraw();
}

void Game::Shutdown()
{
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