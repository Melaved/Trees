#pragma once

/*
 * @brief Represents a node in a treap.
 * * This structure contains a key, priority, and pointers to left and right child nodes.
 */
struct TreapNode
{
    ///< The key stored in the node.
    int Key;                

    ///< The priority of the node used for maintaining heap property.
    int Priority;          

    ///< Pointer to the left child node.
    TreapNode* Left;   

    ///< Pointer to the right child node.
    TreapNode* Right;     
};

/*
 * @brief Creates a new treap node with specified key.
 *
 * This function allocates memory for a new treap node and initializes it with given key and random priority.
 *
 * @param key The key to be stored in the new treap node.
 * @return A pointer to the newly created treap node.
 */
TreapNode* NewNode(int key);
