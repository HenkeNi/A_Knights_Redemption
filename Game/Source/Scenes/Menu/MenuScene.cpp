#include "Pch.h"
#include "MenuScene.h"
#include "GuiFactory/GuiFactory.h"
#include "Transform/C_Transform.h"


MenuScene::MenuScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::ProcessEvents()
{
}

void MenuScene::Update(float aDeltaTime)		  
{
	for (auto& object : m_sceneObjects)
		object.Update(aDeltaTime);
}

void MenuScene::LateUpdate(float aDeltaTime) {}

void MenuScene::Draw() const 
{
	for (auto& object : m_sceneObjects)
		object.Draw();
}

void MenuScene::OnEnter() {}

void MenuScene::OnExit()  {}