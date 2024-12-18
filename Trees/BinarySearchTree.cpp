////#include "BinarySearchTree.h"
//
//struct BinaryTreeNode
//{
//	///< The data stored in the node.
//	int Data;
//
//	///< Pointer to the left child node.
//	BinaryTreeNode* Left;
//
//	///< Pointer to the right child node.
//	BinaryTreeNode* Right;
//};
//
//
//BinaryTreeNode* CreateNode(int data)
//{
//	BinaryTreeNode* node = new BinaryTreeNode();
//	node->Data = data;
//	node->Left = nullptr;
//	node->Right = nullptr;
//	return node;
//}
//
//struct BinarySearchTree
//{
//	///< Pointer to the root node of the binary search tree.
//	BinaryTreeNode* Root;
//};
//
//BinarySearchTree* CreateTree() 
//{
//	BinarySearchTree* binaryTree = new BinarySearchTree();
//	binaryTree->Root = nullptr;
//	return binaryTree;
//}
//
//void Insert(BinarySearchTree* binaryTree, int data) 
//{
//	if (binaryTree->Root == nullptr) 
//	{
//		binaryTree->Root = CreateNode(data);
//		return;
//	}
//
//	BinaryTreeNode* current = binaryTree->Root;
//	BinaryTreeNode* parent = nullptr;
//
//	while (current != nullptr) 
//	{
//		parent = current;
//		if (data < current->Data) 
//		{
//			current = current->Left;
//		}
//		else 
//		{
//			current = current->Right;
//		}
//	}
//
//	if (data < parent->Data) 
//	{
//		parent->Left = CreateNode(data);
//	}
//	else 
//	{
//		parent->Right = CreateNode(data);
//	}
//}
//
//BinaryTreeNode* Search(BinarySearchTree* binaryTree, int data)
//{
//	if (binaryTree == nullptr || binaryTree->Root == nullptr)
//	{
//		return nullptr;
//	}
//
//	BinaryTreeNode* current = binaryTree->Root;
//
//	while (current != nullptr)
//	{
//		if (current->Data == data)
//		{
//			return current;
//		}
//		else if (data < current->Data)
//		{
//			current = current->Left; 
//		}
//		else
//		{
//			current = current->Right; 
//		}
//	}
//
//	return nullptr; 
//}
//
//BinaryTreeNode* FindMaxValue(BinarySearchTree* binaryTree)
//{
//	if (binaryTree == nullptr || binaryTree->Root == nullptr)
//	{
//		return nullptr;
//	}
//
//	BinaryTreeNode* current = binaryTree->Root;
//	while (current->Right != nullptr)
//	{
//		current = current->Right;
//	}
//
//	return current;
//}
//
//BinaryTreeNode* FindMinValue(BinaryTreeNode* node)
//{
//	if (node == nullptr)
//	{
//		return nullptr;
//	}
//	while (node->Left != nullptr)
//	{
//		node = node->Left;
//	}
//	return node;
//}
//
////TODO: либо сделать хайп с подменой и бесполезным деревом либо оставить ноду
//BinaryTreeNode* DeleteNode(BinaryTreeNode* node, int data)
//{
//	if (node == nullptr)
//	{
//		return nullptr;
//	}
//	if (data < node->Data)
//	{
//		node->Left = DeleteNode(node->Left, data);
//	}
//	else if (data > node->Data)
//	{
//		node->Right = DeleteNode(node->Right, data);
//	}
//	else
//	{
//		if (node->Left == nullptr)
//		{
//			BinaryTreeNode* temp = node->Right;
//			delete node;
//			return temp;
//		}
//		else if (node->Right == nullptr)
//		{
//			BinaryTreeNode* temp = node->Left;
//			delete node;
//			return temp;
//		}
//		BinaryTreeNode* temp = FindMinValue(node->Right);
//		node->Data = temp->Data;
//		node->Right = DeleteNode(node->Right, temp->Data);
//	}
//	return node;
//}
//
//void ClearTree(BinarySearchTree* binaryTree)
//{
//	if (binaryTree == nullptr)
//	{
//		return;
//	}
//
//	ClearTree(binaryTree);
//	ClearTree(binaryTree);
//
//	delete binaryTree;
//}


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
    if (binaryTree == nullptr || binaryTree->Root == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode* current = binaryTree->Root;

    while (current != nullptr)
    {
        if (current->Data == data)
        {
            return current; 
        }
        else if (data < current->Data)
        {
            current = current->Left;
        }
        else
        {
            current = current->Right;
        }
    }

    return nullptr; 
}


BinarySearchTree* FindMaxValue(BinarySearchTree* binaryTree)
{
    if (binaryTree == nullptr || binaryTree->Root == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode* current = binaryTree->Root;
    while (current->Right != nullptr)
    {
        current = current->Right;
    }

    BinarySearchTree* maxValueTree = CreateTree();
    maxValueTree->Root = current; 
    return maxValueTree;
}

BinarySearchTree* FindMinValue(BinarySearchTree* binaryTree)
{
    if (binaryTree == nullptr || binaryTree->Root == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode* current = binaryTree->Root;
    while (current->Left != nullptr)
    {
        current = current->Left;
    }

    BinarySearchTree* minValueTree = CreateTree();
    minValueTree->Root = current; 
    return minValueTree;
}

BinarySearchTree* DeleteNode(BinarySearchTree* binaryTree, int data)
{
    if (binaryTree == nullptr)
    {
        return nullptr;
    }

    binaryTree->Root = DeleteNodeHelper(binaryTree->Root, data);

    if (binaryTree->Root == nullptr) 
    {
        delete binaryTree; 
        return nullptr;
    }

    return binaryTree;
}

BinaryTreeNode* DeleteNodeHelper(BinaryTreeNode* node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (data < node->Data)
    {
        node->Left = DeleteNodeHelper(node->Left, data);
    }
    else if (data > node->Data)
    {
        node->Right = DeleteNodeHelper(node->Right, data);
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

        BinaryTreeNode* temp = FindMinValueHelper(node->Right);
        node->Data = temp->Data;
        node->Right = DeleteNodeHelper(node->Right, temp->Data);
    }

    return node;
}

BinaryTreeNode* FindMinValueHelper(BinaryTreeNode* node)
{
    while (node && node->Left != nullptr)
    {
        node = node->Left;
    }

    return node;
}

void ClearTree(BinarySearchTree* binaryTree)
{
    if (binaryTree == nullptr)
    {
        return;
    }

    ClearNodes(binaryTree->Root);

    delete binaryTree; 
}

void ClearNodes(BinaryTreeNode* node)
{
    if (node != nullptr)
    {
        ClearNodes(node->Left);
        ClearNodes(node->Right);
        delete node; 
    }
}
