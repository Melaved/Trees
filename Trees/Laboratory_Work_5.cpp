//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <iomanip>
//#include "BinaryTree.h"
//#include "TreapNode.h"
//
//
//// ... (код структур и функций для BinaryTree и Treap из предыдущих ответов) ...
//
//
//void printBST(BinaryTreeNode* node, int level = 0) {
//    if (node) {
//        printBST(node->Right, level + 1); // Рекурсивный вызов для правого поддерева
//        std::cout << std::setw(4 * level) << "" << node->Data << std::endl; // Вывод узла с отступами
//        printBST(node->Left, level + 1); // Рекурсивный вызов для левого поддерева
//    }
//}
//
//void printBinaryTree(const BinaryTree& tree) {
//    std::cout << "Бинарное дерево поиска:\n";
//    if (tree.Root == nullptr) {
//        std::cout << "Дерево пустое.\n";
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
//    std::cout << "Декартово дерево:\n";
//    if (treap.Root == nullptr) {
//        std::cout << "Дерево пустое.\n";
//    }
//    else {
//        printTreap(treap.Root);
//    }
//    std::cout << std::endl;
//}
//
//void printMenu() {
//    std::cout << "\nМеню:\n";
//    std::cout << "1. Добавить элемент в BST\n";
//    std::cout << "2. Удалить элемент из BST\n";
//    std::cout << "3. Найти элемент в BST\n";
//    std::cout << "4. Найти минимум в BST\n";
//    std::cout << "5. Найти максимум в BST\n";
//    std::cout << "6. Добавить элемент в Treap\n";
//    std::cout << "7. Удалить элемент из Treap\n";
//    std::cout << "8. Найти элемент в Treap\n";
//    std::cout << "9. Очистить BST\n";
//    std::cout << "10. Очистить Treap\n";
//    std::cout << "0. Выход\n";
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
//        std::cout << "Введите ваш выбор: \n";
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1:
//            std::cout << "Введите значение для добавления в BST: ";
//            std::cin >> value;
//            AddToTree(&bst, value);
//            break;
//        case 2:
//            std::cout << "Введите значение для удаления из BST: ";
//            std::cin >> value;
//            DeleteFromTree(&bst, value);
//            break;
//        case 3:
//            std::cout << "Введите значение для поиска в BST: ";
//            std::cin >> value;
//            if (SearchInTree(&bst, value))
//                std::cout << "Значение " << value << " найдено в BST\n";
//            else
//                std::cout << "Значение " << value << " не найдено в BST\n";
//            break;
//        case 4:
//            if (bst.Root)
//                std::cout << "Минимум в BST: " << FindMin(bst.Root) << "\n";
//            else
//                std::cout << "BST пусто\n";
//            break;
//        case 5:
//            if (bst.Root)
//                std::cout << "Максимум в BST: " << FindMax(bst.Root) << "\n";
//            else
//                std::cout << "BST пусто\n";
//            break;
//        case 6:
//            std::cout << "Введите значение для добавления в Treap: ";
//            std::cin >> value;
//            Insert(treap, value);
//            break;
//        case 7:
//            std::cout << "Введите значение для удаления из Treap: ";
//            std::cin >> value;
//            Remove(treap, value);
//            break;
//        case 8:
//            std::cout << "Введите значение для поиска в Treap: ";
//            std::cin >> value;
//            if (Search(treap.Root, value))
//                std::cout << "Значение " << value << " найдено в Treap\n";
//            else
//                std::cout << "Значение " << value << " не найдено в Treap\n";
//            break;
//        case 9:
//            ClearTree(&bst);
//            std::cout << "BST очищено\n";
//            break;
//        case 10:
//            ClearTreap(treap.Root);
//            treap.Root = nullptr;
//            std::cout << "Treap очищен\n";
//            break;
//        case 0:
//            std::cout << "Выход\n";
//            break;
//        default:
//            std::cout << "Неверный выбор\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}
