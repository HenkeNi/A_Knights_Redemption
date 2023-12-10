#include "Pch.h"
#include "EntityFactory.h"
#include "Utility/UtilityFunctions.hpp"

ECS::ComponentData ParseComponent(const rapidjson::Value& aValue);

EntityFactory::EntityFactory()
{
}

EntityFactory::~EntityFactory()
{
}

Entity EntityFactory::Create(const ECS::EntityType& aType)
{
    return Entity();
}

void EntityFactory::LoadBlueprint(const std::string& aPath)
{
    std::ifstream ifs{ aPath };
    std::string content{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

    rapidjson::Document document;
    document.Parse(content.c_str());

    if (document.HasParseError())
    {
        std::cerr << "Error parsing: " << aPath << "\n";
        return;
    }

    EntityBlueprint blueprint;

    for (auto& component : document["components"].GetArray())
    {
        std::unordered_map<std::string, ECS::ComponentData> componentData;

        const rapidjson::Value& properties = component["properties"];
        componentData.insert_or_assign(component["type"].GetString(), ParseComponent(properties));
    }

    std::string blueprintID = document["identifier"].GetString();
    RegisterBlueprint(blueprintID, blueprint);
    
    // TODO. store type ("type: "transform") in COmponent base?
}

void EntityFactory::RegisterBlueprint(const ECS::EntityType& anIdentifier, const EntityBlueprint& aBlueprint)
{
    m_blueprints.insert_or_assign(anIdentifier, aBlueprint);
}

ECS::ComponentData ParseComponent(const rapidjson::Value& aValue)
{
    ECS::ComponentData data;

    for (auto& property : aValue.GetObject())
    {
        const std::string key = property.name.GetString();
        auto& value = property.value;

        data.insert_or_assign(key, CommonUtilities::GetJsonValue(value));  
    }

    return data;
}