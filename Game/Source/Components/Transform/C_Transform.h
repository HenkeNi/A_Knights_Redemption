#pragma once
#include "Component.hpp"
#include "Math/Vectors/Vector.hpp"

namespace CU = CommonUtilities;

class C_Transform : public Component
{
public:
	C_Transform(GameObject* anOwner);
	~C_Transform();

	void						HandleMessage(eMessage aMessageType, const std::any& someData)	override;
	void						Update(float aDeltaTime)										override;
	void						LateUpdate(float aDeltaTime)									override;

	void						SetPosition(const CU::Vector2<float>& aPosition);
	void						SetPosition(float aX, float aY);
	void						SetXPosition(float aX);
	void						SetYPosition(float aY);

	void						AddPosition(const CU::Vector2<float>& aPosition);
	void						AddPosition(float aX, float aY);

	const CU::Vector2<float>&	GetPosition()														const;
	bool						HasMoved()															const;

private:
	CU::Vector2<float>			m_currPosition, m_prevPosition;
	CU::Vector2<float>			m_rotation;
	CU::Vector2<float>			m_scale; // Use for Sprite...
};