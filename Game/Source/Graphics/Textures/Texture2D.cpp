#include "Pch.h"
#include "Texture2D.h"


Texture2D::Texture2D()
	: m_internalFormat{ GL_RGB }, m_imageFormat{ GL_RGB }, m_id{ 0 }
{
}


void Texture2D::Init(unsigned aWidth, unsigned aHeight, unsigned char* data)
{
	/* Generate Texture */ 
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	glTexImage2D(GL_TEXTURE_2D, 0, m_internalFormat, aWidth, aHeight, 0, m_imageFormat, GL_UNSIGNED_BYTE, data);

	// Set texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);
}

//bool Texture2D::LoadFromFile(const std::string& aFilepath)
//{	
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(aFilepath.c_str(), &width, &height, &nrChannels, 0);
//
//	if (data)
//	{
//		Init(width, height, data);
//
//		return true;
//	}
//
//	return false;
//}

//void Texture2D::SetInternalFormat(unsigned aFormat)
//{
//	m_internalFormat = aFormat;
//}
//
//void Texture2D::SetImageFormat(unsigned aFormat)
//{
//	m_imageFormat = aFormat;
//}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}