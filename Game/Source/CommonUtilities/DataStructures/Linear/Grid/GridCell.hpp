#pragma once
#include <vector>

namespace CommonUtilities
{
	template <typename T>
	class GridCell
	{
	public:
		void					AddObject(T* aObject);
		void					RemoveObject(T* aObject);
		void					Clear();

		const std::vector<T*>&	GetObjects() const;

	private:
		std::vector<T*>			myObjects;
	};

#pragma region DEFINITIONS

	template <typename T>
	void GridCell<T>::AddObject(T* aObject)
	{
		myObjects.push_back(aObject);
	}

	template <typename T>
	void GridCell<T>::RemoveObject(T* aObject)
	{
		myObjects.erase(std::remove(myObjects.begin(), myObjects.end(), aObject), myObjects.end());
	}

	template <typename T>
	void GridCell<T>::Clear()
	{
		myObjects.clear();
	}

	template <typename T>
	const std::vector<T*>& GridCell<T>::GetObjects() const
	{
		return myObjects;
	}

#pragma endregion DEFINITIONS
}