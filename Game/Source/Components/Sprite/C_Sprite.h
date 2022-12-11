#pragma once
#include "Component.hpp"

namespace CU = CommonUtilities;

class C_Transform;
class SpriteRenderer;
class Texture2D;

class C_Sprite : public Component
{
public:
	C_Sprite(GameObject* anOwner);
	C_Sprite(GameObject* anOwner, SpriteRenderer* aRenderer, Texture2D* aTexture);

	void		HandleMessage(eMessage aMessageType, const std::any& someData)		  override;
	void		Update(float aDeltaTime)											  override;
	void		Draw()															const override;

	void		SetRenderer(SpriteRenderer* aRenderer);
	void		SetTexture(Texture2D* aTexture);
	// void MirrorSprite() -> Function for inverting Sprite...
	// void setRenderingRect();

private:
	std::weak_ptr<C_Transform>	m_transform;
	SpriteRenderer*				m_renderer;
	Texture2D*					m_texture;
};

