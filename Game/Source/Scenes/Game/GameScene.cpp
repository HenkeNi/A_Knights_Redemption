#include "Pch.h"
#include "GameScene.h"


GameScene::GameScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }, m_shouldPause{ false }
{
	m_sceneObjects.reserve(512);
}

GameScene::~GameScene()
{
}

void GameScene::ProcessEvents()
{
	if (m_sharedContext.m_inputHandler.IsKeyPressed(eInput::Key_Escape))
		m_shouldPause = true;

	m_sharedContext.m_inputHandler.ProcessInput();
}

//void GameScene::Receive(Event& anEvent)
//{
//	if (!m_isActive)
//		return;
//
//	if (anEvent.GetEventType() == eEventType::Reject) 
//	{
//		anEvent.HandleEvent();
//		m_sharedContext.m_sceneManager.PushScene(eSceneType::Pause);
//	}
//}

void GameScene::Update(float aDeltaTime)			  
{
	if (m_shouldPause)
		PauseGame();

	for (auto& object : m_sceneObjects)
		object.Update(aDeltaTime);
}

void GameScene::LateUpdate(float aDeltaTime)		  
{
	for (auto& object : m_sceneObjects)
		object.LateUpdate(aDeltaTime);
}

void GameScene::Draw() const 
{
	for (auto& object : m_sceneObjects)
		object.Draw();
}

void GameScene::OnEnter() 
{
	m_shouldPause = false;
}

void GameScene::OnExit()  {}

void GameScene::RegisterLevels()
{
}

void GameScene::PauseGame()
{
	m_sharedContext.m_sceneManager.PushScene(eSceneType::Pause);
}