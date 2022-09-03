#include <iostream>
#include<string>
#include "Sets.h"
#include <fstream>
#include <sstream>
#include "Divide_into_words.h"
#include "Check.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 4; i++) {
		stringstream ss;
		ss << i;
		string str = ss.str();
		string path = "Test" + str + ".txt";
		cout << "\n\n------------------------test-"<<i+1<< "--------------------\n\n";
		ifstream fin(path);
		AllSets<string> sets;
		string emptystring;
		vector<string> set;
		while(!fin.eof()) {
			string STR;
			getline(fin, STR);
			set = divide_into_words(STR);
			set = Check(set);
			sets.addition(set);
		}
		vector<string> rez;
		cout << "начальные множества\n\n--------------------------------------------------\n\n";
		sets.PrintSets();
		try
		{
			rez = sets.symmetric_difference_allsets();
			cout << "\n\n--------------------------------------------------\n\nсимметрическая разность множеств\n\n";
			for (int i = 0; i < rez.size(); i++) {
				cout << rez[i] << " ";
			}
			cout << "\n";
		}
		catch (const std::exception &ex)
		{
			cout << ex.what();
		}
		cout << "\n\n";
		
	}
	return 0;
}

