#pragma once
#include "Structs.h"

class TextRenderer 
{
public:
	TextRenderer();
	~TextRenderer();

	void Init(Shader* aTextShader, const CU::Vector2<float>& aSize);
	void Load(const std::string& aPath, unsigned aFontSize);
	//void RenderText(const TextRenderData& someData);

   inline  void RenderText(const TextRenderData& someData)
    {
        // activate corresponding render state	
       m_textShader->Activate();
       m_textShader->SetVector3f("textColor", someData.m_color);
       
       glActiveTexture(GL_TEXTURE0);
       glBindVertexArray(m_VAO);

        // iterate through all characters
        auto position = someData.m_position;
        std::string::const_iterator c;
        for (c = someData.m_text.begin(); c != someData.m_text.end(); c++)
        {
            Character ch = m_characters[*c];

            float xpos = position.x + ch.m_bearing.x * someData.m_scale;
            float ypos = position.y - (ch.m_size.y - ch.m_bearing.y) * someData.m_scale;

            float w = ch.m_size.x * someData.m_scale;
            float h = ch.m_size.y * someData.m_scale;
            // update VBO for each character
            float vertices[6][4] = {
                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos,     ypos,       0.0f, 1.0f },
                { xpos + w, ypos,       1.0f, 1.0f },

                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos + w, ypos,       1.0f, 1.0f },
                { xpos + w, ypos + h,   1.0f, 0.0f }
            };
            // render glyph texture over quad
            glBindTexture(GL_TEXTURE_2D, ch.m_textureID);
            // update content of VBO memory
            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            // render quad
            glDrawArrays(GL_TRIANGLES, 0, 6);
            // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
            position.x += (ch.m_advanced >> 6) * someData.m_scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
        }
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }



private:
	//std::unordered_map<char, Character> m_characters; 
	std::unordered_map<GLchar, Character>   m_characters;
	Shader*								    m_textShader; // TODO: accept shader in Render??
	unsigned							    m_VAO, m_VBO;
};