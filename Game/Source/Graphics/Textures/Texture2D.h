#pragma once


class Texture2D
{
public:
	Texture2D();


	void		Init(unsigned aWidth, unsigned aHeight, unsigned char* data); 
	bool		LoadFromFile(const std::string& aFilepath);
	
	void		Bind() const;

private:
	unsigned	m_id;
};