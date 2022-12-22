#pragma once
#include "Shader/Shader.h"
#include "Textures/Texture2D.h"


// Rename ResourceHandler? ResourceHolder?
template <typename Resource, typename Identifier>
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void			FetchAll(const std::string& aFilepath);
	void			Insert(Identifier anIdentifier, std::unique_ptr<Resource> aResource);

	void			Load(const std::string& aResourceName, const std::string& aFilepath);

	//template		<typename... Args>
	//void			Load(Identifier anIdentifier, Args&&... args);
	Resource&		GetResource(Identifier anIdentifier);
	const Resource& GetResource(Identifier anIdentifier) const;
	void			Clear();

private:
	std::unordered_map<Identifier, std::unique_ptr<Resource>> m_resources;
};

using TextureManager = ResourceManager<Texture2D, std::string>;
using ShaderManager  = ResourceManager<Shader, std::string>;

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
	assert(typeid(Identifier) == typeid(std::string) && "Init requires std::string as Identifier"); // Make sure Identifier is a string => TODO... find cleaner solution (Function template specialization doesn't seem to work)

	std::ifstream ifs{ aFilepath };
	std::string content{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

	rapidjson::Document document;
	if (document.Parse(content.c_str()).HasParseError()) { std::cerr << "[Parse Error]: " << aFilepath << '\n'; return; }

	for (auto& resource : document.GetArray())
	{
		Load(resource["name"].GetString(), resource["filepath"].GetString()); // Include other things (like alpha)... iterate throu it?
	}
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Insert(Identifier anIdentifier, std::unique_ptr<Resource> aResource)
{
	auto inserted = m_resources.insert(std::make_pair(anIdentifier, std::move(aResource)));
	assert(inserted.second);
}

//template <typename Resource, typename Identifier>
//template <typename... Args>
//void ResourceManager<Resource, Identifier>::Load(Identifier anIdentifier, Args&&... args) // TODO: Breaks sinlge responsibility principle???
//{
	//	auto resource = std::make_unique<Resource>();
	//
	//	if (!resource->LoadFromFile(std::forward<Args>(args)...))
	//		throw std::runtime_error("Failed to load resource!\n"); // TODO: Throw if failed?
	//
	//	Insert(anIdentifier, std::move(resource));
//}

template <>
inline void ResourceManager<Texture2D, std::string>::Load(const std::string& aResourceName, const std::string& aFilepath)
{
	auto texture = std::make_unique<Texture2D>();

	/*if (alpha)
	{
		texture.Internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}*/

	int width, height, nrChannels;
	unsigned char* data = stbi_load(aFilepath.c_str(), &width, &height, &nrChannels, 0);

	texture->Init(width, height, data);
	stbi_image_free(data);

	Insert(aResourceName, std::move(texture));
}

template <>
inline void ResourceManager<Shader, std::string>::Load(const std::string& aResourceName, const std::string& aFilepath)
{
	auto shader = std::make_unique<Shader>();

	std::string vertex, fragment;

	std::ifstream vertexStream{ aFilepath + aResourceName + ".vertex.glsl"};
	vertex = { std::istreambuf_iterator<char>(vertexStream), std::istreambuf_iterator<char>() };

	std::ifstream fragmentStream{ aFilepath + aResourceName + ".fragment.glsl" };
	fragment = { std::istreambuf_iterator<char>(fragmentStream), std::istreambuf_iterator<char>() };

	// TODO: Geometryshader

  	shader->Init(vertex.c_str(), fragment.c_str(), nullptr);

	Insert(aResourceName, std::move(shader));
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

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::Clear()
{
	m_resources.clear();
}

#pragma endregion METHOD_DEFINITIONS
