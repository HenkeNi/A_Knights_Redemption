#pragma once
#include "Enumerations.h"

class GameObject;
class Renderer;

class Component
{
public:
	Component(GameObject* anOwner) : m_owner{ anOwner }, m_isActive{ true } {}
	virtual ~Component() = default;

	virtual void	HandleMessage(eMessage aMessageType, const std::any& someData)	= 0;
	//virtual void	Activate()														= 0;
	//virtual void	Deactivate()													= 0;
	virtual void	Update(float aDeltaTime)										= 0;
	virtual void	LateUpdate(float aDeltaTime)									 {};
	virtual void	Draw()													   const {};
	//virtual void	Draw(Window& aWindow)									   const {};

	inline  void	SetOwner(GameObject* anOwner)	{ m_owner = anOwner;	 }
	inline  bool	IsActive() const				{ return m_isActive;	 }

protected:
	GameObject*		m_owner; // [Consider] replacing with GameObjectID... or a Weak_ptr?
	bool			m_isActive;
};