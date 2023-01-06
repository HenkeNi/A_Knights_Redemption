#pragma once
#include "Shader/Shader.h"
#include "Textures/Texture2D.h"


// Rename ResourceHandler? ResourceHolder?
template <typename Resource, typename Identifier = std::string>
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void			FetchAll(const std::string& aFilepath);
	void			Insert(Identifier anID, std::unique_ptr<Resource> aResource);

	void			Load(const Identifier& anID, const std::string& aPath, bool alpha);
	void			Load(const Identifier& anID, const std::string& aPath);

	Resource&		GetResource(const Identifier& anID);
	const Resource& GetResource(const Identifier& anID) const;
	void			Clear();

private:
	std::unordered_map<Identifier, std::unique_ptr<Resource>> m_resources;
};

using TextureManager = ResourceManager<Texture2D>;
using ShaderManager  = ResourceManager<Shader>;

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
void ResourceManager<Resource, Identifier>::FetchAll(const std::string& aFilepath)
{
	std::ifstream ifs{ aFilepath };
	std::string content{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

	rapidjson::Document document;
	if (document.Parse(content.c_str()).HasParseError()) { std::cerr << "[Parse Error]: " << aFilepath << '\n'; return; }

	for (auto& value : document.GetArray())
	{
		auto name = value["name"].GetString();
		auto path = value["filepath"].GetString();

		value.HasMember("alpha") ? Load(name, path, value["alpha"].GetBool()) : Load(name, path);
	}
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Insert(Identifier anID, std::unique_ptr<Resource> aResource)
{
	auto inserted = m_resources.insert(std::make_pair(anID, std::move(aResource)));
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Load(const Identifier& anID, const std::string& aPath, bool alpha)
{
	assert(false && "*** No Function Overload Found! ***"); 
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Load(const Identifier& anID, const std::string& aPath)
{
	assert(false && "*** No Function Overload Found! ***");
}

template <>
inline void ResourceManager<Texture2D, std::string>::Load(const std::string& aResourceName, const std::string& aPath, bool alpha)
{
	auto texture = std::make_unique<Texture2D>(alpha);
				
	int width, height, nrChannels;
	unsigned char* data = stbi_load(aPath.c_str(), &width, &height, &nrChannels, 0);
		
	texture->Init({ width, height }, data);
	stbi_image_free(data);
		
	Insert(aResourceName, std::move(texture));
}

template <>
inline void ResourceManager<Shader, std::string>::Load(const std::string& aResourceName, const std::string& aPath)
{
	auto shader = std::make_unique<Shader>();
	
	std::string vertex, fragment;
	
	std::ifstream vertexStream{ aPath + aResourceName + ".vertex.glsl"};
	vertex = { std::istreambuf_iterator<char>(vertexStream), std::istreambuf_iterator<char>() };
	
	std::ifstream fragmentStream{ aPath + aResourceName + ".fragment.glsl" };
	fragment = { std::istreambuf_iterator<char>(fragmentStream), std::istreambuf_iterator<char>() };
	
	// TODO: Geometryshader
	
	shader->Init(vertex.c_str(), fragment.c_str(), nullptr);
	
	Insert(aResourceName, std::move(shader));
}

template <typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::GetResource(const Identifier& anIdentifier)
{
	auto found = m_resources.find(anIdentifier);
	assert(found != m_resources.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::GetResource(const Identifier& anIdentifier) const
{
	return GetResource(anIdentifier);
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Clear()
{
	m_resources.clear();
}

#pragma endregion METHOD_DEFINITIONS