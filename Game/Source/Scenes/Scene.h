#pragma once
#include "GameObject.h"
#include "DataTypes/Structs.h"
#include "Listeners/EventListener.h"

class SceneManager;

class Scene
{
public:
	Scene(SharedContext aSharedContext);
	virtual ~Scene() = default;

	virtual void			ProcessEvents()						= 0;
	virtual void			Update(float aDeltaTime)			= 0;
	virtual void			LateUpdate(float aDeltaTime)		= 0;
	virtual void			Draw()						  const = 0;
	virtual bool			IsOverlay()					  const;

	virtual void			OnCreated()						 {};
	virtual void			OnDestroyed()					 {};
	virtual void			OnEnter()						 {};
	virtual void			OnExit()						 {};

protected:
	friend class			SceneManager;

	SharedContext			m_sharedContext;
	std::vector<GameObject> m_sceneObjects; // [Consider]: replacing with VectorOnStack instead? 
};