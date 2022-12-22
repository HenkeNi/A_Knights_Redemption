#include "Pch.h"
#include "GuiFactory.h"
#include "GameObject.h"
#include "Sprite/C_Sprite.h"
#include "SpriteRenderer/SpriteRenderer.h"


GuiFactory::GuiFactory()
	: m_textureManager{ nullptr }, m_spriteRenderer{ nullptr }
{
}

GuiFactory& GuiFactory::GetInstance()
{
	static GuiFactory instance;
	return instance; 
}

void GuiFactory::Init(TextureManager* aTextureManager, SpriteRenderer* aRenderer)
{
	m_textureManager = aTextureManager;
	m_spriteRenderer = aRenderer;
}

GameObject GuiFactory::CreateBackground(eSceneType aType)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject background;

	return background;
}

GameObject GuiFactory::CreateImage(const std::string& aTexture)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject image;
	image.CreateComponent<C_Sprite>(m_spriteRenderer, &m_textureManager->GetResource(aTexture));

	return image;
}

GameObject GuiFactory::CreateButton(const std::string& aText, const std::function<void()>& aCallback)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject button;
	return button;
}

GameObject GuiFactory::CreateTitle(const std::string& aText)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject title;
	return title;
}

GameObject GuiFactory::CreateLabel(const std::string& aText)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject label;
	return label;
}