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

/*
 * @brief Splits a treap into two parts based on a key.
 *
 * This function divides a treap into two sub-treaps: one containing nodes with keys less than or equal to
 * the specified key, and another containing nodes with keys greater than that key.
 *
 * @param node A pointer to the root of the treap to be split.
 * @param key The key at which to split the treap.
 * @param left Reference to a pointer where left part of treap will be stored.
 * @param right Reference to a pointer where right part of treap will be stored.
 */
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/*
 * @brief Merges two treaps into one.
 *
 * This function combines two sub-treaps into one while maintaining heap and binary search properties.
 *
 * @param left A pointer to the first treap (left part).
 * @param right A pointer to the second treap (right part).
 * @return A pointer to the merged treap root.
 */
TreapNode* Merge(TreapNode* left, TreapNode* right);

/*
 * @brief Inserts a key into a treap without balancing it optimally.
 *
 * This function adds a new key into the treap without ensuring that it maintains optimal heap properties
 * after insertion. It can lead to an unbalanced state over time if used repeatedly without balancing operations.
 *
 * @param root Reference to a pointer where root of treap will be updated after insertion.
 * @param key The key to be inserted into the treap.
 */
void InsertUnoptimized(TreapNode*& root, int key);

/*
 * @brief Inserts a key into a treap while maintaining optimal balance.
 *
 * This function adds a new key into the treap and ensures that it maintains heap properties after insertion,
 * potentially rotating nodes as necessary.
 *
 * @param root Reference to a pointer where root of treap will be updated after insertion.
 * @param key The key to be inserted into the treap.
 */
void InsertOptimized(TreapNode*& root, int key);

/*
 * @brief Removes a key from a treap without balancing it optimally.
 *
 * This function deletes a specified key from the treap without ensuring that it maintains optimal heap properties
 * after removal.
 *
 * @param node Reference to a pointer where root of treap will be updated after removal operation.
 * @param key The key to be removed from the treap.
 */
void RemoveUnoptimized(TreapNode*& node, int key);

/*
 * @brief Removes a key from a treap while maintaining optimal balance.
 *
 * This function deletes a specified key from the treap and ensures that it maintains heap properties after removal,
 * potentially rotating nodes as necessary.
 *
 * @param node Reference to a pointer where root of treap will be updated after removal operation.
 * @param key The key to be removed from the treap.
 */
void RemoveOptimized(TreapNode*& node, int key);

/*
 * @brief Searches for a key in a treap.
 *
 * This function recursively searches for a specified key in the treap and returns
 * the corresponding node if found.
 *
 * @param node A pointer to the current node in the treap.
 * @param key The key to be searched for.
 * @return A pointer to the found node or nullptr if not found.
 */
TreapNode* Search(TreapNode* node, int key);

/*
 * @brief Clears all nodes in a treap.
 *
 * This function recursively deallocates memory for all nodes in the treap.
 *
 * @param node Reference to a pointer where root of treap will be cleared.
 */
void Clear(TreapNode*& node);
