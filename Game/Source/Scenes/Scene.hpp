#pragma once
#include "GameObject.h"
#include "Structs.h"
#include "Listeners/EventListener.h"

class Scene : public EventListener
{
public:
	Scene(SharedContext aSharedContext) : m_sharedContext{ aSharedContext } {}
	virtual ~Scene() = default;

	virtual void			Init()								= 0;
	virtual void			Update(float aDeltaTime)			= 0;
	virtual void			LateUpdate(float aDeltaTime)		= 0;
	virtual void			Draw()						  const = 0;
	virtual bool			IsOverlay()					  const;

	virtual void			OnEnter() {};
	virtual void			OnExit() {};

protected:
	SharedContext			m_sharedContext;
	std::vector<GameObject> m_gameObjects; // [Consider]: replacing with VectorOnStack instead? SceneObjects? 
};

#pragma region METHOD_DEFINITIONS

inline bool Scene::IsOverlay() const { return false; }

#pragma endregion METHOD_DEFINITIONS