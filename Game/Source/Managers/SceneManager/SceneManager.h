#pragma once
#include "DataTypes/Enumerations.h"
#include "DataStructures/Linear/Stack/Stack.hpp"

namespace CU = CommonUtilities;

class Scene;
class Window;

// TODO: replace array with other data structure? Binary Search Tree? - [Might actually be worse?!]

namespace
{
	using SceneArray = std::array<std::shared_ptr<Scene>, (int)eSceneType::Count>;
}

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	std::shared_ptr<Scene>		 GetActiveScene();

	void SetupScenes(Window& aWindow);
	void ProcessEvents();
	void Update(float aDeltaTime);
	void LateUpdate(float aDeltaTime);
	void Draw()		const;

	void RegisterScene(std::unique_ptr<Scene> aScene, eSceneType aType);
	void SetActiveScenes(const std::vector<eSceneType>& someScenes);
	void PushScene(eSceneType aType);
	void PopScene();
	void SwapScenes(eSceneType aType);
	void Clear();
	bool IsEmpty()	const;

private:
	SceneArray				m_scenes;
	CU::Stack<eSceneType>	m_sceneStack;
	// std::array<std::unique_ptr<Scene>, (int)eSceneType::Count>	m_scenes;			
};
