#pragma once
#include "Shader/Shader.h"
#include "Structs.h"

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
	// Rename RenderSprite??
	void RenderSprite(const SpriteRenderData& someData);
	//void DrawSprite(Texture2D& aTexture, const CU::Vector2<float>& aPosition, const CU::Vector2<float>& aSize, const CU::Vector3<float>& aColor, float aRotation = 0.f);

private:

	Shader*		m_shader;	// Accept shader when rendering??
	unsigned	m_quadVAO;
};

