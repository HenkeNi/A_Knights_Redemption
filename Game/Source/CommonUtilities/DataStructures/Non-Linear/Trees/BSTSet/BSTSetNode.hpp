#pragma once

namespace CommonUtilities
{
	template <class T>
	struct BSTSetNode
	{
		BSTSetNode(T someData)
			: myData{ someData }, myLeftChild{ nullptr }, myRightChild{ nullptr }
		{
		}

		T			myData;
		BSTSetNode* myLeftChild;
		BSTSetNode* myRightChild;
	};
}