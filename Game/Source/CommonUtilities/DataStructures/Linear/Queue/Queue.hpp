#pragma once
#include <cassert>

namespace CommonUtilities
{
	template <class T, bool Static = true, typename SizeType = unsigned int>
	class Queue
	{
	public:
		Queue(const SizeType aCapacity = 32);
		~Queue();

		void		Enqueue(const T& aValue);
		T			Dequeue();

		SizeType	GetCapacity()	const;
		SizeType	GetSize()		const;
		const T&	GetFront()		const;
		T&			GetFront();

		bool		IsEmpty()		const;
		bool		IsFull()		const;
		void		Resize(const SizeType aCapacity);
		void		Clear();

	private:
		T*			myData;
		SizeType	myCapacity;
		SizeType	mySize;
		int			myFrontIndex;
		int			myBackIndex;			
	};

#pragma region METHOD_DEFINITIONS

	template <class T, bool Static, typename SizeType>
	Queue<T, Static, SizeType>::Queue(const SizeType aCapacity)
		: myData{ new T[aCapacity] }, myCapacity{ aCapacity }, mySize{ 0 }, myFrontIndex{ -1 }, myBackIndex{ -1 }
	{
	}

	template <class T, bool Static, typename SizeType>
	Queue<T, Static, SizeType>::~Queue()
	{
		delete[] myData;
	}

	template <class T, bool Static, typename SizeType>
	void Queue<T, Static, SizeType>::Enqueue(const T& aValue)
	{
		if (IsFull())
		{
			if (Static)
				assert(false && "Queue is full");
			else
				Resize(myCapacity * 2);
		}

		if (IsEmpty())
		{
			myFrontIndex = 0;
		}

		myBackIndex = myBackIndex + 1 % myCapacity;
		myData[myBackIndex] = aValue;
			
		++mySize;
	}
	
	template <class T, bool Static, typename SizeType>
	T Queue<T, Static, SizeType>::Dequeue()
	{
		assert(!IsEmpty());

		T element = myData[myFrontIndex];
		
		if (myFrontIndex == myBackIndex)
		{
			myBackIndex = myFrontIndex = -1;
		}
		else
		{
			myFrontIndex = (myFrontIndex + 1) % myCapacity;
		}

		--mySize;
		return element;
	}

	template <class T, bool Static, typename SizeType>
	SizeType Queue<T, Static, SizeType>::GetCapacity()	const
	{
		return myCapacity;
	}

	template <class T, bool Static, typename SizeType>
	SizeType Queue<T, Static, SizeType>::GetSize()		const
	{
		return mySize; 
	}

	template <class T, bool Static, typename SizeType>
	const T& Queue<T, Static, SizeType>::GetFront()		const
	{
		assert(!IsEmpty() && "Can't access front of empty Queue");

		return myData[myFrontIndex];
	}

	template <class T, bool Static, typename SizeType>
	T& Queue<T, Static, SizeType>::GetFront()
	{
		assert(!IsEmpty() && "Can't access front of empty Queue");

		return myData[myFrontIndex];
	}
	
	template <class T, bool Static, typename SizeType>
	bool Queue<T, Static, SizeType>::IsEmpty()			const
	{
		return myFrontIndex == -1;
	}
	
	template <class T, bool Static, typename SizeType>
	bool Queue<T, Static, SizeType>::IsFull()			const
	{
		return (myFrontIndex == 0 && myBackIndex == myCapacity - 1) || (myFrontIndex == myBackIndex + 1);
	}

	template <class T, bool Static, typename SizeType>
	void Queue<T, Static, SizeType>::Resize(const SizeType aCapacity)
	{
		assert(!Static && "Queue is not a dynamic structure!");

		T* temp = new T[aCapacity];
		for (int i = myFrontIndex; i <= myBackIndex; ++i)
		{
			temp[i] = myData[i];
		}

		delete[] myData;
		myData = temp;

		myCapacity = aCapacity;
	}

	template <class T, bool Static, typename SizeType>
	void Queue<T, Static, SizeType>::Clear()
	{
		myBackIndex = myFrontIndex = -1;
		mySize = 0;
	}

#pragma endregion METHOD_DEFINITIONS
}