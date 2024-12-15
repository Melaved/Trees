//#include <cstdlib> 
//#include "TreapNode.h"
//using namespace std;
//
//
//struct TreapNode
//{
//    int key;
//    int priority;
//    TreapNode* left;
//    TreapNode* right;
//
//    TreapNode(int key) : key(key), priority(rand()), left(nullptr), right(nullptr) {}
//};
//
//TreapNode* merge(TreapNode* left, TreapNode* right)
//{
//    if (!left)
//    {
//        return right;
//    }
//    if (!right) 
//    {
//        return left;
//    }
//
//    if (left->priority > right->priority)
//    {
//        left->right = merge(left->right, right);
//        return left;
//    }
//    else 
//    {
//        right->left = merge(left, right->left);
//        return right;
//    }
//}

//void split(TreapNode* root, int key, TreapNode*& left, TreapNode*& right)
//{
//    if (!root) 
//    {
//        left = right = nullptr;
//        return;
//    }
//
//    if (root->key <= key) 
//    {
//        left = root;
//        split(root->right, key, left->right, right);
//    }
//    else 
//    {
//        right = root;
//        split(root->left, key, left, right->left);
//    }
//}
//
//
//void insertUnoptimized(TreapNode*& root, int key) 
//{
//    TreapNode* newNode = new TreapNode(key);
//    TreapNode* left, * right;
//
//    split(root, key, left, right);
//
//    root = merge(merge(left, newNode), right);
//}
//
//void insertOptimized(TreapNode*& root, int key) 
//{
//    TreapNode* newNode = new TreapNode(key);
//    TreapNode* left, * right;
//
//    split(root, key, left, right);
//
//    newNode->left = left;
//    newNode->right = right;
//    root = newNode;
//}
//
//void removeUnoptimized(TreapNode*& root, int key) 
//{
//    if (!root)
//    {
//        return;
//    }
//
//    TreapNode* left, * middle, * right;
//
//    split(root, key - 1, left, middle);
//
//    split(middle, key, middle, right);
//
//    if (middle) 
//    {
//        delete middle;
//      
//        root = merge(left, right);
//    }
//    else 
//    {
//        root = merge(left, middle); 
//    }
//}
//
//void removeOptimized(TreapNode*& root, int key) 
//{
//    if (!root) return;
//
//    if (root->key == key)
//    {
//        TreapNode* oldNode = root;
//        root = merge(root->left, root->right);
//        delete oldNode;
//    }
//    else if (key < root->key)
//    {
//        removeOptimized(root->left, key);
//    }
//    else 
//    {
//        removeOptimized(root->right, key);
//    }
//}
//
//TreapNode* search(TreapNode* root, int key)
//{
//    if (!root || root->key == key)
//    {
//        return root;
//    }
//    if (key < root->key)
//    {
//        return search(root->left, key);
//    }
//    return search(root->right, key);
//}
//
//void clear(TreapNode*& root) 
//{
//    if (!root) 
//    {
//        return;
//    }
//    clear(root->left);
//    clear(root->right);
//    delete root;
//    root = nullptr;
//}

struct TreapNode 
{
	int Key;
	int Priority;
	TreapNode* Left;
	TreapNode* Right;
};

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right) 
{
	if (node == nullptr) 
	{
		left = right = nullptr;
	}

	if (node->Key <= key) 
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
    TreapNode* newNode = new TreapNode();
    TreapNode* left;
    TreapNode* right;

    Split(root, key, left, right);

    root = Merge(Merge(left, newNode), right);
}

void InsertOptimized(TreapNode*& node, int key)
{
    TreapNode* newNode = new TreapNode();

    if (node == nullptr)
    {
        node = newNode;
        return;
    }

    TreapNode* current = node;
    TreapNode* parent = nullptr;

    while (current) {
        parent = current;

        if (current->Key < key)
        {
            current = current->Right;
        }

        else
        {
            if (current->Priority < newNode->Priority)
            {
                break;
            }
            current = current->Left;
        }
    }

    TreapNode* leftSubtree = nullptr;
    TreapNode* rightSubtree = nullptr;

    if (parent)
    {
        if (parent->Key < key) {
            leftSubtree = parent;
            rightSubtree = parent->Right;
            parent->Right = nullptr;
        }

        else
        {
            leftSubtree = parent->Left;
            rightSubtree = parent;
            parent->Left = nullptr;
        }
    }

    newNode->Left = leftSubtree;
    newNode->Right = rightSubtree;

    if (parent) 
    {

        if (parent->Key < key) 
        {
            parent->Right = newNode;
        }

        else
        {
            parent->Left = newNode;
        }
    }

    else
    {
        node = newNode;
    }
}

void removeUnoptimized(TreapNode*& node, int key) 
{
    if (node == nullptr)
    {
        return;
    }

    TreapNode* left, * middle, * right;

    Split(node, key - 1, left, middle);

    Split(middle, key, middle, right);

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

void removeOptimized(TreapNode*& node, int key) 
{
    if (!node) return;

    if (node->Key == key)
    {
        TreapNode* oldNode = node;
        node = Merge(node->Left, node->Right);
        delete oldNode;
    }
    else if (key < node->Key)
    {
        removeOptimized(node->Left, key);
    }
    else 
    {
        removeOptimized(node->Right, key);
    }
}