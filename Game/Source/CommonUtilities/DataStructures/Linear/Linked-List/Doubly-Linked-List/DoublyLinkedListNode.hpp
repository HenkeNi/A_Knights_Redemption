#pragma once

namespace CommonUtilities
{
	template <class T>
	class DoublyLinkedList;

	template <class T>
	class DoublyLinkedListNode
	{
	public:
		DoublyLinkedListNode(const DoublyLinkedListNode&)				= delete;
		DoublyLinkedListNode& operator=(const DoublyLinkedListNode&)	= delete;

		T&						GetValue();
		const T&				GetValue()		const;
		DoublyLinkedListNode*	GetNext()		const;
		DoublyLinkedListNode*	GetPrevious()	const;

	private:
		friend class DoublyLinkedList<T>;

		DoublyLinkedListNode(const T& aValue);
		~DoublyLinkedListNode();

		/* - Members - */
		T						myData;
		DoublyLinkedListNode*	myNextNode;
		DoublyLinkedListNode*	myPreviousNode;
	};

#pragma region METHOD_DEFINITIONS

	template <class T>
	DoublyLinkedListNode<T>::DoublyLinkedListNode(const T& aValue)
		: myData{ aValue }, myNextNode{ nullptr }, myPreviousNode{ nullptr }
	{
	}

	template <class T>
	DoublyLinkedListNode<T>::~DoublyLinkedListNode()
	{
	}

	template <class T>
	T& DoublyLinkedListNode<T>::GetValue()
	{
		return myData;
	}

	template <class T>
	const T& DoublyLinkedListNode<T>::GetValue() const
	{
		return myData;
	}


	template <class T>
	DoublyLinkedListNode<T>* DoublyLinkedListNode<T>::GetNext() const
	{
		return myNextNode;
	}

	template <class T>
	DoublyLinkedListNode<T>* DoublyLinkedListNode<T>::GetPrevious() const
	{
		return myPreviousNode;
	}

#pragma endregion METHOD_DEFINITIONS
}