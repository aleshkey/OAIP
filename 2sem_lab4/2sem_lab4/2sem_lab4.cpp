#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Devide_into_words.h"
using namespace std;
struct Bus{
	string number;
	string destination;
	string departure_time;
	string arrivel_time;
};

int line_search(Bus *bus,int n) {
	string key;
	cout << endl << "Введите ключ: ";
	cin >> key;
	for (int i = 0; i < n; i++) {
		if (key <= bus[i].arrivel_time) {
			return i;
		}
	}
}

void GetData(Bus *bus, vector<string> words, int i) {
	if (words.size() == 4 && words[2] != "") {
		bus[i].number = words[0];
		bus[i].destination = words[1];
		bus[i].departure_time = words[2];
		bus[i].arrivel_time = words[3];
	}
}

void ShowData(Bus bus) {
	ofstream fout;
	fout.open("output.txt", ios::app);
	fout << bus.number << "\t" << bus.destination << "\t" << bus.departure_time << "\t" << bus.arrivel_time << endl;
	fout.close();
}

void qsort(Bus *bus, int left, int right) {
	int i, j;
	string x, buffer;
	i = left; j = right;
	x = bus[(left + right) / 2].arrivel_time;
	do {
		while ((bus[i].arrivel_time < x) && (i < right))i++;
		while ((x < bus[j].arrivel_time) && (j > left)) j--;
		if (i <= j) {
			swap(bus[i], bus[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (left < j) qsort(bus, left, j);
	if (i < right) qsort(bus, i, right);
}

int binary_search(int left, int right, Bus *bus){
	bool flag = false;
	int mid;
	string key;
	cout << endl << "Введите ключ: ";
	cin >> key;
	while ((left <= right) && (flag != true)) {
		mid = (left + right) / 2;
		if (bus[mid].arrivel_time <= key && bus[mid+1].arrivel_time > key) flag = true;
		if (bus[mid].arrivel_time > key) right = mid - 1; 
		else left = mid + 1;
	}
	return mid;
}

void addition()
{
	string str;
	getline(cin, str);
	ofstream fout;
	fout.open("input.txt", ios::app);
	fout << endl << str;
}

void ChangingData() {
	int strings = 0;
	ifstream fin("input.txt");
	string str;
	while (!fin.eof()) {
		string buffer;
		getline(fin, buffer);
		strings++;
	}
	int  n;
	Bus *bus;
	bus = new Bus[strings];
	cout << "какую строку хотите заменить?\n";
	cin >> n;
	string emptystring;
	n--;
	cout << "введите новые данные\n";
	getline(cin, emptystring);
	getline(cin, str);
	if (fin.is_open()) {
		system("cls");
		fin.clear();
		fin.seekg(0);
		for (int i = 0; i < strings; i++) {
			string buffer;
			getline(fin, buffer);
			vector<string> words = Devide_into_words(buffer);
			if (i != n) {
				GetData(bus, words, i);
			}
		}
	}
	fin.close();
	remove("input.txt");
	ofstream fout;
	fout.open("input.txt", ios::app);
	for (int i = 0; i < strings; i++) {
		if (i == n) {
			fout << str << endl;
		}
		else {
			fout << bus[i].number << " " << bus[i].destination << " " << bus[i].departure_time << " " << bus[i].arrivel_time << endl;
		}
	}
	delete[] bus;
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "rus");
	int menu;
	int strings = 0;
		system("cls");
		cout << "1) Создание\n2)Просмотр\n3)Коррекция\n4)Решение индивидуального задания\n";
		cin >> menu;
		switch (menu) {
			case 1: {
				cout << "введите количество элементов списка\n";
				string buffer;
				ofstream fout;
				fout.open("input.txt");
				int n;
				cin >> n;
				string emptystring;
				getline(cin, emptystring);
				for (int i = 0; i < n; i++) {
					getline(cin, buffer);
					fout << buffer << endl;
				}
				fout.close();
				break;
			}
			case 2: {
				ifstream fin("input.txt");
				if (fin.is_open()) {
					system("cls");
					while (!fin.eof()) {
						string buffer;
						getline(fin, buffer);
						strings++;
					}
					fin.clear();
					fin.seekg(0);
					Bus *bus;
					bus = new Bus[strings];
					int i = 0;
					while (!fin.eof()) {
						string buffer;
						getline(fin, buffer);
						vector<string> words = Devide_into_words(buffer);
						GetData(bus, words, i);
						i++;
					}
					for (i = 0; i < strings; i++) {
						cout.width(8);
						cout << bus[i].number << " " << bus[i].destination << " " << bus[i].departure_time << " " << bus[i].arrivel_time << endl;
					}
				}
				else cout << "file is not open";
				system("pause");
				fin.close();
				break;
			}
			case 3: {
				system("cls");
				cout << "1)Изменить данные\n2)Добавить данные\n";
				int kod;
				cin >> kod;
				if (kod == 2) {
					addition();
				}
				else {
					if (kod == 1) {
						ChangingData();
					}
				}
				break;
			}
			case 4: {	
				ifstream fin("input.txt");
				if (fin.is_open()) {
					while (!fin.eof()) {
						string buffer;
						getline(fin, buffer);
						strings++;
					}
					fin.clear();
					fin.seekg(0);
					Bus *bus;
					bus = new Bus[strings];
					int i = 0;
					while (!fin.eof()) {
						string buffer;
						getline(fin, buffer);
						vector<string> words = Devide_into_words(buffer);
						GetData(bus, words, i);
						i++;
					}
					int kod;
					cout << "1)QSort\n2)метод прямого выборa\n";
					cin >> kod;
					if (kod == 1) {
						qsort(bus, 0, strings - 1);
					}
					if (kod == 2) {
						for (int j = 0; j < strings; j++) {
							int num_min = j;
							for (int i = j; i < strings; i++) {
								if (bus[i].arrivel_time < bus[num_min].arrivel_time) {
									num_min = i;
								}
							}
							swap(bus[j], bus[num_min]);
						}
					}
					int KOD,  x;
					cout << "каким способом будем искать?\n1)бинарный поиск\n2)линейный поиск\n";
					cin >> KOD;
					if (KOD == 1) {
						x = binary_search(0, strings, bus);
					}
					else {
						x = line_search(bus, strings);
					}
					
					ofstream fout("output.txt");
					fout << "";
					fout.close();

					for (int i = 0; i < x; i++) {
						ShowData(bus[i]);
					}
					delete[] bus;
					fin.close();
				}
				

		}
	}
	return 0;
}