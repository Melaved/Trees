#pragma once
#include "BinaryTreeNode.h"

/*
 * @brief Represents a binary search tree structure.
 * This structure contains a pointer to the root node of the binary search tree.
 */
struct BinarySearchTree
{
    ///< Pointer to the root node of the binary search tree.
    BinaryTreeNode* Root; 
};

/*
 * @brief Creates and initializes a new binary search tree.
 *
 * This function allocates memory for a new binary search tree and sets its root to nullptr.
 *
 * @return A pointer to the created binary search tree, or nullptr in case of an error.
 */
BinarySearchTree* CreateTree();
