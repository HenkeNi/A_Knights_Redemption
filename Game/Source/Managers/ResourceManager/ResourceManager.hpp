#pragma once
#include "Shader/Shader.h"
#include "Textures/Texture2D.h"


template <typename Resource, typename Identifier>
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void			Init(const std::string& aFilepath);
	void			InsertResource(Identifier anIdentifier, std::unique_ptr<Resource> aResource);

	template		<typename... Args>
	void			Load(Identifier anIdentifier, Args&&... args);
	Resource&		GetResource(Identifier anIdentifier);
	const Resource& GetResource(Identifier anIdentifier) const;

private:
	std::unordered_map<Identifier, std::unique_ptr<Resource>> m_resources;
};

#pragma region METHOD_DEFINITIONS

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::ResourceManager()
{
}

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::~ResourceManager()
{
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Init(const std::string& aFilepath)
{
	assert(typeid(Identifier) == typeid(std::string) && "Init requires std::string as Identifier"); // Make sure Identifier is a string => TODO... find cleaner solution (Function template specialization doesn't seem to work)

	std::ifstream ifs{ aFilepath };
	std::string content{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

	rapidjson::Document document;
	if (document.Parse(content.c_str()).HasParseError()) { std::cerr << "[Parse Error]: " << aFilepath << '\n'; return; }

	for (auto& resource : document.GetArray())
	{
		Load(resource["name"].GetString(), resource["filepath"].GetString());
	}
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::InsertResource(Identifier anIdentifier, std::unique_ptr<Resource> aResource)
{
	auto inserted = m_resources.insert(std::make_pair(anIdentifier, std::move(aResource)));
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename... Args>
void ResourceManager<Resource, Identifier>::Load(Identifier anIdentifier, Args&&... args)
{
	auto resource = std::make_unique<Resource>();

	if (!resource->LoadFromFile(std::forward<Args>(args)...))
		throw std::runtime_error("Failed to load resource!\n"); // TODO: Throw if failed?

	InsertResource(anIdentifier, std::move(resource));
}

template <typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::GetResource(Identifier anIdentifier)
{
	auto found = m_resources.find(anIdentifier);
	assert(found != m_resources.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::GetResource(Identifier anIdentifier) const
{
	return GetResource(anIdentifier);
}

#pragma endregion METHOD_DEFINITIONS

