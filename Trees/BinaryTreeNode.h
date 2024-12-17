#pragma once
/*
 * @brief Represents a node in a binary tree.
 *
 * This structure contains the data and pointers to the left and right child nodes.
 */
struct BinaryTreeNode
{
    ///< The data stored in the node.
    int Data;  

    ///< Pointer to the left child node.
    BinaryTreeNode* Left;

    ///< Pointer to the right child node.
    BinaryTreeNode* Right;  
};

/*
 * @brief Creates a new binary tree node.
 *
 * This function allocates memory for a new node and initializes it with the given data.
 *
 * @param data The data to be stored in the new node.
 * @return A pointer to the newly created node.
 */
BinaryTreeNode* CreateNode(int data);

