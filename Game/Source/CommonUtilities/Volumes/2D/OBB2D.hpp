#pragma once
#include "Math/Vectors/Vector.hpp"
#include "Utility/UtilityFunctions.hpp"

/* - Description: Oriented Bounding Box (2D) is essentially an AABB with a rotation - */

// TODO: Rename OrientedRectangle (Oriented Bounding Box is 3D???!?!
namespace CommonUtilities
{
	template <typename T>
	class OBB2D 
	{
	public:
		OBB2D();
		OBB2D(const Vector2<T>& aCenter, const Vector2<T>& aHalfExtent, T aRotation = 0);
		~OBB2D();

		void SetPosition(const Vector2<T>& aCenterPos);		// COmbine to InitWithCenterAndHalfExtentAndRotation??
		void SetHalfExtent(const Vector2<T>& aHalfExtent); 
		void SetRotation(const T aRotation);
		bool IsInside(const Vector2<T>& aPoint);


	private:
		Vector2<T>	myCenter;
		Vector2<T>	myHalfExtent;
		T			myRotation;
	};

#pragma region METHOD_DEFINITIONS

	template <typename T>
	OBB2D<T>::OBB2D()
		: myCenter{ 0, 0 }, myHalfExtent{ 0, 0}, myRotation{ 0 }
	{
	}

	template <typename T>
	OBB2D<T>::OBB2D(const Vector2<T>& aCenter, const Vector2<T>& aHalfExtent, T aRotation)
		: myCenter{ aCenter }, myHalfExtent{ aHalfExtent }, myRotation{ aRotation }
	{
	}

	template <typename T>
	OBB2D<T>::~OBB2D()
	{
	}

	//template <typename T>
	//void OBB2D<T>::InitWithCenterAndRotation(const Vector2<T>& aCenter, T aRotation)
	//{
	//	myCenter	= aCenter;
	//	myRotation	= aRotation;
	//}

	template <typename T>
	void OBB2D<T>::SetPosition(const Vector2<T>& aCenterPos)
	{
		myCenter = aCenterPos;
	}

	template <typename T>
	void OBB2D<T>::SetHalfExtent(const Vector2<T>& aHalfExtent)
	{
		myHalfExtent = aHalfExtent;
	}

	template <typename T>
	void OBB2D<T>::SetRotation(const T aRotation)
	{
		myRotation = aRotation;
	}

	template <typename T>
	bool OBB2D<T>::IsInside(const Vector2<T>& aPoint) // TODO: FIX!
	{
		T newY = sin(myRotation) * (aPoint.y - myCenter.y) + cos(myRotation) * (aPoint.x - myCenter.x); // Swap cos and sin?? /* https://gamedev.stackexchange.com/questions/44110/point-inside-oriented-bounding-box */ 
		T newX = cos(myRotation) * (aPoint.x - myCenter.x) - sin(myRotation) * (aPoint.y - myCenter.y); 
		
		//T newY = cos(myRotation) * (aPoint.x - myCenter.x) + sin(myRotation) * (aPoint.y - myCenter.y);  
		//T newX = sin(myRotation) * (aPoint.y - myCenter.y) - cos(myRotation) * (aPoint.x - myCenter.x);

		return ((newY > myCenter.y - myHalfExtent.y && newY < myCenter.y + myHalfExtent.y) &&
			(newX > myCenter.x - myHalfExtent.x && newX < myCenter.x + myHalfExtent.x));

		//Vector2<T> rotVector = aPoint - myCenter;
		//T theta = -ConvertDegreesToRadians(myRotation);

		//T zRotation2x2[] = {
		//	cosf(theta), sinf(theta),
		//	-sinf(theta), cosf(theta)
		//};
	}


#pragma endregion METHOD_DEFINITIONS
}