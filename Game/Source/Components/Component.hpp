#pragma once
#include "Enumerations.h"

class GameObject;
class Window;

class Component
{
public:
	Component(GameObject* anOwner) : m_owner{ anOwner }, m_isActive{ true } {}
	virtual ~Component() = default;

	virtual void	HandleMessage(eMessage aMessageType, const std::any& someData)	= 0;
	virtual void	Update(float aDeltaTime)										= 0;
	virtual void	LateUpdate(float aDeltaTime)									 {};
	virtual void	Draw(Window& aWindow) const										 {};

	inline  void	SetOwner(GameObject* anOwner) { m_owner = anOwner; }
	inline  void	SetIsActive(bool isActive) { m_isActive = isActive; }
	inline  bool	IsActive() const { return m_isActive; }

protected:
	GameObject*		m_owner; // [Consider] replacing with GameObjectID...
	bool			m_isActive;
};