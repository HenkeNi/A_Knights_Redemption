#pragma once
#include <cassert>

// TODO: Combine MinHeap and MaxHeap? - just change in Heapify
// TODO: Debug function -> prints the tree (is balanced?? - or doesn't need to be since using array??)
namespace CommonUtilities
{
	template <class T, bool Static = true, typename SizeType = unsigned int>
	class MinHeap
	{
	public:
		MinHeap(const SizeType aCapacity = 16);
		~MinHeap();

		const T&	GetTop()					const;
		int			GetSize()					const;
		bool		IsEmpty()					const;
		bool		IsFull()					const;
		void		Enqueue(const T& aElement);
		T			Dequeue();
		void		RemoveCyclic(const T& aObject);
		void		RemoveCyclicAtIndnex(const SizeType aIndex);
		void		Resize(const SizeType aCapacity);

	private:
		/* - Methods - */
		int			Parent(int aIndex)			const;
		int			LeftChild(int aIndex)		const;
		int			RightChild(int aIndex)		const;
		void		HeapifyDown(int aIndex);
		void		HeapifyUp(int aIndex);

		/* - Members - */
		T*			myData;
		SizeType	myCapacity;
		SizeType	mySize;
	};

#pragma region METHOD_DEFINITIONS

	template <class T, bool Static, typename SizeType>
	MinHeap<T, Static, SizeType>::MinHeap(const SizeType aCapacity)
		: myData{ new T[aCapacity] }, myCapacity{ aCapacity }, mySize{ 0 }
	{
	}

	template <class T, bool Static, typename SizeType>
	MinHeap<T, Static, SizeType>::~MinHeap()
	{
		delete[] myData;
	}

	template <class T, bool Static, typename SizeType>
	const T& MinHeap<T, Static, SizeType>::GetTop()				const
	{
		return myData[0];
	}
	
	template <class T, bool Static, typename SizeType>
	int	MinHeap<T, Static, SizeType>::GetSize()					const
	{
		return mySize;
	}
	
	template <class T, bool Static, typename SizeType>
	bool MinHeap<T, Static, SizeType>::IsEmpty()				const
	{
		return mySize == 0;
	}

	template <class T, bool Static, typename SizeType>
	bool MinHeap<T, Static, SizeType>::IsFull()					const
	{
		return mySize == myCapacity;
	}
	
	template <class T, bool Static, typename SizeType>
	void MinHeap<T, Static, SizeType>::Enqueue(const T& aElement)
	{
		if (IsFull())
		{
			if (Static)
				assert(false && "MinHeap is full");
			else
				Resize(myCapacity * 2);
		}

		myData[mySize] = aElement;
		int index = mySize++;

		HeapifyUp(index);
	}
	
	template <class T, bool Static, typename SizeType>
	T MinHeap<T, Static, SizeType>::Dequeue()
	{
		assert(!IsEmpty());

		T minElement = GetTop();

		RemoveCyclicAtIndnex(0);
		HeapifyDown(0);

		return minElement;
	}

	template <class T, bool Static, typename SizeType>
	void MinHeap<T, Static, SizeType>::RemoveCyclic(const T& aObject)
	{
		int index = -1;
		for (int i = 0; i < mySize; ++i)
		{
			if (myData[i] == aObject)
			{
				index = i;
				break;
			}
		}

		if (index != -1)
			myData[index] = myData[--mySize];
	}

	template <class T, bool Static, typename SizeType>
	void MinHeap<T, Static, SizeType>::RemoveCyclicAtIndnex(const SizeType aIndex)
	{
		assert(aIndex >= 0 && aIndex < mySize);
		myData[aIndex] = myData[--mySize];
	}

	template <class T, bool Static, typename SizeType>
	void MinHeap<T, Static, SizeType>::Resize(const SizeType aCapacity)
	{
		assert(!Static && "MinHeap is not a dynamic structure!");

		T* temp = new T[aCapacity];
		for (int i = 0; i < mySize; ++i)
		{
			temp[i] = myData[i];
		}

		delete[] myData;
		myData = temp;

		myCapacity = aCapacity;
	}

	template <class T, bool Static, typename SizeType>
	int MinHeap<T, Static, SizeType>::Parent(int aIndex)		const
	{
		return (aIndex - 1) / 2;
	}

	template <class T, bool Static, typename SizeType>
	int MinHeap<T, Static, SizeType>::LeftChild(int aIndex)		const
	{
		return (aIndex * 2) + 1;
	}
	
	template <class T, bool Static, typename SizeType>
	int MinHeap<T, Static, SizeType>::RightChild(int aIndex)	const
	{
		return (aIndex * 2) + 2;
	}

	template <class T, bool Static, typename SizeType>
	void MinHeap<T, Static, SizeType>::HeapifyDown(int aIndex)
	{
		int leftChild	= LeftChild(aIndex);
		int rightChild	= RightChild(aIndex);

		int smallest = aIndex;

		if (leftChild < mySize && myData[leftChild] < myData[smallest])
		{
			smallest = leftChild;
		}
		if (rightChild < mySize && myData[rightChild] < myData[smallest])
		{
			smallest = rightChild;
		}

		if (smallest != aIndex)
		{
			std::swap(myData[aIndex], myData[smallest]);
			HeapifyDown(smallest);
		}
	}

	template <class T, bool Static, typename SizeType>
	void MinHeap<T, Static, SizeType>::HeapifyUp(int aIndex)
	{
		if (aIndex >= 0 && myData[aIndex] < myData[Parent(aIndex)])
		{
			std::swap(myData[aIndex], myData[Parent(aIndex)]);
			HeapifyUp(Parent(aIndex));
		}
	}

#pragma endregion METHOD_DEFINITIONS
}