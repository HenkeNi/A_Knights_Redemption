#pragma once

namespace CommonUtilities
{
	template <class T>
	class SinglyLinkedList; 

	template <class T>
	class SinglyLinkedListNode
	{
	public:
		SinglyLinkedListNode(const SinglyLinkedListNode&)				= delete;
		SinglyLinkedListNode& operator=(const SinglyLinkedListNode&)	= delete;

		T&						GetValue();
		const T&				GetValue()								   const;
		SinglyLinkedListNode&	GetNext()								   const;

	private:
		friend class SinglyLinkedList<T>;

		SinglyLinkedListNode(const T& aValue);
		~SinglyLinkedListNode();

		/* - Members - */
		T						myData;
		SinglyLinkedListNode*	myNextNode;
	};

#pragma region METHOD_DEFINITIONS

	template <class T>
	SinglyLinkedListNode<T>::SinglyLinkedListNode(const T& aValue)
		: myData{ aValue }, myNextNode{ nullptr }
	{
	}
	
	template <class T>
	SinglyLinkedListNode<T>::~SinglyLinkedListNode()
	{
	}

	template <class T>
	T& SinglyLinkedListNode<T>::GetValue()
	{
		return myData;
	}
	
	template <class T>
	const T& SinglyLinkedListNode<T>::GetValue()					const
	{
		return myData;
	}
	
	template <class T>
	SinglyLinkedListNode<T>& SinglyLinkedListNode<T>::GetNext()		const
	{
		return myNextNode;
	}

#pragma endregion METHOD_DEFINITIONS
}