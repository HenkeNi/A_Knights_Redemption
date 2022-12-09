#include "Pch.h"
#include "C_Sprite.h"


C_Sprite::C_Sprite(GameObject* anOwner)
	: Component{ anOwner }, m_texture{ nullptr }
{
}