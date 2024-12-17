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

/*
 * @brief Inserts a new value into the binary tree.
 *
 * This function recursively inserts a new value into the correct position in the binary tree.
 *
 * @param binaryTree A pointer to the current node in the binary tree.
 * @param data The data to be inserted into the tree.
 * @return A pointer to the updated binary tree node.
 */

void Insert(BinarySearchTree* binaryTree, int data);

/*
 * @brief Searches for a value in the binary tree.
 *
 * This function recursively searches for a value in the binary tree and returns the corresponding node if found.
 *
 * @param binaryTree A pointer to the current node in the binary tree.
 * @param data The data to be searched for.
 * @return A pointer to the found node or nullptr if not found.
 */
BinaryTreeNode* Search(BinarySearchTree* binaryTree, int data);

/*
 * @brief Finds the maximum value in the binary tree.
 *
 * This function traverses to the rightmost node to find the maximum value.
 *
 * @param binaryTree A pointer to the current node in the binary tree.
 * @return A pointer to the node containing the maximum value.
 */
BinaryTreeNode* FindMaxValue(BinarySearchTree* binaryTree);

/*
 * @brief Finds the minimum value in the binary tree.
 *
 * This function traverses to the leftmost node to find the minimum value.
 *
 * @param binaryTree A pointer to the current node in the binary tree.
 * @return A pointer to the node containing the minimum value.
 */
BinaryTreeNode* FindMinValue(BinarySearchTree* binaryTree);

/*
 * @brief Deletes a node with a specified value from the binary tree.
 *
 * This function recursively finds and removes a node with the specified value from the binary tree.
 *
 * @param binaryTree A pointer to the current node in the binary tree.
 * @param data The data of the node to be deleted.
 * @return A pointer to the updated binary tree node.
 */
BinaryTreeNode* DeleteNode(BinarySearchTree* binaryTree, int data);

/*
 * @brief Clears all nodes in the binary tree.
 *
 * This function recursively deallocates memory for all nodes in the binary tree.
 *
 * @param node A pointer to the current node in the binary tree.
 */
void ClearTree(BinarySearchTree* binaryTree);
