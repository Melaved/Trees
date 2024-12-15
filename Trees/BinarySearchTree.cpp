
////void PreOrder(BinaryTreeNode* node)
////{
////    if (node == nullptr) return;
////    std::cout << node->Data << " ";
////    PreOrder(node->Left);
////    PreOrder(node->Right);
////}
////
////// Симметричный обход
////void InOrder(BinaryTreeNode* node)
////{
////    if (node == nullptr) return;
////    InOrder(node->Left);
////    std::cout << node->Data << " ";
////    InOrder(node->Right);
////}
////
////// Обратный обход
////void PostOrder(BinaryTreeNode* node)
////{
////    if (node == nullptr) return;
////    PostOrder(node->Left);
////    PostOrder(node->Right);
////    std::cout << node->Data << " ";
////}
////
////// Обход в ширину
////void LevelOrder(BinaryTreeNode* root)
////{
////    if (root == nullptr) return;
////
////    std::queue<BinaryTreeNode*> q;
////    q.push(root);
////
////    while (!q.empty())
////    {
////        BinaryTreeNode* current = q.front();
////        q.pop();
////        std::cout << current->Data << " ";
////
////        if (current->Left != nullptr)
////            q.push(current->Left);
////        if (current->Right != nullptr)
////            q.push(current->Right);
////    }
////}
//
//// Функция для визуального представления дерева
//void PrintTree(BinaryTreeNode* root, int space = 0, int height = 5)
//{
//    if (root == nullptr)
//    {
//        return;
//    }
//
//    space += height;
//
//    PrintTree(root->Right, space);
//
//    cout << std::endl;
//    for (int i = height; i < space; i++) 
//    {
//        cout << " ";
//    }
//    cout << root->Data << "\n";
//
//    PrintTree(root->Left, space);
//}
//
//int main()
//{
//    setlocale(LC_ALL, "RU");
//    BinaryTreeNode* root = nullptr;
//
//    // Пример вставки значений
//    root = Insert(root, 10);
//    while (true) 
//    {
//        PrintTree(root);
//        Insert(root, GetIntInput("ВВеди"));
//    }
//
//    //std::cout << "Прямой обход (Pre-order): ";
//    //PreOrder(root);
//    //std::cout << "\nСимметричный обход (In-order): ";
//    //InOrder(root);
//    //std::cout << "\nОбратный обход (Post-order): ";
//    //PostOrder(root);
//    //std::cout << "\nОбход в ширину (Level-order): ";
//    //LevelOrder(root);
//
//    std::cout << "\n\nВизуальное представление дерева:\n";
//    PrintTree(root);
//
//    // Освобождение памяти (не забудьте добавить функцию удаления узлов)
//
//    return 0;
//}


struct BinarySearchTree 
{
	int Data;
	BinarySearchTree* Left;
	BinarySearchTree* Right;
};

BinarySearchTree* createNode(int data) 
{
	BinarySearchTree* node = new BinarySearchTree();
	node->Data = data;
	node->Left = nullptr;
	node->Right = nullptr;
	return node;
}

BinarySearchTree* Insert(BinarySearchTree* node, int data)
{
	if (node == nullptr)
	{
		return createNode(data);
	}

	if (data < node->Data)
	{
		node->Left = Insert(node->Left, data);
	}

	if (data > node->Data)
	{
		node->Right = Insert(node->Right, data);
	}

	return node;
}

BinarySearchTree* Search(BinarySearchTree* node, int data) 
{
	if (node == nullptr) 
	{
		return nullptr;
	}

	if (node->Data == data)
	{
		return node;
	}

	if (data > node->Data) 
	{
		return Search(node->Right, data);
	}

	else 
	{
		return Search(node->Left, data);
	}
}

BinarySearchTree* FindMaxValue(BinarySearchTree* node) 
{
	if (node == nullptr) 
	{
		return nullptr;
	}

	while (node->Right != nullptr) 
	{
		node = node->Right;
	}

	return node;
}

BinarySearchTree* FindMinValue(BinarySearchTree* node) 
{
	if (node == nullptr) 
	{
		return nullptr;
	}

	while (node->Left != nullptr) 
	{
		node = node->Left;
	}

	return node;
}

BinarySearchTree* DeleteNode(BinarySearchTree* node, int data)
{
	if (node == nullptr) 
	{
		return nullptr;
	}

	if (data < node->Data) 
	{
		node->Left = DeleteNode(node->Left, data);
	}

	if (data > node->Data) 
	{
		node->Right = DeleteNode(node->Right, data);
	}

	if (data == node->Data) 
	{
		if (node->Left == nullptr) 
		{
			BinarySearchTree* temp = node->Right;
			delete node;
			return temp;
		}
		if (node->Right == nullptr) 
		{
			BinarySearchTree* temp = node->Left;
			delete node;
			return temp;
		}

		BinarySearchTree* temp = FindMinValue(node->Right);

		node->Data = temp->Data;
		
		node->Right = DeleteNode(node->Right, temp->Data);
	}
	return node;
}

void ClearTree(BinarySearchTree* node)
{
	if (node == nullptr)
	{
		return;
	}

	ClearTree(node->Left);
	ClearTree(node->Right);

	delete node;
}


//void PreOrder(BinarySearchTree* node) 
//{
//	if (node == nullptr) 
//	{
//		return;
//	}
//
//}