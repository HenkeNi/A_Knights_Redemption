#pragma once
#include "Volumes/Lines/Line.hpp"
#include "Math/Vectors/Vector.hpp"
#include <vector>

namespace CommonUtilities
{
	template <typename T>
	class LineVolume
	{
	public:
		LineVolume() = default;
		LineVolume(const std::vector<Line<T>>& aLineList);

		void AddLine(const Line<T>& aLine);
		bool IsInside(const Vector2<T>& aPoint);

	private:
		std::vector<Line<T>> myLineList;
	};

#pragma region METHOD_DEFINITIONS

	template <typename T>
	LineVolume<T>::LineVolume(const std::vector<Line<T>>& aLineList)
	{
		myLineList = aLineList;
	}

	template <typename T>
	void LineVolume<T>::AddLine(const Line<T>& aLine)
	{
		myLineList.push_back(aLine);
	}

	/* - A point is inside a LineVolume (convex polygon) if it's inside all of the lines making up the volume - */
	template <typename T>
	bool LineVolume<T>::IsInside(const Vector2<T>& aPoint)
	{
		for (const auto& line : myLineList)
		{
			if (!line.IsInside(aPoint))
			{
				return false;
			}
		}
		return true;
	}

#pragma endregion METHOD_DEFINITIONS
}