#pragma once

namespace CU = CommonUtilities;

class Shader
{
public:
	Shader();
	~Shader();
	 
	void	Init(const char* vSource, const char* fSource, const char* gSource = nullptr); 
	//bool	LoadFromFile(const std::string& aFilepath);

	Shader& Activate();
	
	void	SetBool(const std::string& aName,		bool aValue)						const;
	void	SetInt(const std::string& aName,		int aValue)							const;
	void	SetFloat(const std::string& aName,		float aValue)						const;
	void	SetVector2f(const std::string& aName,	const CU::Vector2<float>& aValue)	const;
	void	SetVector3f(const std::string& aName,	const CU::Vector3<float>& aValue)	const;
	void	SetVector4f(const std::string& aName,	const CU::Vector4<float>& aValue)	const;
	//void	SetMatrix4x4(const std::string& aName, const CU::Matrix4x4<float>& aValue)	const;
	void	SetMatrix4(const std::string& aName, const glm::mat4& aMatrix)	const;

private:
	int		CreateShader(GLenum aShaderType, const char* aSource);
	void	CheckCompileErrors(unsigned anObject, const std::string& aType);

	unsigned m_id;
};

