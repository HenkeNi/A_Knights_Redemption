#pragma once
#include "BinaryTreeNode.hpp"

namespace CommonUtilities
{
	template <class T>
	class BinaryTree
	{
	public:
		BinaryTree();
		~BinaryTree();

		const BinaryTreeNoe<T>* GetRoot()					const;
		bool					HasElement(const T& aData)	const;
		void					Insert(const T& aData);
		void					Remove(const T& aData);
		void					DSWBalance();

	};

#pragma region METHOD_DEFINITIONS



#pragma endregion METHOD_DEFINITIONS
}