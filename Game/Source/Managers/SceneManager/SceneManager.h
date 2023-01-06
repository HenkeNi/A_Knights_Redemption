#pragma once
#include "Enumerations.h"
#include "DataStructures/Linear/Stack/Stack.hpp"

namespace CU = CommonUtilities;

class Scene;
class Window;

// TODO: replace array with other data structure? Binary Search Tree? - [Might actually be worse?!]

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

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
	std::array<std::unique_ptr<Scene>, (int)eSceneType::Count>	m_scenes;			
	CU::Stack<eSceneType>										m_sceneStack;
};
