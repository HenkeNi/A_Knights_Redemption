#pragma once
#include "BSTSetNode.hpp"

/* Set => value can only occure once */
/* Bineary Search Tree => all elements in the left subtree are smaller than parent */
/*  all elements larger than parent => in the right subtree */

namespace CommonUtilities
{
	template <class T>
	class BSTSet
	{
	public:
		BSTSet();
		~BSTSet();

		bool HasElement(const T& aValue);
		void Insert(const T& aValue);
		void Remove(const T& aValue);
		void Clear();

	private:


		BSTSetNode<T>* myRoot;
	};

#pragma region METHOD_DEFINITIONS
	
	template <class T>
	BSTSet<T>::BSTSet()
	{
	}

	template <class T>
	BSTSet<T>::~BSTSet()
	{
	}

	template <class T>
	bool BSTSet<T>::HasElement(const T& aValue)
	{

	}
	
	template <class T>
	void BSTSet<T>::Insert(const T& aValue)
	{

	}
	
	template <class T>
	void BSTSet<T>::Remove(const T& aValue)
	{

	}

	template <class T>
	void BSTSet<T>::Clear()
	{

	}


#pragma endregion METHOD_DEFINITIONS
}