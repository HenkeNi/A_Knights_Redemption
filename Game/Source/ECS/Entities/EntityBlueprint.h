#pragma once


namespace ECS
{
	using ComponentData = std::unordered_map<std::string, std::any>;
}

class EntityBlueprint // Blueprint, Template or Prototype prefab
{
public:
	EntityBlueprint();
	~EntityBlueprint();

	// Should now how to init itself with json?

	void AddComponentData(const std::string& aComponentType, const ECS::ComponentData& someData);

private:
	std::unordered_map<std::string, ECS::ComponentData> m_componentData;
	// ECS::EntityType										m_identifier; -> not needed?!
};