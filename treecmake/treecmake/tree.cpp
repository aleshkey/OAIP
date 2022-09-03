#include"tree.h";

int Height(node* root) // вычисляет высоту дерева
{
	if (root == NULL) return 0; //если дерево пусто возвращем 0
	int hLeft = Height(root->left), // считаем высоту левого поддерева
		hRight = Height(root->right); // считаме высоту правого поддерева 
	if (hLeft > hRight) // если высота слева больше
		return hLeft + 1; // возвращаем +1, т.е добавили еще наш узел
	else // иначе 
		return hRight + 1; // возвращем высоту правого поддерева +1
}
// *(&root) эквивалетно **root (указатель на указатель)
// Т.е. вторая звездочка была заменена на амперсенд
//Данная операция была проведена для удобства, чтобы каждый раз не проводить операцию разименования 
//Т.е. &root уже разименованый указатель 
void SetBalance(node* (&root)) // нахождение значение баланса для текущего узла
{
	if (root != NULL) // если указатель не пуст 
		root->balance = Height(root->right) - Height(root->left); // то балансу присваиваем значение высоты от правого поддерева минус высота левого поддерева 
}

void TurnRight(node* (&root)) //правый поворот
{
	node* leftSubtree, *leftSubtreeRightSubtree; // rightSubtree - указатель на левое поддерево; rightSubtreeLeftSubtree - указатель на правое поддерево для левого поддерва 
	leftSubtree = root->left; //присваиваем значение левого поддерева 
	leftSubtreeRightSubtree = leftSubtree->right; // присваиваем значение правого поддерева для левого поддерева 

	leftSubtree->right = root; // присваиваем Х как правое поддерево А
	root->left = leftSubtreeRightSubtree; // Т2 присваивается Х
	root = leftSubtree; // присваиваем А, как новую вершину 
	SetBalance(root->right);
	SetBalance(root);
}

void TurnLeft(node* (&root)) //левый поворот
{
	node* rightSubtree, *rightSubtreeLeftSubtree;
	rightSubtree = root->right;
	rightSubtreeLeftSubtree = rightSubtree->left;

	rightSubtree->left = root;
	root->right = rightSubtreeLeftSubtree;
	root = rightSubtree;
	SetBalance(root->left);
	SetBalance(root);
}

void Insert(node* (&root), int d, string name) // добавление узла в дерево поиска
{
	if (root == NULL) //нашли пустой указатель - пустое место
	{ //создаем новый узел дерева на найденном месте 
		root = new node; // выделяем место в памяти под узел
		root->info = d; // сохраняем присваиваемое значение 
		root->name = name;
		root->balance = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else//текущий узел не пуст
	{
		if (d > root->info) //идем в правое поддерево
		{
			Insert(root->right, d, name);//добавляем узел в правое поддерево 
			if (Height(root->right) - Height(root->left) > 1) //если баланс AVL-дерева нарушен 
			{//выполням вращения 
				if (Height(root->right->right) < Height(root->right->left))//а если были еще проблемы в поддеревьях у правого поддерева 
					// Т. е. высота правого поддерева у правого поддерева меньше высоты правого поддерева у левого поддерева 
					TurnRight(root->right); //то предварительно проворачиваем правое дерево
				TurnLeft(root); //поворот дерева вправо 
			}
		}
		else
			if (d < root->info) // идем в левое поддерево
			{
				Insert(root->left, d, name); //добавялем узел в левое поддерво 
				if (Height(root->left) - Height(root->right) > 1) // если баланс AVL-дерева нарушен 
				{
					if (Height(root->left->left) < Height(root->left->right)) // а если были еще проблемы в поддеревьях у левого поддерева 
						//Т. е. высота левого поддерева у левого поддерева меньше высоты левого поддерева у правого поддерева 
						TurnLeft(root->left); //то предварительно проворачиваем левое поддерево
					TurnRight(root); //поворот дерева вправо 
				}
			}
			else
				cout << "Данный элемент уже присутствует в дереве" << endl;
		SetBalance(root);// пересчитываем значение баланса 
	}
}

void PrintInorder(node* root) //Inorder (центрированный) обход дерева
{
	if (root == NULL)
		return;
	PrintInorder(root->left); //сначало посещаем все узлы в левом поддереве 
	cout << root->info << " | " << root->name << endl; //посещаем корневой узел
	PrintInorder(root->right); // посещаем все узлы в правом поддереве 
}

void PrintPreorder(node *root)
{
	if (root == NULL)
		return;
	cout << root->info << " | " << root->name << endl;
	PrintPreorder(root->left);
	PrintPreorder(root->right);
}

void Delete(int x, node* (&root))
{
	node* d;
	if (root == NULL)
	{
		cout << "Sorry, but there isn't such element\n" << endl;
	}
	else if (x < root->info)
	{
		Delete(x, root->left);
	}
	else if (x > root->info) 
	{
		Delete(x, root->right);
	}
	else if ((root->left == NULL) && (root->right == NULL)) 
	{
		d = root;
		free(d); 
		root = NULL;
		cout << "Element removed\n" << endl;
	}
	else if (root->left == NULL)
	{
		d = root;
		root = root->right;
		free(d);
		cout << "Element removed\n" << endl;
	}
	else if (root->right == NULL)
	{
		d = root;
		root = root->left;
		free(d);
		cout << "Element removed\n" << endl;
	}
	else
	{
		root->right->left = root->left;
		root = root->right;
		d = root->right;
		free(d);
		cout << "Element removed\n" << endl;
	}
	return SetBalance(root);
}

void Clear(node* (&p))
{
	if (p != NULL)
	{
		Clear(p->left);
		Clear(p->right);

		delete p;
		p = NULL;
	}
}

node* Search(node* root, int value)
{
	if (root->info < value)
		return Search(root->right, value);
	else if (root->info > value)
		return Search(root->left, value);
	else
		return root;

}

int Task(node* root, int count) {
	if (root == NULL) return count;
	return max(Task(root->left, count + 1), Task(root->left, count + 1));
}

void View_Tree(node* p, int level) {
	string str;
	if (p) {
		View_Tree(p->right, level + 1);		
		for (int i = 0; i < level; i++) {
			str = str + "    ";
		}
		str += to_string(p->info);
		cout << str << endl;
		View_Tree(p->left, level + 1); 
	}
}

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}
