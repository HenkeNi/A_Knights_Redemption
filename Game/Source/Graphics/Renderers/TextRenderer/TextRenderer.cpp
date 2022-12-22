#include "Pch.h"
#include "TextRenderer.h"


TextRenderer::TextRenderer()
	: m_textShader{ nullptr }, m_VAO{ 0 }, m_VBO{ 0 }
{
}

TextRenderer::~TextRenderer() 
{
}

void TextRenderer::Init(Shader* aTextShader, const CU::Vector2<float>& aSize)
{
	m_textShader = aTextShader;
    m_textShader->Activate();

    glm::mat4 projection = glm::ortho(0.0f, aSize.x, 0.0f, aSize.y);
    m_textShader->SetMatrix4("projection", projection);

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	
    glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void TextRenderer::Load(const std::string& aPath, unsigned aFontSize)
{
    // first clear the previously loaded Characters
    m_characters.clear();

    // then initialize and load the FreeType library
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) // all functions return a value different than 0 whenever an error occurred
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
    
    // load font as face
    FT_Face face;
    if (FT_New_Face(ft, aPath.c_str(), 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
    
    // set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, aFontSize);

    // disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    auto& glyph = face->glyph;

    // then for the first 128 ASCII characters, pre-load/compile their characters and store them
    for (unsigned char c = 0; c < 128; ++c)  
    {
        // load character glyph 
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        } 

        // generate texture
        unsigned texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, glyph->bitmap.width, glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, glyph->bitmap.buffer);

        // set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // now store character for later use
        Character character;
        character.m_size = { glyph->bitmap.width, glyph->bitmap.rows };
        character.m_bearing = { (int)glyph->bitmap_left, (int)glyph->bitmap_top };
        character.m_textureID = texture;
        character.m_advanced = glyph->advance.x;
        
        m_characters.insert(std::make_pair(c, character)); // std::pair<char, Character>(c, character));
    }
    glBindTexture(GL_TEXTURE_2D, 0);

    // destroy FreeType once we're finished
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}

//void TextRenderer::RenderText(const TextRenderData& someData)
//{
//    // activate corresponding render state	
//    m_textShader->Activate();
//    m_textShader->SetVector3f("textColor", someData.m_color);
//    glActiveTexture(GL_TEXTURE0);
//    glBindVertexArray(m_VAO);
//
//    // iterate through all characters
//    std::string::const_iterator c;
//    auto position = someData.m_position;
//    
//    for (c = someData.m_text.begin(); c != someData.m_text.end(); c++)
//    {
//        Character ch = m_characters[*c];
//
//        float xpos = position.x + ch.m_bearing.x * someData.m_scale;
//        float ypos = position.y + (m_characters['H'].m_bearing.y - ch.m_bearing.y) * someData.m_scale;
//
//        float w = ch.m_size.x * someData.m_scale;
//        float h = ch.m_size.y * someData.m_scale;
//        // update VBO for each character
//        float vertices[6][4] = {
//          { xpos,     ypos + h,     0.0f, 0.0f },
//            { xpos,     ypos,       0.0f, 1.0f },
//            { xpos + w, ypos,       1.0f, 1.0f },
//
//            { xpos,     ypos + h,   0.0f, 0.0f },
//            { xpos + w, ypos,       1.0f, 1.0f },
//            { xpos + w, ypos + h,   1.0f, 0.0f }
//        };
//        // render glyph texture over quad
//        glBindTexture(GL_TEXTURE_2D, ch.m_textureID);
//        // update content of VBO memory
//        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData
//        glBindBuffer(GL_ARRAY_BUFFER, 0);
//        // render quad
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        // now advance cursors for next glyph
//        position.x += (ch.m_advanced >> 6) * someData.m_scale; // bitshift by 6 to get value in pixels (1/64th times 2^6 = 64)
//    }
//    glBindVertexArray(0);
//    glBindTexture(GL_TEXTURE_2D, 0);
//}