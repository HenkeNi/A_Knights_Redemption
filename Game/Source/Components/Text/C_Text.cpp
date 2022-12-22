#include "Pch.h"
#include "C_Text.h"
#include "GameObject.h"
#include "TextRenderer/TextRenderer.h"
#include "Transform/C_Transform.h"


C_Text::C_Text(GameObject* anOwner)
	: C_Text{ anOwner, nullptr }
{
}

C_Text::C_Text(GameObject* anOwner, TextRenderer* aTextRenderer)
	: Component{ anOwner }, m_renderer{ aTextRenderer }
{
}

void C_Text::HandleMessage(eMessage aMessageType, const std::any& someData)
{
}

void C_Text::Update(float aDeltaTime)
{
}

void C_Text::Draw()	const
{
	if (!m_renderer)
		return;

	auto transform = m_transform.lock();
	//m_renderer->RenderText()
}

void C_Text::OnActivate()
{
	m_transform = m_owner->GetComponent<C_Transform>();
}