#include "Pch.h"
#include "C_Sprite.h"
#include "GameObject.h"
#include "SpriteRenderer/SpriteRenderer.h"
#include "Transform/C_Transform.h"


C_Sprite::C_Sprite(GameObject* anOwner)
	: C_Sprite{ anOwner, nullptr, nullptr }
{
}

C_Sprite::C_Sprite(GameObject* anOwner, SpriteRenderer* aRenderer, Texture2D* aTexture)
	: Component{ anOwner }, m_renderer{ aRenderer }, m_texture{ aTexture }
{
	m_transform = m_owner->GetComponent<C_Transform>();
}

void C_Sprite::HandleMessage(eMessage aMessageType, const std::any& someData)
{
	// Listen for position changed (C_Transform)

	// Listen for scale changed (C_Transform)
}

void C_Sprite::Update(float aDeltaTime)
{
}

void C_Sprite::Draw() const
{
	if (!m_renderer || !m_texture)
		return;

	// TODO: Make C_Sprite a friend class instead??
	// TODO: Have a reference to Transform??
	//auto transform = m_owner->GetComponent<C_Transform>();
	auto transform = m_transform.lock();
	m_renderer->RenderSprite({ *m_texture, { 1.f, 1.f, 1.f }, transform->GetPosition(), transform->GetScale(), transform->GetRotation() });
}

void C_Sprite::OnActivate()
{
	m_transform = m_owner->GetComponent<C_Transform>();
}

void C_Sprite::SetRenderer(SpriteRenderer* aRenderer)
{
	m_renderer = aRenderer;
}

void C_Sprite::SetTexture(Texture2D* aTexture)
{
	m_texture = aTexture;
}