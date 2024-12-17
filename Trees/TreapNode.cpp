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

