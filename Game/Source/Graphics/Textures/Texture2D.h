#pragma once


class Texture2D
{
public:
	Texture2D();


	void		Init(unsigned aWidth, unsigned aHeight, unsigned char* data); 
	//void		SetInternalFormat(unsigned aFormat);
	//void		SetImageFormat(unsigned aFormat);
	void		Bind() const;
	//bool		LoadFromFile(const std::string& aFilepath);

private:
	unsigned	m_internalFormat, m_imageFormat;
	unsigned	m_id;
};