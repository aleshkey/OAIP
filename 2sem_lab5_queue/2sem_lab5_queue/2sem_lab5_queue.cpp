#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Add_Front(queue<int> q, int x) {
	queue<int> q1;
	q1.push(x);
	while (q.size()>=1) {
		q1.push(q.front());
		q.pop();
	}
	return q1;
}

queue<int> Delete_Back(queue<int> q) {
	queue<int> q1;
	while (q.size() > 1) {
		q1.push(q.front());
		q.pop();
	}
	return q1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int kod, n;
	cin >> n;
	queue<int> q, buf;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		q.push(temp);
	}
	string repeat;
	while(1){
		cout << "1)добавить в конец\n2)удалить с начала\n3)добавтить в начало\n4)удалить в конце\n5)индивидуальное задание\n6)просмотр c начала\n7)просмотр с конца\n";
		cin >> kod;
		switch (kod)
		{
		case 1: {
			int temp;
			cin >> temp;
			q.push(temp);
			n = q.size();
			for (int i = 0; i < n; i++) {
				cout << q.front() << " ";
				buf.push(q.front());
				q.pop();
			}
			cout << endl;
			break;
		}
		case 2: {
			q.pop();
			n = q.size();
			for (int i = 0; i < n; i++) {
				cout << q.front() << " ";
				buf.push(q.front());
				q.pop();
			}
			cout << endl;
			break;
		}

		case 3: {
			int temp;
			cin >> temp;
			q = Add_Front(q, temp);
			n = q.size();
			for (int i = 0; i < n; i++) {
				cout << q.front() << " ";
				buf.push(q.front());
				q.pop();
			}
			cout << endl;
			break;
		}

		case 4: {
			q = Delete_Back(q);
			n = q.size();
			for (int i = 0; i < n; i++) {
				cout << q.front() << " ";
				buf.push(q.front());
				q.pop();
			}
			cout << endl;
			break;
		}

		case 5: {
			swap(q.front(), q.back());
			n = q.size();
			for (int i = 0; i < n; i++) {
				cout << q.front() << " ";
				buf.push(q.front());
				q.pop();
			}
			cout << endl;
			break;
		}
		case 6: {
			for (int i = 0; i < n; i++) {
				cout << q.front() << " ";
				buf.push(q.front());
				q.pop();
			}
			cout << endl;
			break;
		}
		case 7: {
			buf = q;
			for (int i = 0; i < n; i++) {
				cout << q.back() << " ";
				q = Delete_Back(q);
			}
			cout << endl;
			break;
		}
		}

		q = buf;
		n = buf.size();
		for (int i = 0; i < n; i++) {
			buf.pop();
		}
	}
	return 0;
}