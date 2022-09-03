#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	node *root = NULL;
	int operation, value, size;
	string name;
	while (true) {
		cout << "1 - Сreate tree\n"
			<< "2 - Add\n"
			<< "3 - Delete\n"
			<< "4 - Inorder traversal\n"
			<< "5 - Preorder traversaln\n"
			<< "6 - View tree\n"
			<< "7 - Find\n"
			<< "8 - Individual task\n"
			<< "0 - Exit\n\n";
		cin >> operation;
		switch (operation) {
		case 1:
			cout << "Enter the size of tree\n";
			cin >> size;
			cout << "Enter tree\n\n";
			for (int i = 0; i < size; ++i) {
				cout << "Enter value of new node\n";
				cin >> value;
				cout << "Enter name of new node\n";
				cin >> name;
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
				cout << "Sorry, but there isn't such element\n";
			cout << Search(root, value)->name << endl;
			break;
		case 8: {
			int count = 0;
			Task(root, count);
			cout << "Count of nodes that have only one son: " << count << endl;
			break;
		}
		case 0:
			Clear(root);
			return 0;
		}
	}
}

