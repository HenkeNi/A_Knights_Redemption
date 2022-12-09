#pragma once
#include "Shader/Shader.h"

namespace CU = CommonUtilities;

class Texture2D;

// TODO: Create a PrimitivesRenderer??
class SpriteRenderer
{
public:
	SpriteRenderer();
	~SpriteRenderer();
	
	void Init();
	void SetShader(Shader* aShader);


	// TODO: accept a transform matrix??
	// Store this data in TEXTURE? -> rotation, etc..?
	void DrawSprite(Texture2D& aTexture, const CU::Vector2<float>& aPosition, const CU::Vector2<float>& aSize, const CU::Vector3<float>& aColor, float aRotation = 0.f);
	//void DrawSprite(C_Sprite* aSprite);

private:

	Shader*		m_shader;
	unsigned	m_quadVAO;
};

