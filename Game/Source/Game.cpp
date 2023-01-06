#include "Pch.h"
#include "Game.h"
#include "Structs.h"
#include "Factories/GuiFactory/GuiFactory.h"
#include "Game/GameScene.h"
#include "HUD/HUDScene.h"
#include "Loading/LoadingScene.h"
#include "Menu/MenuScene.h"
#include "Pause/PauseScene.h"
#include "Title/TitleScene.h"


Game::Game() 
{
}

Game::~Game()
{
}

bool Game::Init()
{
	if (!m_window.Init() || glewInit() != GLEW_OK)
		return false;

	SetupOpenGL();

	m_textureManager.FetchAll("../Assets/Json/Textures.json");
	m_shaderManager.FetchAll("../Assets/Json/Shaders.json");
	
	m_inputHandler.Init(&m_window);
	m_spriteRenderer.Init();

	m_window.SetKeyCallback(m_inputHandler.KeyCallback);   // TODO: Instead of passing in a keycallback function -> send an event??? -> mark as handled??
	m_spriteRenderer.SetShader(&m_shaderManager.GetResource("sprite"));


	// Set projection and image in shader -> TODO: Move elsewhere???
	glm::mat4 projection = glm::ortho(0.f, (float)m_window.GetSize().x, (float)m_window.GetSize().y, 0.f, -1.f, 1.f);
	m_shaderManager.GetResource("sprite").Activate().SetInt("image", 0);
	m_shaderManager.GetResource("sprite").SetMatrix4("projection", projection);

	GuiFactory::GetInstance().Init(&m_textureManager, &m_spriteRenderer, &m_textRenderer);
	
	
	const auto& size = m_window.GetSize();

	m_textRenderer.Init(&m_shaderManager.GetResource("text"), { (float)size.x, (float)size.y });
	m_textRenderer.Load("../Assets/Fonts/PipeDream-1Zwg.ttf", 48);

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
	m_window.ClearScreen();
	m_sceneManager.Draw();
	m_window.SwapBuffers();
}

void Game::Shutdown()
{
}

bool Game::IsRunning() const
{
	return m_window.IsOpen();
}

void Game::SetupOpenGL()
{
	/* - Enable blending - */
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Game::RegisterScenes()
{
	auto sharedContext = SharedContext{ m_window, m_sceneManager, m_inputHandler };

	m_sceneManager.RegisterScene(std::make_unique<TitleScene>(sharedContext),	eSceneType::Title);
	m_sceneManager.RegisterScene(std::make_unique<LoadingScene>(sharedContext), eSceneType::Loading);
	m_sceneManager.RegisterScene(std::make_unique<MenuScene>(sharedContext),	eSceneType::Menu);
	m_sceneManager.RegisterScene(std::make_unique<GameScene>(sharedContext),	eSceneType::Game);
	m_sceneManager.RegisterScene(std::make_unique<PauseScene>(sharedContext),	eSceneType::Pause);

	m_sceneManager.SetActiveScenes({ eSceneType::Game, eSceneType::Menu, eSceneType::Loading, eSceneType::Title });
	m_sceneManager.SetupScenes(m_window);
}

void Game::MapControlls()
{
	// TODO: One key can do multiple events??

	m_inputHandler.MapEvent(eInput::Key_Space,	eEventType::Accept); 
	m_inputHandler.MapEvent(eInput::Key_Escape, eEventType::Reject);
}