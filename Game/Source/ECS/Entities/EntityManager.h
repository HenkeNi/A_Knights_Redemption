#pragma once
#include "Entity.h"
#include "EntityFactory.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	Entity* Create(const ECS::EntityType& aType);
	Entity* Find(unsigned anID);

	template <typename... Components>
	std::vector<Entity*> FindAll();

	template <typename... Components>
	Entity* FindFirst();

	void Destroy(unsigned anID);
	void DestroyAll();

private:
	static EntityFactory s_entityFactory;
	std::vector<Entity>  m_entities;
};

#pragma region Method_Definitions

template <typename... Components>
std::vector<Entity*> EntityManager::FindAll()
{
	std::vector<Entity*> found;

	for (auto& entity : m_entities)
	{
		if (entity.HasComponents<Components...>())
			found.push_back(&entity);
	}
	return found;
}

template <typename... Components>
Entity* EntityManager::FindFirst()
{
	for (auto& entity : m_entities)
	{
		if (entity.HasComponents<Components...>())
			return &entity;
	}

	return nullptr;
}

#pragma endregion Method_Definitions