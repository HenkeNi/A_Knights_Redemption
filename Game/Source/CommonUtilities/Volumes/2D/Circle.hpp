#pragma once
#include "Math/Vectors/Vector.hpp"

namespace CommonUtilities
{
	template <typename T>
	class Circle
	{
	public:
		Circle();
		Circle(const Circle<T>& aCircle);
		Circle(const Vector2<T>& aCenter, T aRadius);

		void				InitWithCenterAndRadius(const Vector2<T>& aCenter, T aRadius);
		bool				IsInside(const Vector2<T>& aPoint)	const;

		const Vector2<T>&	GetCenterPosition()					const;
		const T&			GetRadius()							const;

	private:
		Vector2<T>			myCenterPosition;
 		T					myRadius;
	};

#pragma region METHOD_DEFINITIONS

	template <typename T>
	Circle<T>::Circle()
		: myCenterPosition{ 0, 0 }, myRadius{ 0 }
	{
	}

	template <typename T>
	Circle<T>::Circle(const Circle<T>& aCircle)
		: myCenterPosition{ aCircle.myCenterPosition }, myRadius{ aCircle.myRadius }
	{
	}

	template <typename T>
	Circle<T>::Circle(const Vector2<T>& aCenter, T aRadius)
		: myCenterPosition{ aCenter }, myRadius{ aRadius }
	{
	}

	template <typename T>
	void Circle<T>::InitWithCenterAndRadius(const Vector2<T>& aCenter, T aRadius)
	{
		myCenterPosition	= aCenter;
		myRadius			= aRadius;
	}

	template <typename T>
	bool Circle<T>::IsInside(const Vector2<T>& aPoint)		const
	{
		auto distance = aPoint - myCenterPosition;
		return distance.LengthSqr() <= (myRadius * myRadius);
	}

	template <typename T>
	const Vector2<T>& Circle<T>::GetCenterPosition()		const
	{
		return myCenterPosition;
	}
	
	template <typename T>
	const T& Circle<T>::GetRadius()							const
	{
		return myRadius;
	}

#pragma endregion METHOD_DEFINITIONS
}