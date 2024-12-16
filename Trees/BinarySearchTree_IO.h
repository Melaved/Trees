#pragma once
using namespace std;

/*
 * @brief Performs a pre-order traversal of the binary tree.
 *
 * This function visits the current node first, then recursively visits the left and right subtrees.
 *
 * @param node A pointer to the current node in the binary tree.
 */
void PreOrder(BinaryTreeNode* node);

/*
 * @brief Performs an in-order traversal of the binary tree.
 *
 * This function recursively visits the left subtree, then the current node, and finally the right subtree.
 *
 * @param node A pointer to the current node in the binary tree.
 */
void InOrder(BinaryTreeNode* node);

/*
 * @brief Performs a post-order traversal of the binary tree.
 *
 * This function recursively visits the left and right subtrees before visiting the current node.
 *
 * @param node A pointer to the current node in the binary tree.
 */
void PostOrder(BinaryTreeNode* node);

/*
 * @brief Performs a level-order traversal of the binary tree.
 *
 * This function visits nodes level by level, from top to bottom and left to right.
 *
 * @param root A pointer to the root node of the binary tree.
 */
void LevelOrder(BinaryTreeNode* root);

/*
 * @brief Prints the binary tree in a structured format.
 *
 * This function displays the binary tree with indentation to represent its structure visually.
 *
 * @param node A pointer to the current node in the binary tree.
 * @param indent The indentation level for printing the current node.
 */
void PrintBinaryTree(BinaryTreeNode* node, int indent);

/*
 * @brief Displays the menu for binary tree operations.
 *
 * This function presents a menu to the user for choosing various operations on the binary tree.
 */
void ShowBinaryTreeMenu();

/*
 * @brief Handles user choice for binary tree operations.
 *
 * This function processes user input and performs the corresponding operation on the given binary search tree.
 *
 * @param binaryTree A pointer to the binary search tree on which operations will be performed.
 */
void BinaryTreeChoice(BinarySearchTree* binaryTree);
