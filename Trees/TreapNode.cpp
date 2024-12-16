#include <cstdlib>
#include "TreapNode.h"

TreapNode* NewNode(int key) 
{
    TreapNode* node = new TreapNode();
    node->Key = key;
    node->Priority = rand(); 
    node->Left = nullptr;
    node->Right = nullptr;
    return node;
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right) 
{
	if (node == nullptr) 
	{
		left = right = nullptr;
        return;
	}

	else if (node->Key < key) 
	{
		left = node;
		Split(node->Right, key, left->Right, right);
	}

	else 
	{
		right = node;
		Split(node->Left, key, left, right->Left);
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right) 
{
	if (left == nullptr) 
	{
		return right;
	}

	if (right == nullptr) 
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
	    left->Right = Merge(left->Right, right);
	    return left;
	}
	else 
	{
	    right->Left = Merge(left, right->Left);
	    return right;
	}
}

void InsertUnoptimized(TreapNode*& root, int key) 
{
    TreapNode* newNode = NewNode(key);
    TreapNode* left;
    TreapNode* right;

    Split(root, key, left, right);

    root = Merge(Merge(left, newNode), right);
}

void InsertOptimized(TreapNode*& root, int key) 
{

    TreapNode* newNode = NewNode(key);
    TreapNode* current = root;
    TreapNode* parent = nullptr;

    while (current != nullptr && current->Priority > newNode->Priority) 
    {
        parent = current;

        if (key < current->Key) 
        {
            current = current->Left;
        }
        else 
        {
            current = current->Right;
        }
    }

    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    Split(current, key, left, right);

    newNode->Left = left;
    newNode->Right = right;

    if (parent == nullptr) 
    {
        root = newNode;
    }
    else if (key < parent->Key)
    {
        parent->Left = newNode;
    }
    else
    {
        parent->Right = newNode;
    }
}



void RemoveUnoptimized(TreapNode*& node, int key) 
{
    if (node == nullptr)
    {
        return;
    }

    TreapNode* left;
    TreapNode* middle;
    TreapNode* right;

    Split(node, key, left, middle);

    Split(middle, key + 1, middle, right);

    if (middle) 
    {
        delete middle;
      
        node = Merge(left, right);
    }
    else 
    {
        node = Merge(left, middle); 
    }
}

void RemoveOptimized(TreapNode*& node, int key) 
{
    if (node == nullptr)
    {
        return;
    }

    if (node->Key == key)
    {
        TreapNode* oldNode = node;
        node = Merge(node->Left, node->Right);
        delete oldNode;
    }
    else if (key < node->Key)
    {
        RemoveOptimized(node->Left, key);
    }
    else 
    {
        RemoveOptimized(node->Right, key);
    }
}

TreapNode* Search(TreapNode* node, int key)
{
    if (!node || node->Key == key)
    {
        return node;
    }
    if (key < node->Key)
    {
        return Search(node->Left, key);
    }
    return Search(node->Right, key);
}

void Clear(TreapNode*& node) 
{
    if (!node) 
    {
        return;
    }
    Clear(node->Left);
    Clear(node->Right);
    delete node;
    node = nullptr;
}

