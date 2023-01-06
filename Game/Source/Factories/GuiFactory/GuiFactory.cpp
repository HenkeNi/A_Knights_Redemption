#include "Pch.h"
#include "GuiFactory.h"
#include "GameObject.h"
#include "Sprite/C_Sprite.h"
#include "SpriteRenderer/SpriteRenderer.h"
#include "Text/C_Text.h"
#include "TextRenderer/TextRenderer.h"


GuiFactory::GuiFactory()
	: m_textureManager{ nullptr }, m_spriteRenderer{ nullptr }
{
}

GuiFactory& GuiFactory::GetInstance()
{
	static GuiFactory instance;
	return instance; 
}

void GuiFactory::Init(TextureManager* aTextureManager, SpriteRenderer* aRenderer, TextRenderer* aTextRenderer)
{
	m_textureManager = aTextureManager;
	m_spriteRenderer = aRenderer;
	m_textRenderer	 = aTextRenderer;
}

GameObject GuiFactory::CreateBackground(eSceneType aType)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject background;

	// Set size to window size

	return background;
}

GameObject GuiFactory::CreateImage(const std::string& aTexture)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject image;
	image.CreateComponent<C_Sprite>(m_spriteRenderer, &m_textureManager->GetResource(aTexture));

	return image;
}

GameObject GuiFactory::CreateButton(const std::string& aText, int anAction)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject button;
	return button;
}

GameObject GuiFactory::CreateTitle(const std::string& aText)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject title;
	auto text = title.CreateComponent<C_Text>(m_textRenderer);
	text->SetText(aText);
	text->SetColor({ 1.f, 1.f, 1.f });

	// Set size (and position)??

	return title;
}

GameObject GuiFactory::CreateLabel(const std::string& aText)
{
	assert(m_textureManager && m_spriteRenderer && "Factory is uninitialized");

	GameObject label;
	auto text = label.CreateComponent<C_Text>(m_textRenderer);
	text->SetText(aText);
	text->SetColor({ 0.2f, 0.2f, 0.2f });

	return label;
}


const std::function<void()>& GuiFactory::GetButtonAction(int anAction)
{
	// LOOK INTO COMMAND PATTERN!!

	std::function<void()> action = [](){};

	switch (anAction)
	{
	case 1:
		//action = [](){ m_sharedContext.m_}
		break;
	}

	return action;
}
