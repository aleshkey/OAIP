#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "twodimensional_array.h"
#include "devide_into_words.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int KOD;
	cout << "1)вручную\n2)тестами\n";
	cin >> KOD;
	switch (KOD)
	{
	case 1: {
		int rows, colums;
		twodimensional_array arr;
		int menu;
		string repeat = "yes";
		while (repeat != "no") {
			system("cls");
			cout << "1)создание\n2)сортировка\n3)добавление\n4)просмотр\n5)поиск\n6)объединение/пересечение\n";
			cin >> menu;
			switch (menu)
			{
			case 1: {
				cout << "введите начальные размеры массива\n";
				cin >> rows >> colums;
				arr.SetRows(rows); arr.SetColums(colums);
				arr.creation();
				break;
			}
			case 2: {
				arr.sorting();
				cout << "\n\n";
				arr.print();
				break;
			}
			case 3: {
				int kod;
				cout << "хатите заменить элемент(1) или добавить строку(2)";
				cin >> kod;
				switch (kod) {

				case 1: int x, y, number;
					cout << "какой элемент хотите заменить?\n";
					cin >> x >> y >> number;
					arr.replace(x, y, number);
					cout << "\n\n";
					arr.print();
					break;

				case 2: {
					system("cls");
					arr.addrow();
					cout << "\n\n";
					arr.print();
					break;
				}
				}
			}
			case 4: {
				system("cls");
				arr.print();
				break;
			}
			case 5: {
				system("cls");
				int temp;
				cout << "какой элемент хотите найти\n";
				cin >> temp;
				arr.print();
				cout << endl;

				arr.search(temp);
				break;
			}
			case 6: {
				system("cls");
				cout << "введите размеры нового массива\n";
				int ROWS, COLUMS;
				cin >> ROWS >> COLUMS;
				twodimensional_array arr2(ROWS, COLUMS);
				arr2.creation();
				cout << "желаете его отсортировать?(yes/no)\n";
				string buffer;
				cin >> buffer;
				if (buffer == "yes") {
					arr2.sorting();
				}
				cout << "что вы хотите выполнить:\n1)пересечение\n2)объединение\n";
				int temp;
				cin >> temp;
				switch (temp)
				{
				case 1: {
					cout << "array1=\n";
					arr.print();
					cout << endl << "array2=\n";
					arr2.print();
					cout << "\n\n";
					arr.intersection(arr2);
					cout << "rezult:\n";
					arr.print();
					break;
				}
				case 2: {
					cout << "array1=\n";
					arr.print();
					cout << endl << "array2=\n";
					arr2.print();
					cout << "\n\n";
					arr.Union(arr2);
					cout << "rezult:\n";
					arr.print();
					break;
				}
				}
			}
			}
			cout << "желаете провести ещё одну операцию?(yes/no)\n";
			string buffer;
			cin >> buffer;
			repeat = buffer;
		}
		break;
	}
	case 2: {
		system("cls");
		for (int i = 0; i < 5; i++) {
			stringstream ss;
			ss << i;
			string str = ss.str();
			string path = "Test" + str + ".txt";
			cout << "\n\n------------------------test" + str + "--------------------\n\n";
			ifstream fin(path);
			vector<int>textinfile;
			vector <int> arrinfile;
			int replacex, replacey, replacenumber, SEARCH, count = 0;
			int rows = 0, colums;
			int ROWS = 0, COLUMS;
			if (fin.is_open()) {
				vector <int> file;
				while (!fin.eof()) {
					string buffer;
					getline(fin, buffer);
					vector <string> buf = devide_into_words(buffer);
					if (buf.size() != 1 && count == 0) {
						colums = buf.size();
						for (int i = 0; i < buf.size(); i++) {
							textinfile.push_back(atoi(buf[i].c_str()));
						}
						rows++;
					}
					else {
						switch (count) {

						case 0: { replacex = atoi(buf[0].c_str()); count++; break; }
						case 1: { replacey = atoi(buf[0].c_str()); count++; break; }
						case 2: { replacenumber = atoi(buf[0].c_str()); count++; break; }
						case 3: { SEARCH = atoi(buf[0].c_str()); count++; break; }
						default: {
							for (int i = 0; i < buf.size(); i++) {
								arrinfile.push_back(atoi(buf[i].c_str())); count++;
							}
							COLUMS = buf.size();
							ROWS++;
						}
						}

					}
				}
				count = 0;
				twodimensional_array arr(rows, colums);
				vector<vector<int>> test(rows);
				int bufer = 0;
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < colums; j++) {
						test[i].push_back(textinfile[bufer]);
						bufer++;
					}
				}
				int numer = 0;
				vector<vector<int>>buff(ROWS);
				for (int i = 0; i < ROWS; i++) {
					for (int j = 0; j < COLUMS; j++) {
						buff[i].push_back(arrinfile[numer]);
						numer++;
					}
				}
				arr.SetArray(test);
				arr.print();
				arr.sorting();
				cout << "\nсортировка\n";
				arr.print();
				arr.replace(replacex, replacey, replacenumber);
				cout << "\nдобавление ("<<replacenumber<<")\n";
				arr.print();
				cout << "\nпоиск ("<<SEARCH<<")\n";
				arr.search(SEARCH);
				arr.print();
				twodimensional_array arr1;
				arr1.SetArray(buff);
				arr1.sorting();
				cout << "\nотсортированный первый массив\n";
				arr.print();
				cout << "\nотсортированный второй массив\n";
				arr1.print();
				arr.sorting();
				arr.Union(arr1);
				/*cout << "\nобъединение\n";
				arr.print();*/
				arr.intersection(arr1);
				/*cout << "\nпересечение\n";
				arr.print();*/
				
			}
			else { cout << "file is not open"; }
		}
	}
	}
	return 0;
}
