#pragma once
class Texture2D
{
public:
	Texture2D();

	void Generate(unsigned aWidth, unsigned aHeight, unsigned char* data);
	void Bind() const;

private:
	unsigned m_internalFormat, m_imageFormat;
	unsigned m_wrapS, m_wrapT;
	unsigned m_filterMin, m_filterMax;
	unsigned m_width, m_height;
	unsigned m_id;
};

