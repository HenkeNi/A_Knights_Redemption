#include "Pch.h"
#include "SceneManager.h"
#include "Scene.hpp"


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init(const std::vector<eSceneType>& someActiveScenes) // TODO: maybe rework function..
{
	// TODO: CU::Stack can accept an intializer list? or insert function
	for (auto& scene : someActiveScenes)
	{
		m_sceneStack.Push(scene);
	}

	for (auto& scene : m_scenes)
	{
		if (scene)
			scene->Init();
	}
}

void SceneManager::ProcessEvents()
{
}

void SceneManager::Update(float aDeltaTime)
{
	if (IsEmpty()) { return; }

	int index = static_cast<int>(m_sceneStack.GetTop());
	if (m_scenes[index]->IsOverlay())
	{
		m_scenes[index - 1]->Update(aDeltaTime);
	}

	m_scenes[index]->Update(aDeltaTime);
}

void SceneManager::LateUpdate(float aDeltaTime)
{
	if (IsEmpty()) { return; }

	int index = static_cast<int>(m_sceneStack.GetTop());
	if (m_scenes[index]->IsOverlay())
	{
		m_scenes[index - 1]->LateUpdate(aDeltaTime);
	}

	m_scenes[index]->LateUpdate(aDeltaTime);
}

void SceneManager::Draw() const
{
	if (IsEmpty()) { return; }

	int index = static_cast<int>(m_sceneStack.GetTop());
	if (m_scenes[index]->IsOverlay())
	{
		m_scenes[index - 1]->Draw();
	}

	m_scenes[index]->Draw();
}

void SceneManager::RegisterScene(std::unique_ptr<Scene> aScene, eSceneType aType)
{
	m_scenes[static_cast<int>(aType)] = std::move(aScene);
}

void SceneManager::PushScene(eSceneType aType)
{
	m_sceneStack.Push(aType);
	m_scenes[(int)m_sceneStack.GetTop()]->OnEnter();
}

void SceneManager::PopScene()
{
	if (!IsEmpty())
	{
		m_scenes[(int)m_sceneStack.GetTop()]->OnExit();
		m_sceneStack.Pop();

		m_scenes[(int)m_sceneStack.GetTop()]->OnEnter();
	}
}

void SceneManager::SwapScenes(eSceneType aType)
{
	if (!IsEmpty())
	{
		m_sceneStack.Pop();
		m_scenes[(int)m_sceneStack.GetTop()]->OnExit();
	}

	m_sceneStack.Push(aType);
	m_scenes[(int)m_sceneStack.GetTop()]->OnEnter();
}

void SceneManager::Clear()
{
	m_sceneStack.Clear();
}

bool SceneManager::IsEmpty() const
{
	return m_sceneStack.IsEmpty();
}