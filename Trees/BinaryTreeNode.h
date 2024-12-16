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

/*
 * @brief Inserts a new value into the binary tree.
 *
 * This function recursively inserts a new value into the correct position in the binary tree.
 *
 * @param node A pointer to the current node in the binary tree.
 * @param data The data to be inserted into the tree.
 * @return A pointer to the updated binary tree node.
 */
BinaryTreeNode* Insert(BinaryTreeNode* node, int data);

/*
 * @brief Searches for a value in the binary tree.
 *
 * This function recursively searches for a value in the binary tree and returns the corresponding node if found.
 *
 * @param node A pointer to the current node in the binary tree.
 * @param data The data to be searched for.
 * @return A pointer to the found node or nullptr if not found.
 */
BinaryTreeNode* Search(BinaryTreeNode* node, int data);

/*
 * @brief Finds the maximum value in the binary tree.
 *
 * This function traverses to the rightmost node to find the maximum value.
 *
 * @param node A pointer to the current node in the binary tree.
 * @return A pointer to the node containing the maximum value.
 */
BinaryTreeNode* FindMaxValue(BinaryTreeNode* node);

/*
 * @brief Finds the minimum value in the binary tree.
 *
 * This function traverses to the leftmost node to find the minimum value.
 *
 * @param node A pointer to the current node in the binary tree.
 * @return A pointer to the node containing the minimum value.
 */
BinaryTreeNode* FindMinValue(BinaryTreeNode* node);

/*
 * @brief Deletes a node with a specified value from the binary tree.
 *
 * This function recursively finds and removes a node with the specified value from the binary tree.
 *
 * @param node A pointer to the current node in the binary tree.
 * @param data The data of the node to be deleted.
 * @return A pointer to the updated binary tree node.
 */
BinaryTreeNode* DeleteNode(BinaryTreeNode* node, int data);

/*
 * @brief Clears all nodes in the binary tree.
 *
 * This function recursively deallocates memory for all nodes in the binary tree.
 *
 * @param node A pointer to the current node in the binary tree.
 */
void ClearTree(BinaryTreeNode* node);
