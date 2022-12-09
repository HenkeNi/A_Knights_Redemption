#version 330 core
layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vec4(aPosition.xy, 0.0, 1.0);
	TexCoord = aTexCoord;
}


//layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

//out vec2 TexCoords;

//uniform mat4 model;
//uniform mat4 projection;

//void main()
//{
  //  TexCoords = vertex.zw;
   // gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
//}