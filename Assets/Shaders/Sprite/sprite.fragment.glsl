#version 330 core
out vec4 aColor;

in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
	aColor = texture(texture1, TexCoord);
}


//in vec2 TexCoords;
//out vec4 color;

//uniform sampler2D image;
//uniform vec3 spriteColor;

//void main()
//{    
//    color = vec4(0.3, 0.5, 0.1, 1.0) * texture(image, TexCoords);
//}  