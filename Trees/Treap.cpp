#include "Treap.h"

Treap* CreateTreap()
{
    Treap* treap = new Treap();
    treap->Root = nullptr;
    return treap;
}

void Split(Treap* treap, int key, Treap*& left, Treap*& right) 
{
    if (treap->Root == nullptr) 
    {
        left = new Treap();
        right = new Treap();
        return;
    }

    if (treap->Root->Key < key)
    {
        left = new Treap();
        left->Root = treap->Root;
        Treap* tempRight;
        Split(new Treap{ treap->Root->Right }, key, left, tempRight); 
        right = tempRight; 
    }
    else
 {
        right = new Treap();
        right->Root = treap->Root;
        Treap* tempLeft;
        Split(new Treap{ treap->Root->Left }, key, tempLeft, right); 
        left = tempLeft; 
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
    else {
        right->Left = Merge(left, right->Left);
        return right;
    }
}

void InsertUnoptimized(Treap* treap, int key) 
{
    TreapNode* newNode = NewNode(key);
    Treap* left = new Treap();
    Treap* right = new Treap();

    Split(treap, key, left, right);

    treap->Root = Merge(Merge(left->Root, newNode), right->Root);
}

void InsertOptimized(Treap* treap, int key) {
    TreapNode* newNode = NewNode(key);
    if (treap->Root == nullptr) {
        treap->Root = newNode;
        return;
    }

    Treap* left = nullptr;
    Treap* right = nullptr;

    // Разделяем дерево на два поддерева
    Split(treap, key, left, right);

    // Если новый узел имеет больший приоритет, чем корень
    if (newNode->Priority > treap->Root->Priority) {
        newNode->Left = left->Root;  // Левое поддерево
        newNode->Right = right->Root; // Правое поддерево
        treap->Root = newNode;         // Новый корень
    }
    else {
        // Вставляем новый узел в одно из поддеревьев
        if (key < treap->Root->Key) {
            newNode->Left = left->Root;
            newNode->Right = right->Root;
            treap->Root->Left = Merge(treap->Root->Left, newNode);
        }
        else {
            newNode->Left = left->Root;
            newNode->Right = right->Root;
            treap->Root->Right = Merge(treap->Root->Right, newNode);
        }
    }

    // Освобождаем временные структуры
    delete left;
    delete right;
}


void RemoveUnoptimized(Treap* treap, int key) 
{
    if (treap->Root == nullptr)
    {
        return;
    }

    Treap* left = new Treap();
    Treap* middle = new Treap();
    Treap* right = new Treap();

    Split(treap, key, left, middle);
    Split(middle, key + 1, middle, right);

    if (middle->Root) 
    {
        delete middle->Root; 
        treap->Root = Merge(left->Root, right->Root);
    }
    else 
    {
        treap->Root = Merge(left->Root, middle->Root);
    }
}

void RemoveOptimized(Treap* treap, int key) {
    if (treap->Root == nullptr) return;

    if (treap->Root->Key == key) 
    {
        TreapNode* oldNode = treap->Root;
        treap->Root = Merge(treap->Root->Left, treap->Root->Right);
        delete oldNode;
    }
    else if (key < treap->Root->Key) 
    {
        RemoveOptimized(new Treap{ treap->Root->Left }, key);
    }
    else
    {
        RemoveOptimized(new Treap{ treap->Root->Right }, key);
    }
}

TreapNode* Search(Treap* treap, int key)
{
    TreapNode* node = treap->Root;

    while (node != nullptr)
    {
        if (node->Key == key)
        {
            return node;
        }
        if (key < node->Key)
        {
            node = node->Left;
        }
        else 
        {
            node = node->Right;
        }
    }   return nullptr; 
}

void Clear(Treap* treap) 
{
    if (!treap || !treap->Root)
    {
        return;
    }

    Clear(new Treap{ treap->Root->Left });
    Clear(new Treap{ treap->Root->Right });

    delete treap->Root;
    delete treap;
}