#include "Pch.h"
#include "TitleScene.h"
#include "GuiFactory/GuiFactory.h"
#include "Transform/C_Transform.h"
#include "Dispatcher/Dispatcher.h"


TitleScene::TitleScene(SharedContext aSharedContext)
	: Scene{ aSharedContext }, m_sceneDuration{ 4.2f }, m_shouldSkip{ false }
{
	//Dispatcher::GetInstance().Subscribe(eEventType::KeyPressed, this);
	m_gameObjects.reserve(16);
}

TitleScene::~TitleScene()
{
	//Dispatcher::GetInstance().Unsubscribe(eEventType::KeyPressed, this);
}

void TitleScene::Init()
{
	auto screenSize = m_sharedContext.m_window.GetSize();

	// Fetch all elemtns using json???
	// Also fetch scene duration?

	GameObject logo = GuiFactory::GetInstance().CreateImage("Wall");
	logo.GetComponent<C_Transform>()->SetPosition({ screenSize.x * 0.5f, screenSize.y * 0.5f });	// read from json?
	logo.GetComponent<C_Transform>()->SetScale({ 200.f, 200.f });									// read from json?
	m_gameObjects.push_back(logo);

	// TODO: Add 'Title', 'Creator', 

}

void TitleScene::Receive(Event& anEvent)
{
	/*if (anEvent.GetEventType() == eEventType::KeyPressed)
	{
		anEvent.HandleEvent();
		m_shouldSkip = true;
	}*/
}

void TitleScene::Update(float aDeltaTime)
{
	UpdateDuration(aDeltaTime);

	if (IsTimeUp() || m_shouldSkip)
		m_sharedContext.m_sceneManager.PopScene();
	
	for (auto& object : m_gameObjects)
		object.Update(aDeltaTime);
}

void TitleScene::LateUpdate(float aDeltaTime)
{
	for (auto& object : m_gameObjects)
		object.LateUpdate(aDeltaTime);
}

void TitleScene::Draw() const
{
	for (auto& object : m_gameObjects)
		object.Draw();
}

void TitleScene::OnEnter()
{
	m_sceneDuration = 4.2f;
}

void TitleScene::OnExit()
{
}

bool TitleScene::IsTimeUp() const
{
	return m_sceneDuration <= 0;
}

void TitleScene::UpdateDuration(float aDeltaTime)
{
	m_sceneDuration -= aDeltaTime;
}