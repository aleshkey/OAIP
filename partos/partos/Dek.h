#pragma once
#include <vector>
class Dek
{
private:
	int numberofelements;
	std::vector<int> deque;
public:
	Dek(int numberofelements=0);
	void creation();
	void print();
	void PushBack(int number);
	void PushFront(int number);
	void PopBack();
	void PopFront();
};

