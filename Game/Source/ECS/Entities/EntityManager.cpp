#include "Pch.h"
#include "EntityManager.h"
#include "Systems/EventSystem/Dispatcher/Dispatcher.h"
#include "Systems/EventSystem/Events/Event.h"

EntityFactory EntityManager::s_entityFactory;

EntityManager::EntityManager()
{
	m_entities.reserve(512);
}

EntityManager::~EntityManager()
{
}

Entity* EntityManager::Create(const ECS::EntityType& aType)
{
	auto entity = s_entityFactory.Create(aType);
	m_entities.push_back(std::move(entity));

	auto* created = &m_entities.back();
	Dispatcher::GetInstance().SendEvent(Event{ eEventType::EntityCreated, created });

	return created;
}

Entity* EntityManager::Find(unsigned anID)
{
	auto it = std::find_if(m_entities.begin(), m_entities.end(), [=](const Entity& anEntity) { return anEntity.GetID() == anID; });

	if (it != m_entities.end())
		return &(*it);

	return nullptr;
}

void EntityManager::Destroy(unsigned anID)
{
	auto it = std::find_if(m_entities.begin(), m_entities.end(), [=](const Entity& anEntity) { return anEntity.GetID() == anID; });

	if (it != m_entities.end())
	{
		Dispatcher::GetInstance().SendEvent(Event{ eEventType::EntityDestroyed, &(*it) });
		m_entities.erase(it);
	}
}

void EntityManager::DestroyAll()
{
	m_entities.clear();
}
