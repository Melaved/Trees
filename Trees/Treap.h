#pragma once
#include "TreapNode.h"

/*
 * @brief Represents a treap structure.
 *
 * This structure contains a pointer to the root of the treap.
 */
struct Treap
{
    ///< Pointer to the root node of the treap.
    TreapNode* Root; 
};

/*
 * @brief Creates a new treap.
 *
 * This function allocates memory for a new treap and initializes its root as nullptr.
 *
 * @return A pointer to the newly created treap.
 */
Treap* CreateTreap();

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
void Split(TreapNode* treap, int key, TreapNode*& left, TreapNode*& right);

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
 * @param treap pointer where root of treap will be updated after insertion.
 * @param key The key to be inserted into the treap.
 */
Treap* InsertUnoptimized(Treap* treap, int key);

/*
 * @brief Inserts a key into a treap while maintaining optimal balance.
 *
 * This function adds a new key into the treap and ensures that it maintains heap properties after insertion,
 * potentially rotating nodes as necessary.
 *
 * @param root Reference to a pointer where root of treap will be updated after insertion.
 * @param key The key to be inserted into the treap.
 */
Treap* InsertOptimized(Treap* treap, int key);

/*
 * @brief Removes a key from a treap without balancing it optimally.
 *
 * This function deletes a specified key from the treap without ensuring that it maintains optimal heap properties
 * after removal.
 *
 * @param Treap Reference to a pointer where root of treap will be updated after removal operation.
 * @param key The key to be removed from the treap.
 */
Treap* RemoveUnoptimized(Treap* treap, int key);

/*
 * @brief Removes a key from a treap while maintaining optimal balance.
 *
 * This function deletes a specified key from the treap and ensures that it maintains heap properties after removal,
 * potentially rotating nodes as necessary.
 *
 * @param node Reference to a pointer where root of treap will be updated after removal operation.
 * @param key The key to be removed from the treap.
 */
Treap* RemoveOptimized(Treap* treap, int key);


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
TreapNode* Search(Treap* treap, int key);

/*
 * @brief Clears all nodes in a treap.
 *
 * This function recursively deallocates memory for all nodes in the treap.
 *
 * @param node Reference to a pointer where root of treap will be cleared.
 */
void Clear(TreapNode*& node);

/*
 * @brief Clear a treap.
 *
 * This function recursively deallocates memory for all nodes in the treap.
 *
 * @param reference Reference to a pointer where root of treap will be cleared.
 */
void ClearTreap(Treap*& treap);

