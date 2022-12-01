#include "Pch.h"
#include "Shader.h"


Shader::Shader()
{
}

Shader& Shader::Activate()
{
	glUseProgram(m_id);
	return *this;
}

void Shader::Init(const char* vSource, const char* fSource, const char* gSource)
{
	/* Create Vertex Shader */
	unsigned vertexShader = CreateShader(GL_VERTEX_SHADER, vSource); 
	CheckCompileErrors(vertexShader, "VERTEX");

	/* Create Fragment Shader */
	unsigned fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fSource);
	CheckCompileErrors(fragmentShader, "FRAGMENT");
	
	/* Create Geometry Shader */
	unsigned geometryShader; 
	if (gSource)
	{
		geometryShader = CreateShader(GL_GEOMETRY_SHADER, gSource);
		CheckCompileErrors(geometryShader, "GEOMETRY");
	}

	/* Create Program */
	m_id = glCreateProgram();
	glAttachShader(m_id, vertexShader);
	glAttachShader(m_id, fragmentShader);

	if (gSource) 
		glAttachShader(m_id, geometryShader);
	
	glLinkProgram(m_id);
	CheckCompileErrors(m_id, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	if (gSource)
		glDeleteShader(geometryShader);
}

bool Shader::LoadFromFile(const std::string& aFilepath)
{


	return true;
}

void Shader::SetBool(const std::string& aName, bool aValue)	const
{
	glUniform1i(glGetUniformLocation(m_id, aName.c_str()), (int)aValue);
}

void Shader::SetInt(const std::string& aName, int aValue) const
{
	glUniform1i(glGetUniformLocation(m_id, aName.c_str()), aValue);
}

void Shader::SetFloat(const std::string& aName, float aValue) const
{
	glUniform1f(glGetUniformLocation(m_id, aName.c_str()), aValue);
}

void Shader::SetVector2f(const std::string& aName, const CU::Vector2<float>& aValue) const
{
	glUniform2f(glGetUniformLocation(m_id, aName.c_str()), aValue.x, aValue.y);
}

void Shader::SetVector3f(const std::string& aName, const CU::Vector3<float>& aValue) const
{
	glUniform3f(glGetUniformLocation(m_id, aName.c_str()), aValue.x, aValue.y, aValue.z);
}

void Shader::SetVector4f(const std::string& aName, const CU::Vector4<float>& aValue) const
{
	glUniform4f(glGetUniformLocation(m_id, aName.c_str()), aValue.x, aValue.y, aValue.z, aValue.w);
}

void Shader::SetMatrix4x4(const std::string& aName, const CU::Matrix4x4<float>& aValue)	const
{
	assert(true && "NOT IMPLEMENTED");
	//	glUniformMatrix4fv(glGetUniformLocation(m_id, aName.c_str()), glm::v)
}

int	Shader::CreateShader(GLenum aShaderType, const char* aSource)
{
	unsigned shader = glCreateShader(aShaderType);
	glShaderSource(shader, 1, &aSource, nullptr);
	glCompileShader(shader);

	return shader;
}

void Shader::CheckCompileErrors(unsigned anObject, const std::string& aType)
{
	int		success;
	char	infoLog[1024];

	aType != "PROGRAM" ? glGetShaderiv(anObject, GL_COMPILE_STATUS, &success) : glGetProgramiv(anObject, GL_LINK_STATUS, &success);
	
	if (!success)
		std::cout << "ERROR::SHADER -> " << aType << '\n' << infoLog << '\n';
}