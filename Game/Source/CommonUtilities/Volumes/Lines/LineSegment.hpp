#pragma once
#include "Math/Vectors/Vector.hpp"

/* - Description: a Segment is defined by a start point and an end point. - */

namespace CommonUtilities
{
	template <typename T>
	class LineSegment
	{
	public:
		LineSegment(const Vector2<T>& aStart, const Vector2<T>& aEnd);
		~LineSegment();

		bool	PointOnLine(const Vector2<T>& aPoint)	const;
		T		Length()								const;
		T		LengthSqr()								const;

	private:
		Vector2<T> myStartPoint;
		Vector2<T> myEndPoint;
	};

#pragma region METHOD_DEFINITIONS

	template <typename T>
	LineSegment<T>::LineSegment(const Vector2<T>& aStart, const Vector2<T>& aEnd)
		: myStartPoint{ aStart }, myEndPoint{ aEnd }
	{
	}

	template <typename T>
	LineSegment<T>::~LineSegment()
	{
	}

	template <typename T>
	bool LineSegment<T>::PointOnLine(const Vector2<T>& aPoint)	const // TODO: Check if works:..
	{
		// Find the slope 
		Vector2<T> direction = { myEndPoint.x - myStartPoint.x, myEndPoint.y - myStartPoint.y };
		T slope = direction.y / direction.x;

		// Find the y-intercept
		T intercept = myStartPoint.y - slope * myStartPoint.x;

		return aPoint.y == slope * aPoint.x + intercept;

	}

	template<typename T>
	T LineSegment<T>::Length() const
	{
		return std::sqrt((myEndPoint.x - myStartPoint.x) + (myEndPoint.y - myStartPoint.y));
	}

	template<typename T>
	inline T LineSegment<T>::LengthSqr() const
	{
		return (myEndPoint.x - myStartPoint.x) + (myEndPoint.y - myStartPoint.y);
	}

#pragma endregion METHOD_DEFINITIONS
}