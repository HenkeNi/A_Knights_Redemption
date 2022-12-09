#pragma once
#include "Component.hpp"

class Texture2D;

class C_Sprite : public Component
{
public:
	C_Sprite(GameObject* anOwner);

	 

private:
	Texture2D* m_texture;
};

