#include "Dek.h"
#include <iostream>
#include <vector>
using namespace std;
Dek::Dek(int numberofelements)
{
	this->numberofelements = numberofelements;
}

void Dek::creation()
{
	for (int i = 0; i < numberofelements; i++) {
		int temp;
		cin >> temp;
		deque.push_back(temp);
	}
}

void Dek::print()
{
	for (int i = 0; i < numberofelements; i++) {
		cout << deque[i] << " ";
	}
}

void Dek::PushBack(int number)
{
	deque.push_back(number);
	numberofelements++;
}


void Dek::PushFront(int number)
{
	vector<int> buffer;
	buffer.push_back(number);
	for (int i = 0; i < numberofelements; i++) {
		buffer.push_back(deque[i]);
	}
	deque.clear();
	numberofelements++;
	for (int i = 0; i < numberofelements; i++) {
		deque.push_back(buffer[i]);
	}
}

void Dek::PopBack()
{
	deque.pop_back();
	numberofelements--;
}

void Dek::PopFront()
{
	vector<int> buffer;
	for (int i = numberofelements-1; i >=0; i--) {
		buffer.push_back(deque[i]);
	}
	deque.clear();
	buffer.pop_back();
	numberofelements--;
	for (int i = numberofelements-1; i >=0; i--) {
		deque.push_back(buffer[i]);
	}
}

