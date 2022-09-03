#include"tree.h"

int Height(node* root)
{
	if (root == NULL) return 0;
	int hLeft = Height(root->left),
		hRight = Height(root->right);
	if (hLeft > hRight)
		return hLeft + 1;
	else
		return hRight + 1;
}
void SetBalance(node* (&root))
{
	if (root != NULL)
		root->balance = Height(root->right) - Height(root->left);
}

void TurnRight(node* (&root))
{
	node* leftSubtree, *leftSubtreeRightSubtree;
	leftSubtree = root->left;
	leftSubtreeRightSubtree = leftSubtree->right;

	leftSubtree->right = root;
	root->left = leftSubtreeRightSubtree;
	root = leftSubtree;
	SetBalance(root->right);
	SetBalance(root);
}

void TurnLeft(node* (&root))
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

void Insert(node* (&root), int d, string name)
{
	if (root == NULL)
	{
		root = new node;
		root->info = d;
		root->name = name;
		root->balance = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (d > root->info)
		{
			Insert(root->right, d, name);
			if (Height(root->right) - Height(root->left) > 1)
			{
				if (Height(root->right->right) < Height(root->right->left))
					TurnRight(root->right);
				TurnLeft(root);
			}
		}
		else
			if (d < root->info)
			{
				Insert(root->left, d, name);
				if (Height(root->left) - Height(root->right) > 1)
				{
					if (Height(root->left->left) < Height(root->left->right))
						TurnLeft(root->left);
					TurnRight(root);
				}
			}
			else
				cout << "Данный элемент уже присутствует в дереве" << endl;
		SetBalance(root);
	}
}

void PrintInorder(node* root)
{
	if (root == NULL)
		return;
	PrintInorder(root->left);
	cout << root->info << " | " << root->name << endl;
	PrintInorder(root->right);
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

void Clear(node* (&p)) {
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

int Task(node* search_node, int count) {
	int rez = 0;
	if (!search_node->left && !search_node->right) {
		return count+1;
	}
	else {
		if (search_node->left) {
			rez=rez+Task(search_node->left, count);
		}
		if (search_node->right) {
			rez=rez+Task(search_node->right, count);
		}
	}
	return rez;
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

