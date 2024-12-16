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
