//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <iomanip>
//#include "BinaryTree.h"
//#include "TreapNode.h"
//
//
//// ... (��� �������� � ������� ��� BinaryTree � Treap �� ���������� �������) ...
//
//
//void printBST(BinaryTreeNode* node, int level = 0) {
//    if (node) {
//        printBST(node->Right, level + 1); // ����������� ����� ��� ������� ���������
//        std::cout << std::setw(4 * level) << "" << node->Data << std::endl; // ����� ���� � ���������
//        printBST(node->Left, level + 1); // ����������� ����� ��� ������ ���������
//    }
//}
//
//void printBinaryTree(const BinaryTree& tree) {
//    std::cout << "�������� ������ ������:\n";
//    if (tree.Root == nullptr) {
//        std::cout << "������ ������.\n";
//    }
//    else {
//        printBST(tree.Root);
//    }
//    std::cout << std::endl;
//}
//
//
//void printTreap(TreapNode* node, int level = 0) {
//    if (node) {
//        printTreap(node->Right, level + 1);
//        std::cout << std::setw(4 * level) << "" << node->Data << " (Priority: " << node->Priority << ")" << std::endl;
//        printTreap(node->Left, level + 1);
//    }
//}
//
//void printTreapTree(const Treap& treap) {
//    std::cout << "��������� ������:\n";
//    if (treap.Root == nullptr) {
//        std::cout << "������ ������.\n";
//    }
//    else {
//        printTreap(treap.Root);
//    }
//    std::cout << std::endl;
//}
//
//void printMenu() {
//    std::cout << "\n����:\n";
//    std::cout << "1. �������� ������� � BST\n";
//    std::cout << "2. ������� ������� �� BST\n";
//    std::cout << "3. ����� ������� � BST\n";
//    std::cout << "4. ����� ������� � BST\n";
//    std::cout << "5. ����� �������� � BST\n";
//    std::cout << "6. �������� ������� � Treap\n";
//    std::cout << "7. ������� ������� �� Treap\n";
//    std::cout << "8. ����� ������� � Treap\n";
//    std::cout << "9. �������� BST\n";
//    std::cout << "10. �������� Treap\n";
//    std::cout << "0. �����\n";
//
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    srand(time(0));
//    BinaryTree bst;
//    Treap treap;
//    int choice, value;
//
//    do {
//        printMenu();
//        printBinaryTree(bst);
//        printTreapTree(treap);
//        std::cout << "������� ��� �����: \n";
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1:
//            std::cout << "������� �������� ��� ���������� � BST: ";
//            std::cin >> value;
//            AddToTree(&bst, value);
//            break;
//        case 2:
//            std::cout << "������� �������� ��� �������� �� BST: ";
//            std::cin >> value;
//            DeleteFromTree(&bst, value);
//            break;
//        case 3:
//            std::cout << "������� �������� ��� ������ � BST: ";
//            std::cin >> value;
//            if (SearchInTree(&bst, value))
//                std::cout << "�������� " << value << " ������� � BST\n";
//            else
//                std::cout << "�������� " << value << " �� ������� � BST\n";
//            break;
//        case 4:
//            if (bst.Root)
//                std::cout << "������� � BST: " << FindMin(bst.Root) << "\n";
//            else
//                std::cout << "BST �����\n";
//            break;
//        case 5:
//            if (bst.Root)
//                std::cout << "�������� � BST: " << FindMax(bst.Root) << "\n";
//            else
//                std::cout << "BST �����\n";
//            break;
//        case 6:
//            std::cout << "������� �������� ��� ���������� � Treap: ";
//            std::cin >> value;
//            Insert(treap, value);
//            break;
//        case 7:
//            std::cout << "������� �������� ��� �������� �� Treap: ";
//            std::cin >> value;
//            Remove(treap, value);
//            break;
//        case 8:
//            std::cout << "������� �������� ��� ������ � Treap: ";
//            std::cin >> value;
//            if (Search(treap.Root, value))
//                std::cout << "�������� " << value << " ������� � Treap\n";
//            else
//                std::cout << "�������� " << value << " �� ������� � Treap\n";
//            break;
//        case 9:
//            ClearTree(&bst);
//            std::cout << "BST �������\n";
//            break;
//        case 10:
//            ClearTreap(treap.Root);
//            treap.Root = nullptr;
//            std::cout << "Treap ������\n";
//            break;
//        case 0:
//            std::cout << "�����\n";
//            break;
//        default:
//            std::cout << "�������� �����\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}
