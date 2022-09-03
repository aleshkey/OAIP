#include <iostream>
#include <string>
using namespace std;
class Tree {
private:
	struct STree {
		int info;
		string data;
		STree *left, *right;
	};
	STree* root=NULL;

	STree* CreateList(int inf, string str) {
		STree *tr = new STree;
		tr->data = str;
		tr->info = inf;
		tr->left = tr->right = NULL;
		return tr;
	}

public:
	void CreateRoot(int inf, string str) {
		root->info = inf;
		root->data = str;
		root->left = root->right = NULL;
	}

	void AddList(int key, string str) {
		STree *prev, *tr;
		bool find = true;
		tr = root;
		while (tr && find) {
			prev = tr;
			if (key == tr->info) {
				find = false;
			}
			else
				if (key < tr->info) tr = tr->left;
				else   tr = tr->right;
		}
		if (find) {					// Нашли нужное место
			tr = CreateList(key, str);			// Создаем новый лист
			if (key < prev->info) { prev->left = tr; }
			else    prev->right = tr;
		}
	}


};

int main()
{
   
}