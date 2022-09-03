#include <iostream>
#include <vector>
using namespace std;
struct Stack {
	int data;
	Stack *next;
} *beg;

Stack* Push(Stack *st, int in) {
	Stack *t = new Stack;
	t->data = in;
	t->next = st;
	return st;
}

void Show_Data(Stack *st) {
	Stack *t = st;
	while (t != NULL) {
		cout << t->data << endl;
		t = t->next;
	}
}

Stack* PoP(Stack* st, int *out) {
	Stack *t = st;
	*out = st->data;
	st = st->next; 		
	delete t; 			
	return st;
}

void Del_All(Stack **p) {
	Stack *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

/*Stack* Sort_p(Stack **p) {
	Stack *t = NULL, *t1, *r;
	if ((*p)->next->next == NULL) return *p;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->data > t1->next->next->data) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
	return *p;
}*/

int length(Stack **st) {
	int len = 0;
	while (*st != NULL) {
		len++;
		*st = (*st)->next;
	}
	return len;
}

/*void replace_first_and_last()
{
	if (length(&beg) == 1) {
		return;
	}

	if (length(&beg) == 2) {
		int *last=nullptr;
		beg=PoP(beg, last);
		int *first=nullptr;
		beg=PoP(beg, first);
		beg=Push(beg, *last);
		beg=Push(beg, *first);
		return;
	}

	int *last=nullptr, *first=nullptr;
	vector<int> temp;
	beg=PoP(beg, last);
	while (length(&beg) > 1) {
		int *Temp=nullptr;
		beg=PoP(beg, Temp);
		temp.push_back(*Temp);
	}

	beg=PoP(beg, first);

	beg=Push(beg, *last);
	for (vector<int>::reverse_iterator it = temp.rbegin(); it != temp.rend(); ++it)		beg=Push(beg, *it);
	beg=Push(beg, *first);
}*/

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "введите количество элементов\n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		beg = Push(beg, in);
	}
	//replace_first_and_last();
	Show_Data(beg);
	//beg = Sort_p(&beg);
	Show_Data(beg);
	Del_All(&beg);
	return 0;
}
