#include <vector>
#include <iostream>
using namespace std;
int main()
{ 
	setlocale(LC_ALL, "Russian");
	int c1, c2, mode, c3, c4, k=0;
	double element;
	cout << "Введите мощность множества А ";
	cin >> c1;	// Пользователь вводит мощность множества A
		vector <double> a; 
		cout << "Введите элементы множества А \n";
		for (int i = 0; i < c1; i++) {
			cin >> element;  //Пользователь вводит элементы множества A
			a.push_back(element);
		}
		cout << "Введите мощность множества В ";
		cin >> c2;  //Пользователь вводит мощность множества B
		vector <double> b;
		cout << "Введите элементы множества B \n";
		for (int i = 0; i < c2; i++) {
			cin >> element;  //Пользователь вводит элементы множества B
			b.push_back(element);
		}

		cout << "Вы хотите найти: \n" << "\t\t 1) Пересечение \n" << "\t\t 2) Объединение \n";
		cin >> mode;
		if (mode == 1) {
			vector <double> d;  //Создаётся пустое множество D
			for (int i = 0; i < c1; i++) {  //Выбираем элемент множества A
				for (int j = 0; j < c2; j++) {  //Выбираем элемент множества В
					if (a[i] == b[j]) {
						d.push_back(a[i]);  //Записываем выбранный элемент множества A во множество D
					}
				}
			}
			c3 = size(d);
			cout << endl;
			if (c3 != 0) {
				cout << "Множество D = {";
				for (int i = 0; i < c3 - 1; i++) {
					cout << d[i] << ", ";  //Выводим на экран результат операции пересечения множеств А и В (множество D)
				}
				cout << d[c3 - 1] << "}. \n";
			}
			else { cout << "D - пустое множество \n"; }
		}
		else {
				vector <double> c;  //Создаётся пустое множество C
				for (int i = 0; i < c1; i++) {
					c.push_back(a[i]);  //Во множество C копируется каждый элемент множества А
				}
				for (int i = 0; i < c2; i++) {  //Выбираем элемент множества B
					c4 = size(c);
					k = 0;
					for (int j = 0; j < c4; j++) {  //Выбираем элемент множества D
						if (b[i] == c[j]) {
							k += 1;
						}
					
					}
						if (k == 0) {
							c.push_back(b[i]);  //Записываем выбранный элемент множества B во множество D
						}
				}
				c4 = size(c);
				cout << "Множество С = {";
			for (int i = 0; i < c4-1; i++) {
					cout << c[i] << ", ";  //Выводим на экран результат операции объединения множеств А и В (множество D)
			}
			cout <<c[c4-1]<< "}. \n ";

		system("pause");

		
	return 0;
}

