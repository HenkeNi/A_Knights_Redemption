#pragma once
#include "GridCell.hpp"
#include "Math/Vectors/Vector.hpp"
#include <cassert>
#include <cmath>

namespace CommonUtilities
{
	template <typename T>
	class Grid
	{
	public:
		Grid();
		~Grid();

		void			Initialize(const Vector2<int>& aGridSize, const Vector2<int>& aCellSize);
		void			Render();
		void			AddObject(T* aObject);
		void			Resize(const Vector2<int>& aSize);
		void			Clear();
		
		std::vector<T*> GetCollidableObjects(const Vector2<int>& aPosition);
		
		// Const?
		GridCell<T>&	GetCell(const Vector2<float>& aPosition);
		GridCell<T>&	GetCell(int aRow, int aCol);

	private:
		std::vector<int> GetAdjacentCellIndexes(const Vector2<int>& aPosition) const;
		//std::vector<GridCell*> GetAdjacentCells(int aIndex) const;

		std::vector<GridCell<T>>	myCells;
		Vector2<int>				myGridSize; // TODO: add position?? don't always start at 0, 0! myOffset?
		Vector2<int>				myCellSize;

		Vector2<int>				myNumOfCells;
	};

#pragma region METHOD_DEFINITIONS

	template <typename T>
	Grid<T>::Grid()
	{
	}

	template <typename T>
	Grid<T>::~Grid()
	{
	}

	template <typename T>
	void Grid<T>::Initialize(const Vector2<int>& aGridSize, const Vector2<int>& aCellSize)
	{
		myGridSize = aGridSize;
		myCellSize = aCellSize;

		myNumOfCells.x = ceil((float)myGridSize.x / myCellSize.x);
		myNumOfCells.y = ceil((float)myGridSize.y / myCellSize.y);

		//myCells.resize(rowAmount * colAmount, nullptr);
		myCells.resize(myNumOfCells.x * myNumOfCells.y, nullptr);
	}

	template <typename T>
	void Grid<T>::Render()
	{

	}

	template <typename T>
	void Grid<T>::AddObject(T* aObject)
	{
		GridCell& cell = GetCell(aObject->GetPosition());
		cell.AddOjbect(aObject);
	}

	template <typename T>
	void Grid<T>::Resize(const Vector2<int>& aSize)
	{
		myGridSize = aSize;

		// Clear Grid?
	}


	template <typename T>
	void Grid<T>::Clear()
	{
		for (auto& cell : myCells)
		{
			cell.Clear();
		}
	}

	template <typename T>
	std::vector<T*> Grid<T>::GetCollidableObjects(const Vector2<int>& aPosition)
	{
		std::vector<T*> objects;
		for (auto& cell : GetAdjacentCellIndexes(aPosition))
		{
			auto cellObjects = cell.GetObjects();
			objects.insert(objects.end(), cellObjects.begin(), cellObjects.end());
		}
		return objects;
	}

	template <typename T>
	GridCell<T>& Grid<T>::GetCell(const Vector2<float>& aPosition)
	{
		assert(aPosition.x >= 0 && aPosition.y >= 0 && aPosition.x <= myGridSize.x && aPosition.y <= myGridSize.y);

		int row = floor(aPosition.x / myCellSize.x);
		int col = floor(aPosition.y / myCellSize.y); // TODO: Cast to int?

		return GetCell(row, col);
	}

	template <typename T>
	GridCell<T>& Grid<T>::GetCell(int aRow, int aCol)
	{
		assert(aRow >= 0 && aCol >= 0 && aRow <= myNumOfCells.x && aCol <= myNumOfCells.y); 

		return myCells[aRow + (aCol * myNumOfCells.x)];
	}

	template<typename T>
	
	//std::vector<int> Grid<T>::GetAdjacentCellIndexes(int aIndex) const // TAke in a Cell??
	std::vector<int> Grid<T>::GetAdjacentCellIndexes(const Vector2<int>& aPosition) const
	{
		//for (int x = aIndex)

		return {};
	}


	//template<typename T>
	//std::vector<GridCell<T>*> Grid<T>::GetAdjacentCells(int aIndex) const
	//{
	//	return std::vector<GridCell*>();
	//}



#pragma endregion METHOD_DEFINITIONS
}