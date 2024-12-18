#include "Treap.h"
#include <stdlib.h>

Treap* CreateTreap()
{
    Treap* treap = new Treap();
    treap->Root = nullptr;
    return treap;
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
    if (node == nullptr)
    {
        left = right = nullptr;
    }
    else if (node->Key <= key)
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


Treap* InsertUnoptimized(Treap* treap, int key)
{
    TreapNode* newNode = NewNode(key);
    if (treap->Root == nullptr)
    {
        treap->Root = newNode;
        return treap;
    }

    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    Split(treap->Root, key, left, right);
    treap->Root = Merge(Merge(left, newNode), right);

    return treap;
}


Treap* InsertOptimized(Treap* treap, int key)
{
    TreapNode* newNode = NewNode(key);
    if (treap->Root == nullptr)
    {
        treap->Root = newNode;
        return treap;
    }

    if (newNode->Priority > treap->Root->Priority)
    {
        TreapNode* left = nullptr;
        TreapNode* right = nullptr;
        Split(treap->Root, key, left, right);

        newNode->Left = left;
        newNode->Right = right;
        treap->Root = newNode;
        return treap;
    }

    TreapNode* current = treap->Root;
    TreapNode* parent = nullptr;

    while (current != nullptr)
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

    if (key < parent->Key)
    {
        parent->Left = InsertOptimized(new Treap{ parent->Left }, key)->Root;
    }
    else
    {
        parent->Right = InsertOptimized(new Treap{ parent->Right }, key)->Root; 
    }

    return treap;
}



Treap* RemoveUnoptimized(Treap* treap, int key)
{
    if (treap->Root == nullptr)
    {
        return treap;
    }

    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    Split(treap->Root, key, left, right);

    TreapNode* midLeft = nullptr;
    TreapNode* midRight = nullptr;
    Split(left, key - 1, midLeft, midRight);

    delete midRight;
    treap->Root = Merge(midLeft, right);

    return treap;
}

Treap* RemoveOptimized(Treap* treap, int key)
{
    if (treap->Root == nullptr)
    {
        return treap;
    }

    TreapNode* current = treap->Root;
    TreapNode* parent = nullptr;

    while (current != nullptr && current->Key != key)
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

    if (current == nullptr)
    {
        return treap;
    }

    TreapNode* leftChild = current->Left;
    TreapNode* rightChild = current->Right;

    TreapNode* mergedChild = Merge(leftChild, rightChild);

    if (current == treap->Root)
    {
        treap->Root = mergedChild;
    }
    else 
    {
        if (parent->Left == current)
        {
            parent->Left = mergedChild;
        }
        else 
        {
            parent->Right = mergedChild;
        }
    }

    delete current;
    return treap;
}


TreapNode* Search(Treap* treap, int key)
{
    TreapNode* current = treap->Root;

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            return current;
        }
        else if (key < current->Key)
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

void ClearTreap(Treap*& treap)
{
    Clear(treap->Root);
    delete treap; 
}

