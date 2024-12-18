#include <iostream>
#include "TreapNode.h"
#include <iomanip>
#include "Treap.h"
#include "SupportMethods.h"
#include "Menu.h"
using namespace std;


void ShowTreapMenu()
{
    cout << "\tTreap Menu:\n";
    cout << "1. Insert a node to the tree(optimized)\n";
    cout << "2. Insert a node to the tree(not optimized)\n";
    cout << "3. Delete a node from the tree(optimized)\n";
    cout << "4. Delete a node from the tree(not optimized)\n";
    cout << "5. Search a node in the tree\n";
    cout << "0. Exit\n";
}

void PrintTreap(TreapNode* node, int indent)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->Right != nullptr)
    {
        PrintTreap(node->Right, indent + 4);
    }

    if (indent)
    {
        cout << setw(indent) << ' ';
    }

    if (node->Right)
    {
        cout << " /\n" << setw(indent) << ' ';
    }

    cout << node->Key << "(" << node->Priority << ")" << "\n ";
    if (node->Left)
    {
        cout << setw(indent) << ' ' << " \\\n";
        PrintTreap(node->Left, indent + 4);
    }
}

void TreapChoice(Treap* treap)
{
    while (true)
    {
        ClearScreen();
        ShowTreapMenu();
        PrintTreap(treap->Root, 1);
        int treapChoice = GetIntInput("Your input: ");

        switch (treapChoice)
        {

            case 1:
            {
                int data = GetIntInput("Enter key to insert: ");
                InsertOptimized(treap, data);
                break;
            }

            case 2:
            {
                int data = GetIntInput("Enter key to insert: ");
                InsertUnoptimized(treap, data);
                break;

            }

            case 3:
            {
                int data = GetIntInput("Enter key to delete: ");
                RemoveOptimized(treap, data);
                break;
            }

            case 4:
            {
                int data = GetIntInput("Enter key to delete: ");
                RemoveUnoptimized(treap, data);
                break;
            }

            case 5:
            {
                int data = GetIntInput("Enter the data to search: ");
                TreapNode* foundNode = Search(treap, data);
                if (foundNode == nullptr)
                {
                    cout << "\nNo node found \n";
                }
                else
                {
                    cout << "\nNode found: " << foundNode->Key << endl;
                }
                break;
            }

            case 0:
            {
                ClearScreen();
                ShowMainMenu();
                Clear(treap->Root);
                return;
            }

        default:
            cout << "Invalid choice! Try again." << endl;
        }

        ContinueCheck();
    }
}
