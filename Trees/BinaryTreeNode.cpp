#include "BinaryTreeNode.h"

BinaryTreeNode* CreateNode(int data)
{
	BinaryTreeNode* node = new BinaryTreeNode();
	node->Data = data;
	node->Left = nullptr;
	node->Right = nullptr;
	return node;
}

BinaryTreeNode* Insert(BinaryTreeNode* node, int data)
{
	if (node == nullptr)
	{
		return CreateNode(data);
	}

	if (data < node->Data)
	{
		node->Left = Insert(node->Left, data);
	}

	if (data > node->Data)
	{
		node->Right = Insert(node->Right, data);
	}

	return node;
}

BinaryTreeNode* Search(BinaryTreeNode* node, int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Data == data)
	{
		return node;
	}

	if (data > node->Data)
	{
		return Search(node->Right, data);
	}

	else
	{
		return Search(node->Left, data);
	}
}

BinaryTreeNode* FindMaxValue(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}

BinaryTreeNode* FindMinValue(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}

BinaryTreeNode* DeleteNode(BinaryTreeNode* node, int data)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (data < node->Data)
	{
		node->Left = DeleteNode(node->Left, data);
	}

	else if (data > node->Data)
	{
		node->Right = DeleteNode(node->Right, data);
	}

	else
	{
		if (node->Left == nullptr)
		{
			BinaryTreeNode* temp = node->Right;
			delete node;
			return temp;
		}
		else if (node->Right == nullptr)
		{
			BinaryTreeNode* temp = node->Left;
			delete node;
			return temp;
		}

		BinaryTreeNode* temp = FindMinValue(node->Right);

		node->Data = temp->Data;

		node->Right = DeleteNode(node->Right, temp->Data);
	}
	return node;
}

void ClearTree(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	ClearTree(node->Left);
	ClearTree(node->Right);

	delete node;
}
