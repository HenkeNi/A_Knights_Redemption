#include "Pch.h"
#include "GameScene.h"


GameScene::GameScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
}

void GameScene::Receive(Event& anEvent)
{
}

void GameScene::Update(float aDeltaTime)			  
{
}

void GameScene::LateUpdate(float aDeltaTime)		  
{
}

void GameScene::Draw() const 
{
}

void GameScene::OnEnter()
{
}

void GameScene::OnExit()
{
}

void GameScene::RegisterLevels()
{
}

bool GameScene::IsPauseEnabled() const
{
	return false;
}

void GameScene::PauseGame()
{
}