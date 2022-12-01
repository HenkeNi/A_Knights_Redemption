#pragma once
#include "Shader/Shader.h"

namespace CU = CommonUtilities;

class Texture2D;

class SpriteRenderer
{
public:
	SpriteRenderer(Shader &aShader);
	~SpriteRenderer();
	
	void Init();

	// Store this data in TEXTURE? -> rotation, etc..?
	void DrawSprite(Texture2D& aTexture, const CU::Vector2<float>& aRotation, const CU::Vector2<float>& aSize, const CU::Vector3<float>& aColor);

private:

	Shader		m_shader;
	unsigned	m_quadVAO;
};

