#include "addition.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
void addition(string path)
{
	string str;
	getline(cin, str);
	ofstream fout;
	fout.open(path, ios::app);
	fout << endl << str;
}
