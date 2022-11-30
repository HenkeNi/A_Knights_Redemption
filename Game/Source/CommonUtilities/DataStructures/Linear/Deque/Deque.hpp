#pragma once

namespace CommonUtilities
{
	template <class T, bool Resizeable = true, typename SizeType = unsigned int>
	class Deque
	{
	public:
		Deque(const SizeType aCapacity = 32);
		~Deque();

		void		Resize();
		void		PushBack(const T& someData);
		void		PushFront(const T& someData);
		void		PopFront(); // return element?
		void		PopBack();

		T			Front();
		const T&	Front()			const;
		T			Back();
		const T&	Back()			const;

		int			GetCapacity()	const;
		int			GetSize()		const;
		bool		IsEmpty()		const;
		bool		IsFull()		const;

	private:
		T*			myData;
		SizeType	myCapacity;
		SizeType	mySize;
		int			myFrontIndex;
		int			myBackIndex;
	};

#pragma region METHOD_DEFINITIONS

	template <class T, bool Resizeable, typename SizeType>
	Deque<T, Resizeable, SizeType>::Deque(const SizeType aCapacity)
		: myData{ new T[aCapacity] }, myCapacity{ aCapacity }, mySize{ 0 }, myFrontIndex{ -1 }, myBackIndex{ -1 }
	{
	}

	template <class T, bool Resizeable, typename SizeType>
	Deque<T, Resizeable, SizeType>::~Deque()
	{

	}

	template <class T, bool Resizeable, typename SizeType>
	void Deque<T, Resizeable, SizeType>::Resize()
	{
		assert(Resizeable);

		myCapacity *= 2;

		T* temp = new T[myCapacity];

		// memcopy??


		int i = myFrontIndex;
		int j = 0;

		while (i != myBackIndex)
		{
			temp[j] = myData[i];
			i = (i + 1) % mySize;
			++j;
		}
		temp[j] = myData[i];
	}


	template <class T, bool Resizeable, typename SizeType>
	void Deque<T, Resizeable, SizeType>::PushBack(const T& someData)
	{
		if (IsFull() && Resizeable)
		{
			Resize();
		}
	}

	template <class T, bool Resizeable, typename SizeType>
	void Deque<T, Resizeable, SizeType>::PushFront(const T& someData)
	{

	}
	
	template <class T, bool Resizeable, typename SizeType>
	void Deque<T, Resizeable, SizeType>::PopFront()
	{

	}

	template <class T, bool Resizeable, typename SizeType>
	void Deque<T, Resizeable, SizeType>::PopBack()
	{

	}

	template <class T, bool Resizeable, typename SizeType>
	T Deque<T, Resizeable, SizeType>::Front()
	{
		assert(!IsEmpty());
		return myData[myFrontIndex];
	}

	template <class T, bool Resizeable, typename SizeType>
	const T& Deque<T, Resizeable, SizeType>::Front()	const
	{
		assert(!IsEmpty());
		return myData[myFrontIndex];
	}

	template <class T, bool Resizeable, typename SizeType>
	T Deque<T, Resizeable, SizeType>::Back()
	{
		assert(!IsEmpty());
		return myData[myBackIndex];
	}

	template <class T, bool Resizeable, typename SizeType>
	const T& Deque<T, Resizeable, SizeType>::Back()		const
	{
		assert(!IsEmpty());
		return myData[myBackIndex];
	}

	template <class T, bool Resizeable, typename SizeType>
	int Deque<T, Resizeable, SizeType>::GetCapacity()	const
	{
		return myCapacity;
	}

	template <class T, bool Resizeable, typename SizeType>
	int Deque<T, Resizeable, SizeType>::GetSize()		const
	{
		return mySize;
	}

	template <class T, bool Resizeable, typename SizeType>
	bool Deque<T, Resizeable, SizeType>::IsEmpty()		const
	{
		return myFrontIndex == -1 && myBackIndex == -1;
		//return mySize == 0;
	}

	template <class T, bool Resizeable, typename SizeType>
	bool Deque<T, Resizeable, SizeType>::IsFull()		const
	{
		return mySize == myCapacity;
	}

#pragma endregion METHOD_DEFINITIONS
}