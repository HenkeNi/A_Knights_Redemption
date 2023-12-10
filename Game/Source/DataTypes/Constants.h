#pragma once
#include <cstdint>

namespace Constants
{
	constexpr size_t MaxQuadCount	= 10000;
	constexpr size_t MaxVertexCount = MaxQuadCount * 4;
	constexpr size_t MaxIndexCount	= MaxQuadCount * 6;

	constexpr uint32_t MaxTextureSlots = 32;		
}