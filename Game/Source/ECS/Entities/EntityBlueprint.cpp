#include "Pch.h"
#include "EntityBlueprint.h"


EntityBlueprint::EntityBlueprint()
{
}

EntityBlueprint::~EntityBlueprint()
{
}

void EntityBlueprint::AddComponentData(const std::string& aComponentType, const ECS::ComponentData& someData)
{
	m_componentData.insert_or_assign(aComponentType, someData);
}