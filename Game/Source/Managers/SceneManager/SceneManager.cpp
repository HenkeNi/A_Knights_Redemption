#include "Pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GuiFactory/GuiFactory.h"
#include "Transform/C_Transform.h"


SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

std::shared_ptr<Scene> SceneManager::GetActiveScene()
{
	return m_scenes[(int)m_sceneStack.GetTop()];
}

void SceneManager::SetupScenes(Window& aWindow)
{
	std::ifstream ifs{ "../Assets/Json/Scenes/SceneData.json" };
	std::string content{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

	rapidjson::Document document;
	if (document.Parse(content.c_str()).HasParseError()) 
	{ 
		std::cerr << "Failed to parse SceneData.json\n"; 
		return; 
	}
	
	auto screenSize = aWindow.GetSize();

	for (auto& scene : document.GetArray())
	{
		auto index = (int)scene["scene_type"].GetInt();
		for (auto& object : scene["objects"].GetArray())
		{
			GameObject sceneObject;
			std::string type = object["type"].GetString();

			if (type == "background")
				sceneObject = GuiFactory::GetInstance().CreateBackground((eSceneType)index);
			else if (type == "image")
				sceneObject = GuiFactory::GetInstance().CreateImage(object["image_name"].GetString());
			else if (type == "title")
				sceneObject = GuiFactory::GetInstance().CreateTitle(object["text"].GetString());
			else if (type == "label")
				sceneObject = GuiFactory::GetInstance().CreateLabel(object["text"].GetString());
			else if (type == "button")
				sceneObject = GuiFactory::GetInstance().CreateButton("Play", object["action"].GetInt());

			sceneObject.GetComponent<C_Transform>()->SetPosition({ screenSize.x * object["position"]["x"].GetFloat(),
				screenSize.y * object["position"]["y"].GetFloat() });

			sceneObject.GetComponent<C_Transform>()->SetScale({ object["scale"]["width"].GetFloat(), object["scale"]["height"].GetFloat() });

			m_scenes[index]->m_sceneObjects.push_back(sceneObject);
		}
	}
}

void SceneManager::ProcessEvents()
{
	m_scenes[static_cast<int>(m_sceneStack.GetTop())]->ProcessEvents();
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
	m_scenes[(int)aType] = std::move(aScene);
	m_scenes[(int)aType]->OnCreated();
}

void SceneManager::SetActiveScenes(const std::vector<eSceneType>& someScenes)
{
	for (auto& scene : someScenes)
		m_sceneStack.Push(scene);
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
	for (auto& scene : m_scenes)
		scene->OnDestroyed();

	m_sceneStack.Clear();
}

bool SceneManager::IsEmpty() const
{
	return m_sceneStack.IsEmpty();
}