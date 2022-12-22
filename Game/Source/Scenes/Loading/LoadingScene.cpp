#include "Pch.h"
#include "LoadingScene.h"


LoadingScene::LoadingScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }
{
}

LoadingScene::~LoadingScene()
{
}

void LoadingScene::Init()
{
}

void LoadingScene::Receive(Event& anEvent)
{
}

void LoadingScene::Update(float aDeltaTime)
{
}

void LoadingScene::LateUpdate(float aDeltaTime)
{
}

void LoadingScene::Draw() const
{
}

void LoadingScene::OnEnter()
{
}

void LoadingScene::OnExit()
{
}

bool LoadingScene::IsDoneLoading() const
{
	return false;
}

void LoadingScene::LoadResources()
{
}