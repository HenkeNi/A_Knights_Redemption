#pragma once
#include "Entity.h"
#include "EntityBlueprint.h"
#include "ECS/Components/ComponentFactory.h"

namespace ECS
{
	using EntityType = std::string;
}

class EntityFactory
{
public:
	EntityFactory();
	~EntityFactory();

	Entity	Create(const ECS::EntityType& aType);
	void	LoadBlueprint(const std::string& aPath);
	void	RegisterBlueprint(const ECS::EntityType& anIdentifier, const EntityBlueprint& aBlueprint);


private:
	static ComponentFactory s_componentFactory;
	std::unordered_map<ECS::EntityType, EntityBlueprint> m_blueprints;
};