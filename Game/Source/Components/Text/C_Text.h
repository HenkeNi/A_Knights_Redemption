#pragma once
#include "Component.h"

class C_Transform;
class TextRenderer;

class C_Text : public Component
{
public:
	C_Text(GameObject* anOwner);
	C_Text(GameObject* anOwner, TextRenderer* aTextRenderer);

	void		HandleMessage(eMessage aMessageType, const std::any& someData)		  override;
	void		Update(float aDeltaTime)											  override;
	void		Draw()															const override;
	void		OnActivate()														  override;

private:
	std::weak_ptr<C_Transform>	m_transform;
	TextRenderer*				m_renderer;

	// Shader here??
};