#pragma once

namespace CU = CommonUtilities;

class Texture2D
{
public:
	Texture2D(bool isAlpha = false);


	void		Init(const CU::Vector2<int>& aSize, unsigned char* data); 
	//void		SetInternalFormat(unsigned aFormat);
	//void		SetImageFormat(unsigned aFormat);
	void		Bind() const;
	//bool		LoadFromFile(const std::string& aFilepath);

private:
	//unsigned	m_internalFormat, m_imageFormat; // GL_RGB is not of tpye unsigned int???
	int			m_internalFormat, m_imageFormat; // GL_RGB is not of tpye unsigned int???
	unsigned	m_id;
};