#include "Pch.h"
#include "LoadingScene.h"


LoadingScene::LoadingScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }, m_sceneDuration{ 1.f }, m_elapsedTime{ 0.f }, m_isDoneLoading{ false }
{
}

LoadingScene::~LoadingScene()
{
}

void LoadingScene::ProcessEvents() {}

void LoadingScene::Update(float aDeltaTime)
{
	UpdateElapsedTime(aDeltaTime);

	if (IsDoneLoading())
		m_sharedContext.m_sceneManager.PopScene();

	for (auto& object : m_sceneObjects)
		object.Update(aDeltaTime);
}

void LoadingScene::LateUpdate(float aDeltaTime) {}

void LoadingScene::Draw() const
{
	for (auto& object : m_sceneObjects)
		object.Draw();
}

void LoadingScene::OnEnter()
{
	m_elapsedTime = 0.f;
}

void LoadingScene::OnExit() {}

bool LoadingScene::IsDoneLoading() const
{
	return m_isDoneLoading || m_elapsedTime >= m_sceneDuration;
}

void LoadingScene::UpdateElapsedTime(float aDeltaTime)
{
	m_elapsedTime += aDeltaTime;
}
