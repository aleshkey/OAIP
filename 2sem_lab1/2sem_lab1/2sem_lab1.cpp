#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "devide_into_words.h"
#include "addition.h"
using namespace std;
struct Marks {
	int physics;
	int math;
	int IT;
	int chemistry;
};
struct Student {
	string name;
	int year;
	string group;
	Marks marks;
	string average_score;
};
void GetData(Student *student, vector<string> words, int i) {
	if (words.size() == 8) {
		student[i].name = words[0];
		student[i].year = atoi(words[1].c_str());
		student[i].group = words[2];
		student[i].marks.physics = atoi(words[3].c_str());
		student[i].marks.math = atoi(words[4].c_str());
		student[i].marks.IT = atoi(words[5].c_str());
		student[i].marks.chemistry = atoi(words[6].c_str());
		student[i].average_score = words[7];
	}
}
void ShowData(Student student, string fname) {
	if (student.name != "") {
		ofstream fout;
		fout.open(fname, ios::app);
		fout << student.name << " " << student.year << " " << student.group << " " << student.marks.physics << " " << student.marks.math << " " << student.marks.IT << " " << student.marks.chemistry << " " << student.average_score << endl;
		fout.close();
	}
}
void ChangingData() {
	int strings=0;
	ifstream fin("input.txt");
	string str;
	while (!fin.eof()) {
		string buffer;
		getline(fin, buffer);
		strings++;
	}
	int  n;
	Student *student;
	student = new Student[strings];
	cout << "какую строку хотите заменить?\n";
	cin >> n;
	n--;
	cout << "введите новые данные\n";
	getline(cin, str);
	if (fin.is_open()) {
		system("cls");
		fin.clear();
		fin.seekg(0);
		for (int i=0; i<strings;i++){
				string buffer;
				getline(fin, buffer);
				vector<string> words = Devide_into_words(buffer);
			if (i != n) {
				GetData(student, words, i);
			}
		}
	}
	fin.close();
	remove("input.txt");
	ofstream fout;
	fout.open("input.txt", ios::app);
	for (int i = 0; i < strings; i++) {
		if (i == n) {
			fout << str<<endl;
		}
		else {
			if (student[i].name != "") {
				fout << student[i].name << " " << student[i].year << " " << student[i].group << " " << student[i].marks.physics << " " << student[i].marks.math << " " << student[i].marks.IT << " " << student[i].marks.chemistry << " " << student[i].average_score << endl;
			}
		}
	}
	fout.close();
}
int main()
{
	setlocale(LC_ALL, "rus");
	int menu;
	int strings = 0;
	string repeat = "yes";
	while (repeat != "no") {
		system("cls");
		cout << "1) Создание\n2)Просмотр\n3)Коррекция\n4)Решение индивидуального задания\n";
		cin >> menu;
		switch (menu) {
		case 1: {
			cout << "введите количество учеников, которые будут в журнале\n";
			string buffer;
			ofstream fout;
			fout.open("input.txt");
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "введите информацию о " << i + 1 << " ученике\n";
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
				Student *student;
				student = new Student[strings];
				int i = 0;
				while (!fin.eof()) {
					string buffer;
					getline(fin, buffer);
					vector<string> words = Devide_into_words(buffer);
					GetData(student, words, i);
					i++;
				}
				for (i = 0; i < strings; i++) {
					if (student[i].name != "") {
						cout.width(8);
						cout << student[i].name << "\t" << student[i].year << "\t" << student[i].group << "\t" << student[i].marks.physics << "\t" << student[i].marks.math << "\t" << student[i].marks.IT << "\t" << student[i].marks.chemistry << "\t" << student[i].average_score << endl;
					}
				}
				cout << "хотите провести ещё одну операцию?\n";
				string buffer;
				cin >> buffer;
				repeat = buffer;
			}
			else cout << "file is not open";
			fin.close();
			break;
		}
		case 3: {
			system("cls");
			cout << "1)Изменить данные\n2)Добавить данные\n";
			int kod;
			cin >> kod;
			if (kod == 2) {
				addition("input.txt");
			}
			else {
				if (kod == 1) {
					ChangingData();
				}
			}
			cout << "хотите провести ещё одну операцию?\n";
			string buffer;
			cin >> buffer;
			repeat = buffer;
			break;
		}
		case 4: {
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
				Student *student;
				student = new Student[strings];
				int i = 0;
				while (!fin.eof()) {
					string buffer;
					getline(fin, buffer);
					vector<string> words = Devide_into_words(buffer);
					GetData(student, words, i);
					i++;
				}
				for (i = 0; i < strings; i++) {
					if (student[i].name[0] == 'A' && (student[i].marks.math == 9 || student[i].marks.math == 8)) {
						ShowData(student[i],"output.txt");
					}
				}
				delete[]student;
				cout << "Ответ в файле output.txt\n";
				cout << "хотите провести ещё одну операцию?\n";
				string buffer;
				cin >> buffer;
				repeat = buffer;
			}
			else cout << "file is not open\n";
			fin.close();
		}
		}
	}
	return 0;
}
