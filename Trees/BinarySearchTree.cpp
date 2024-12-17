#include "BinarySearchTree.h"

BinarySearchTree* CreateTree() 
{
	BinarySearchTree* binaryTree = new BinarySearchTree();
	binaryTree->Root = nullptr;
	return binaryTree;
}

void Insert(BinarySearchTree* binaryTree, int data) 
{
	if (binaryTree->Root == nullptr) 
	{
		binaryTree->Root = CreateNode(data);
		return;
	}

	BinaryTreeNode* current = binaryTree->Root;
	BinaryTreeNode* parent = nullptr;

	while (current != nullptr) 
	{
		parent = current;
		if (data < current->Data) 
		{
			current = current->Left;
		}
		else 
		{
			current = current->Right;
		}
	}

	if (data < parent->Data) 
	{
		parent->Left = CreateNode(data);
	}
	else 
	{
		parent->Right = CreateNode(data);
	}
}

BinaryTreeNode* Search(BinarySearchTree* binaryTree, int data)
{
	if (binaryTree == nullptr)
	{
		return nullptr;
	}

	if (binaryTree->Root->Data == data)
	{
		return binaryTree->Root;
	}

	if (data > binaryTree->Root->Data)
	{
		return Search(binaryTree, data);
	}

	else
	{
		return Search(binaryTree, data);
	}
}

BinaryTreeNode* FindMaxValue(BinarySearchTree* binaryTree)
{
	if (binaryTree == nullptr)
	{
		return nullptr;
	}

	while (binaryTree->Root->Right != nullptr)
	{
		binaryTree->Root = binaryTree->Root->Right;
	}

	return binaryTree->Root;
}

BinaryTreeNode* FindMinValue(BinarySearchTree* binaryTree)
{
	if (binaryTree == nullptr)
	{
		return nullptr;
	}

	while (binaryTree->Root->Left != nullptr)
	{
		binaryTree->Root = binaryTree->Root->Left;
	}

	return binaryTree->Root;
}

BinaryTreeNode* DeleteNode(BinarySearchTree* binaryTree, int data)
{
	if (binaryTree == nullptr)
	{
		return nullptr;
	}

	if (data < binaryTree->Root->Data)
	{
		binaryTree->Root->Left = DeleteNode(binaryTree, data);
	}
	else if (data > binaryTree->Root->Data)
	{
		binaryTree->Root->Right = DeleteNode(binaryTree, data);
	}

	else
	{
		if (binaryTree->Root->Left == nullptr)
		{
			BinaryTreeNode* temp = binaryTree->Root->Right;
			delete binaryTree;
			return temp;
		}
		else if (binaryTree->Root->Right == nullptr)
		{
			BinaryTreeNode* temp = binaryTree->Root->Left;
			delete binaryTree;
			return temp;
		}

		BinaryTreeNode* temp = FindMinValue(binaryTree);

		binaryTree->Root->Data = temp->Data;

		binaryTree->Root->Right = DeleteNode(binaryTree, temp->Data);
	}
	return binaryTree->Root;
}

void ClearTree(BinarySearchTree* binaryTree)
{
	if (binaryTree == nullptr)
	{
		return;
	}

	ClearTree(binaryTree);
	ClearTree(binaryTree);

	delete binaryTree;
}
