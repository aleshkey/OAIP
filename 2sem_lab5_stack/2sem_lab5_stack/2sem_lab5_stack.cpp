#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
	struct TStack {
		int data;
		TStack* next;
	};
	TStack* head;
	TStack* tail;

	void Add_Head() {
		if (head) {
			TStack *temp = new TStack;
			temp = head;
			head = new TStack;
			head->data = 0;
			head->next = temp;
		}
	}

	void Delete_Head() {
		if (head->next) {
			head = head->next;
		}
	}

	int len;

public:
	Stack() :head(nullptr), len(0) {}

	int Pop()
	{
		if (head)
		{
			TStack *now = head;
			TStack *prev = nullptr;

			while (now->next)
			{
				prev = now;
				now = now->next;
			}

			if (prev)
				prev->next = nullptr;
			int n = now->data;
			delete now;
			len--;
			if (len == 0)
			{
				head = nullptr;
				tail = nullptr;
			}
			return n;
		}
		return 0;
	}

	void Push(int n)
	{
		TStack* temp = new TStack();

		if (head == nullptr)
			head = temp;
		else
			tail->next = temp;
		temp->data = n;
		temp->next = nullptr;
		tail = temp;
		len++;
	}

	int length()
	{
		return len;
	}

	void print()
	{
		TStack* tmp = head;
		while (tmp) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void Sorting_Adres() {
		TStack *t = NULL, *t1, *r, *t2;
		Add_Head();
		if ((head)->next->next == NULL) return;
		do {
			for (t1 = head; t1->next->next != t; t1 = t1->next)
				if (t1->next->next && t1->next->data > t1->next->next->data) {
					r = t1->next->next;
					t1->next->next = r->next;
					r->next = t1->next;
					t1->next = r; 
				}
			t = t1->next;
		} while ((head)->next->next != t);
		Delete_Head();
	}

	void Sorting_Data() {
		TStack *t = NULL, *t1;
		int r;
		do {
			for (t1 = head; t1->next != t; t1 = t1->next)
				if (t1->data > t1->next->data) {
					r = t1->data;
					t1->data = t1->next->data;
					t1->next->data = r;
				}
			t = t1;
		} while (head->next != t);
	}

};

void replace_first_and_last(Stack& st)
{
	if (st.length() == 1) {
		return;
	}

	if (st.length() == 2) {
		int last = st.Pop();
		int first = st.Pop();
		st.Push(last);
		st.Push(first);
		return;
	}

	int last, first;
	vector<int> temp;
	last = st.Pop();
	while (st.length() > 1)
		temp.push_back(st.Pop());
	first = st.Pop();

	st.Push(last);  
	for (int i = temp.size() - 1; i >= 0; i--) {
		st.Push(temp[i]); 
	}
	st.Push(first);
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack st;
	int n, key;
	cout << "введите количество элементов\n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int buffer;
		cin >> buffer;
		st.Push(buffer);
	}
	replace_first_and_last(st);
	st.print();
	cout << "1)сортировка адресами\n2)сортировка значений\n";
	cin >> key;
	if (key == 1) {
		st.Sorting_Adres();
	}
	else st.Sorting_Data();
	st.print();
	return 0;
}
