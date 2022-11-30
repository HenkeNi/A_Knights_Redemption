#pragma once
#include "Math/Vectors/Vector.hpp"

namespace CommonUtilities
{
	template <class T>
	class Ray;

	template <typename T>
	class Sphere
	{
	public:
		Sphere();
		Sphere(const Sphere& aSphere);
		Sphere(const Vector3<T>& aCenter, T aRadius);

		void				InitWithCenterAndRadius(const Vector3<T>& aCenter, T aRadius);
		bool				IsInside(const Vector3<T>& aPosition)	const;

		const Vector3<T>&	GetCenterPosition()						const;
		const T&			GetRadius()								const;

	private:
		Vector3<T>			myCenterPosition;
		T					myRadius;
	};

#pragma region METHOD_DEFINITIONS

	template <typename T>
	Sphere<T>::Sphere()
		: myCenterPosition{ 0.f, 0.f, 0.f }, myRadius{ 0.f }
	{
	}

	template <typename T>
	Sphere<T>::Sphere(const Sphere& aSphere)
		: myCenterPosition{ aSphere.myCenterPosition }, myRadius{ aSphere.myRadius }
	{
	}

	template <typename T>
	Sphere<T>::Sphere(const Vector3<T>& aCenter, T aRadius)
		: myCenterPosition{ aCenter }, myRadius{ aRadius }
	{
	}

	template <typename T>
	void Sphere<T>::InitWithCenterAndRadius(const Vector3<T>& aCenter, T aRadius)
	{
		myCenterPosition = aCenter;
		myRadius = aRadius;
	}

	template <typename T>
	bool Sphere<T>::IsInside(const Vector3<T>& aPosition)	const
	{
		Vector3<T> distance = aPosition - myCenterPosition;
		return distance.LengthSqr() <= (myRadius * myRadius);
	}

	template <typename T>
	const Vector3<T>& Sphere<T>::GetCenterPosition()		const
	{
		return myCenterPosition;
	}

	template <typename T>
	const T& Sphere<T>::GetRadius()							const
	{
		return myRadius;
	}

#pragma endregion METHOD_DEFINITIONS
}

