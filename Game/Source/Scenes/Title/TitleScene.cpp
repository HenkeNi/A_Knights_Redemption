#include "Pch.h"
#include "TitleScene.h"
#include "GuiFactory/GuiFactory.h"
#include "Transform/C_Transform.h"


TitleScene::TitleScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }, m_sceneDuration{ 1.5f }, m_shouldSkip{ false }
{
}

TitleScene::~TitleScene() {}

void TitleScene::ProcessEvents()
{
	if (m_sharedContext.m_inputHandler.IsKeyPressed(eInput::Key_Space))
	{
		m_shouldSkip = true;
	}
}

void TitleScene::Update(float aDeltaTime)
{
	UpdateDuration(aDeltaTime);

	if (IsTimeUp() || m_shouldSkip)
		m_sharedContext.m_sceneManager.PopScene();
	
	for (auto& object : m_sceneObjects)
		object.Update(aDeltaTime);
}

void TitleScene::LateUpdate(float aDeltaTime) {}

void TitleScene::Draw() const
{
	for (auto& object : m_sceneObjects)
		object.Draw();
}

void TitleScene::OnEnter()
{
	m_sceneDuration = 4.2f;
	m_shouldSkip = false;
}

void TitleScene::OnExit() {}

bool TitleScene::IsTimeUp() const
{
	return m_sceneDuration <= 0;
}

void TitleScene::UpdateDuration(float aDeltaTime)
{
	m_sceneDuration -= aDeltaTime;
}