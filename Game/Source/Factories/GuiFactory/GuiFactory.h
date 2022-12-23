#pragma once
#include "Enumerations.h"
#include "ResourceManager/ResourceManager.hpp"

class GameObject;
class SpriteRenderer;
class TextRenderer;

class GuiFactory
{
public:
	GuiFactory(const GuiFactory&)			 = delete;
	GuiFactory& operator=(const GuiFactory&) = delete;

	static GuiFactory&	GetInstance();

	void				Init(TextureManager* aTextureManager, SpriteRenderer* aRenderer, TextRenderer* aTextRenderer);
	GameObject			CreateBackground(eSceneType aType);
	GameObject			CreateImage(const std::string& aTexture);
	GameObject			CreateButton(const std::string& aText, const std::function<void()>& aCallback);
	GameObject			CreateTitle(const std::string& aText);
	GameObject			CreateLabel(const std::string& aText);

private:
	GuiFactory();

	TextureManager*		m_textureManager;
	SpriteRenderer*		m_spriteRenderer;
	TextRenderer*		m_textRenderer;
};