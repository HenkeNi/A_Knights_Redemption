#pragma once
#include "Component.h"
#include "Structs.h"

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

	void		SetText(const std::string& aText);
	void		SetColor(const CU::Vector3<float>& aColor);

private:
	std::weak_ptr<C_Transform>	m_transform;
	TextRenderer*				m_renderer;
	std::string					m_text;
	CU::Vector3<float>			m_color;


	// Shader here??
};