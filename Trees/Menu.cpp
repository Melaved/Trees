#include <iostream>
#include "SupportMethods.h"
using namespace std;

void ShowMainMenu()
{
    cout << "\nMain menu:" << endl;
    cout << "1. Binary search tree" << endl;
    cout << "2. Treap" << endl;
}

void Menu()
{
   /* HashTable* hashTable = CreateHashTable();
    Dictionary* dictionary = CreateDictionary();*/
    while (true)
    {
        ClearScreen();
        ShowMainMenu();

        int choice = GetIntInput("Your input: ");

        switch (choice)
        {

        case 1:
        {

            //BinarySearahTree(binaryTree);
            break;
        }

        case 2:
        {

            //TreapeChoice(treap);
            break;
        }

        case 0:
            /*DeleteHashTable(hashTable);
            DeleteDictionary(dictionary);*/
            return;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    }
}
