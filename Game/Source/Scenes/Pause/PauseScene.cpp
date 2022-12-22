#include "Pch.h"
#include "PauseScene.h"


PauseScene::PauseScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }
{
}

void PauseScene::Init()
{

}

void PauseScene::Receive(Event& anEvent)
{

}

void PauseScene::Update(float aDeltaTime)
{

}

void PauseScene::LateUpdate(float aDeltaTime)
{

}

void PauseScene::Draw() const
{

}

void PauseScene::OnEnter()
{

}

bool PauseScene::IsResumeEnabled() const
{
	return false;
}

void PauseScene::ResumeGame() const
{

}