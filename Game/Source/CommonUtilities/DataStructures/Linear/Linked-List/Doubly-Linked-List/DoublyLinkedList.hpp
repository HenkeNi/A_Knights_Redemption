#pragma once
#include "DoublyLinkedListNode.hpp"
#include <cassert>

namespace CommonUtilities
{
	template <class T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
	
		DoublyLinkedListNode<T>*	FindFirst(const T& aValue);
		DoublyLinkedListNode<T>*	FindLast(const T& aValue);
		DoublyLinkedListNode<T>*	GetFirst();
		DoublyLinkedListNode<T>*	GetLast();

		int							GetSize()									const;	
		void						PrintList(bool aForwardDirection = true)	const;
		void						ClearList();
		void						InsertFirst(const T& aValue);
		void						InsertLast(const T& aValue);
		void						InsertBefore(DoublyLinkedListNode<T>* aNode, const T& aValue);
		void						InsertAfter(DoublyLinkedListNode<T>* aNode, const T& aValue);

		void						Remove(DoublyLinkedListNode<T>* aNode);
		bool						RemoveFirst(const T& aValue);
		bool						RemoveLast(const T& aValue);

	private:
		DoublyLinkedListNode<T>		myHead;
		DoublyLinkedListNode<T>		myTail;
		int							mySize;
	};

#pragma region METHOD_DEFINITIONS

	template <class T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: myHead{ nullptr }, myTail{ nullptr }, mySize{ 0 }
	{
	}

	template <class T>
	DoublyLinkedList<T>::~DoublyLinkedList()
	{
		ClearList();
	}

	template <class T>
	DoublyLinkedListNode<T>* DoublyLinkedList<T>::FindFirst(const T& aValue)
	{
		auto* traverser = myHead;
		while (traverser != nullptr)
		{
			if (traverser->myData == aValue)
			{
				return traverser;
			}
			traverser = traverser->myNextNode;
		}

		return nullptr;
	}
	
	template <class T>
	DoublyLinkedListNode<T>* DoublyLinkedList<T>::FindLast(const T& aValue)
	{
		auto* traverser = myTail;
		while (traverser != nullptr)
		{
			if (traverser->myData == aValue)
			{
				return traverser;
			}
			traverser = traverser->myPreviousNode;
		}
		return nullptr;
	}
	
	template <class T>
	DoublyLinkedListNode<T>* DoublyLinkedList<T>::GetFirst()
	{
		return myHead;
	}
	
	template <class T>
	DoublyLinkedListNode<T>* DoublyLinkedList<T>::GetLast()
	{
		return myTail;
	}

	template <class T>
	int DoublyLinkedList<T>::GetSize()   const
	{
		return mySize;
	}

	template <class T>
	void DoublyLinkedList<T>::PrintList(bool aForwardDirection)	const
	{
		auto* traverser = aForwardDirection ? myHead : myTail;
		while (traverser != nullptr)
		{
			std::cout << traverser->myData << '\n';
			traverser = aForwardDirection ? traverser->myNextNode : traverser->myPreviousNode;
		}
	}

	template <class T>
	void DoublyLinkedList<T>::ClearList()
	{
		while (myHead != nullptr)
		{
			auto* temp = myHead;
			myHead = myHead->myNextNode;

			delete temp;
		}
		mySize = 0;
	}

	template <class T>
	void DoublyLinkedList<T>::InsertFirst(const T& aValue)
	{
		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		newNode->myNextNode = myHead;

		if (myHead != nullptr)
		{
			myHead->myPreviousNode = newNode;
		}
		else
		{
			myTail = newNode;
		}

		myHead = newNode;
		++mySize;
	}

	template <class T>
	void DoublyLinkedList<T>::InsertLast(const T& aValue)
	{
		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		newNode->myPreviousNode = myTail;

		if (myHead == nullptr)
		{
			myHead = newNode;
		}
		else
		{
			myTail->myNextNode = newNode;
		}

		myTail = newNode;
		++mySize;
	}

	template <class T>
	void DoublyLinkedList<T>::InsertBefore(DoublyLinkedListNode<T>* aNode, const T& aValue)
	{
		assert(aNode);

		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		auto* previousNode = aNode->myPreviousNode;

		if (previousNode == nullptr)
		{
			myHead = newNode;
		}
		else
		{
			previousNode->myNextNode = newNode;
			newNode->myPreviousNode = previousNode;
		}

		newNode->myNextNode = aNode;
		aNode->myPreviousNode = newNode;

		++mySize;
	}

	template <class T>
	void DoublyLinkedList<T>::InsertAfter(DoublyLinkedListNode<T>* aNode, const T& aValue)
	{
		assert(aNode);

		auto* newNode = new DoublyLinkedListNode<T>(aValue);
		auto* nextNode = aNode->myNextNode;

		if (nextNode == nullptr)
		{
			myTail = newNode;
		}
		else
		{
			newNode->myNextNode = nextNode;
			nextNode->myPreviousNode = newNode;

		}

		aNode->myNextNode = newNode;
		newNode->myPreviousNode = aNode;
		++mySize;
	}

	template <class T>
	void DoublyLinkedList<T>::Remove(DoublyLinkedListNode<T>* aNode)
	{
		assert(aNode);

		auto* previousNode = aNode->myPreviousNode;
		auto* nextNode = aNode->myNextNode;

		if (previousNode == nullptr)
		{
			myHead = aNode->myNextNode;
		}
		else
		{
			previousNode->myNextNode = nextNode;
		}

		if (nextNode == nullptr)
		{
			myTail = aNode->myPreviousNode;
		}
		else
		{
			nextNode->myPreviousNode = previousNode;
		}

		delete aNode;
		--mySize;
	}
		
	template <class T>
	bool DoublyLinkedList<T>::RemoveFirst(const T& aValue)
	{
		auto* node = FindFirst(aValue);
		if (node)
		{
			auto* previous = node->myPreviousNode;
			auto* next = node->myNextNode;

			if (previous == nullptr)
			{
				myHead = next;
			}
			else
			{
				previous->myNextNode = next;
			}

			if (next == nullptr)
			{
				myTail = previous;
			}
			else
			{
				next->myPreviousNode = previous;
			}

			delete node;
			--mySize;

			return true;
		}
		return false;
	}

	template <class T>
	bool DoublyLinkedList<T>::RemoveLast(const T& aValue)
	{
		auto* node = FindLast(aValue);
		if (node)
		{
			auto* previous = node->myPreviousNode;
			auto* next = node->myNextNode;

			if (previous == nullptr)
			{
				myHead = next;
			}
			else
			{
				previous->myNextNode = next;
			}
			if (next == nullptr)
			{
				myTail = previous;
			}
			else
			{
				next->myPreviousNode = previous;
			}

			delete node;

			--mySize;
			return true;
		}
		return false;
	}

#pragma endregion METHOD_DEFINITIONS
}