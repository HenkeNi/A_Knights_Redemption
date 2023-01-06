#include "Pch.h"
#include "PauseScene.h"


PauseScene::PauseScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }, m_shouldResume{ false }
{
}

PauseScene::~PauseScene() {}

void PauseScene::ProcessEvents()
{
	if (m_sharedContext.m_inputHandler.IsKeyPressed(eInput::Key_Escape))
	{
		m_shouldResume = true;
	}
	m_sharedContext.m_inputHandler.ProcessInput();
}

void PauseScene::Update(float aDeltaTime)
{
	for (auto& object : m_sceneObjects)
		object.Update(aDeltaTime);
}

void PauseScene::LateUpdate(float aDeltaTime) {}

void PauseScene::Draw() const
{
	for (auto& object : m_sceneObjects)
		object.Draw();
}

void PauseScene::OnEnter()
{
	m_shouldResume = false;
}

void PauseScene::OnExit() {}

void PauseScene::ResumeGame() const
{
	m_sharedContext.m_sceneManager.PopScene();
}