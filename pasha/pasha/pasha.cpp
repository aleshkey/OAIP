#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

int main()
{

	setlocale(LC_ALL, "rus");

	node *root = NULL;

	int operation, value, size;
	string name;
	string emptystring;
	while (true) {
		cout << "1 - Сreate tree\n2 - Add\n3 - Delete\n4 - Inorder traversal\n5 - Preorder traversaln\n6 - View tree\n7 - Find\n8 - Individual task\n0 - Exit\n\n";
		cin >> operation;
		cout << "------------------------------------------------------\n";
		switch (operation) {
		case 1:
			cout << "Enter the size of tree\n";
			cin >> size;
			cout << "Enter tree\n\n";
			for (int i = 0; i < size; ++i) {
				cout << "Enter value of new node\n";
				cin >> value;
				cout << "Enter name of new node\n";
				getline(cin, emptystring);
				getline(cin, name);
				Insert(root, value, name);
			}
			break;
		case 2:
			cout << "Enter value of new node\n";
			cin >> value;
			cout << "Enter name of new node\n";
			cin >> name;
			Insert(root, value, name);
			break;
		case 3:
			cout << "Enter value of node\n";
			cin >> value;
			Delete(value, root);
			break;
		case 4:
			PrintInorder(root);
			cout << endl;
			break;
		case 5:
			PrintPreorder(root);
			cout << endl;
			break;
		case 6:
			View_Tree(root, 0);
			break;
		case 7:
			cout << "Enter value of node\n";
			cin >> value;
			if (!Search(root, value))
				cout << "Сорри, but there isn't such element\n";
			cout << Search(root, value)->name << endl;
			break;
		case 8: {
			cout << "Введите значение узла\n";
			cin >> value;
			node *search_node = Search(root, value);
			if(search_node->left || search_node->right)
				cout << "Result: " << Task(search_node, 0) << endl;
			else cout << "Result: 0" << endl;
			break;
		}
		case 0:
			Clear(root);
			return 0;
		}
	}
}