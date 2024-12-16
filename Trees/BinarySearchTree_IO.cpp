#include <iostream>
#include <queue>
#include <iomanip>
#include "BinarySearchTree.h"
#include "BinarySearchTree_IO.h"
#include "SupportMethods.h"
#include "Menu.h"
using namespace std;

void PreOrder(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->Data << " ";
    PreOrder(node->Left);
    PreOrder(node->Right);
}

void InOrder(BinaryTreeNode* node)
{
    if (node == nullptr) 
    {
        return;
    }
    InOrder(node->Left);
    cout << node->Data << " ";
    InOrder(node->Right);
}

void PostOrder(BinaryTreeNode* node)
{
    if (node == nullptr) 
    {
        return;
    }

    PostOrder(node->Left);
    PostOrder(node->Right);
    cout << node->Data << " ";
}

void LevelOrder(BinaryTreeNode* root)
{
    if (root == nullptr) 
    {
        return;
    }

    queue<BinaryTreeNode*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        BinaryTreeNode* current = queue.front();
        queue.pop();
        cout << current->Data << " ";

        if (current->Left != nullptr)
        {
            queue.push(current->Left);
        }

        if (current->Right != nullptr)
        {
            queue.push(current->Right);
        }
    }
}

void PrintBinaryTree(BinaryTreeNode* node, int indent)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->Right)
    {
        PrintBinaryTree(node->Right, indent + 4);
    }

    if (indent)
    {
        cout << setw(indent) << ' ';
    }

    if (node->Right)
    {
        cout << " /\n" << setw(indent) << ' ';
    }

    cout << node->Data << "\n ";
    if (node->Left)
    {
        cout << setw(indent) << ' ' << " \\\n";
        PrintBinaryTree(node->Left, indent + 4);
    }

}

void ShowBinaryTreeMenu() 
{
    cout << "\tBinary Search Tree Menu:\n";
    cout << "1. Insert a node to the tree\n";
    cout << "2. Delete a node from the tree\n";
    cout << "3. Search a node in the tree\n";
    cout << "4. Search minimum value\n";
    cout << "5. Search maximum value\n";
    cout << "6. InOrder traversal\n";
    cout << "7. PreOrder traversal\n";
    cout << "8. PostOrder traversal\n";
    cout << "9. LevelOrder traversal\n";
    cout << "0. Exit\n";
}


void BinaryTreeChoice(BinarySearchTree* binaryTree) 
{
    while (true)
    {
        ClearScreen();
        ShowBinaryTreeMenu();

        if (binaryTree->Root == nullptr) 
        {
            binaryTree->Root = Insert(binaryTree->Root, GetIntInput("Enter root value: "));
        }

        PrintBinaryTree(binaryTree->Root,1);
        int BinarySearchTreeChoice = GetIntInput("Your input: ");

        switch (BinarySearchTreeChoice)
        {

            case 1:
            {
                int data = GetIntInput("Enter data to insert: ");
                Insert(binaryTree->Root, data); 
                break;
            }

            case 2:
            {
                int data = GetIntInput("Enter data to delete: ");
                DeleteNode(binaryTree->Root, data); 
                break;
            }

            case 3:
            {
                int data = GetIntInput("Enter the data to search: ");
                BinaryTreeNode* foundNode = Search(binaryTree->Root, data);
                if (foundNode == nullptr)
                {
                    cout << "\nNo node found \n";
                }
                else
                {
                    cout << "\nNode found: " << foundNode->Data << endl;
                }
                break;
            }

            case 4: 
            {
                BinaryTreeNode* minNode = FindMinValue(binaryTree->Root);
                if (minNode != nullptr)
                {
                    cout << "Min value in the tree: " << minNode->Data << endl;
                }
                else
                {
                    cout << "Tree is empty \n";
                }
                break;
            }

            case 5:
            {
                BinaryTreeNode* maxNode = FindMaxValue(binaryTree->Root);
                if (maxNode != nullptr)
                {
                    cout << "Max value in the tree: " << maxNode->Data << endl;
                }
                else
                {
                    cout << "Tree is empty \n";
                }
                break;
            }

            case 6:
            {
                cout << "InOrder: ";
                InOrder(binaryTree->Root);
                break;
            }

            case 7:
            {
                cout << "PreOrder: ";
                PreOrder(binaryTree->Root);
                break;
            }

            case 8:
            {
                cout << "PostOrder: ";
                PostOrder(binaryTree->Root);
                break;
            }

            case 9:
            {
                cout << "LevelOrder: ";
                LevelOrder(binaryTree->Root);
                break;
            }

            case 0:
            {
                ClearScreen();
                ShowMainMenu();
                ClearTree(binaryTree->Root);
                return;
            }

        default:
            cout << "Invalid choice! Try again." << endl;
        }

        ContinueCheck(); 
    }
}
