#pragma once

/*
 * @brief Displays the menu for treap operations.
 *
 * This function presents a menu to the user for choosing various operations on the treap.
 */
void ShowTreapMenu();

/*
 * @brief Prints the treap in a structured format.
 *
 * This function displays the treap with indentation to represent its structure visually.
 *
 * @param node A pointer to the current node in the treap.
 * @param indent The indentation level for printing the current node.
 */
void PrintTreap(TreapNode* node, int indent);

/*
 * @brief Handles user choice for treap operations.
 *
 * This function processes user input and performs the corresponding operation on the given treap.
 *
 * @param treap A pointer to the treap on which operations will be performed.
 */
void TreapChoice(Treap* treap);