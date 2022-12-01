#include "Pch.h"
#include "Texture2D.h"


Texture2D::Texture2D()
	: m_id{ 0 }
{
	glGenTextures(1, &m_id);
}


void Texture2D::Init(unsigned aWidth, unsigned aHeight, unsigned char* data)
{
	// Create Texture
	glBindTexture(GL_TEXTURE_2D, m_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, aWidth, aHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	
	// Set texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Texture2D::LoadFromFile(const std::string& aFilepath)
{
	std::cout << "Loading from path" << aFilepath;

	return true;
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}