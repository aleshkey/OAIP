#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
template <typename T>
class AllSets {
	vector<T> REZ;
	vector<vector<T>> sets;
	vector<T> symmetrical_difference(vector<T> arr1, vector<T> arr2);
public:
	~AllSets();
	void PrintSets();
	void addition(vector<T> arr);
	vector<T> symmetric_difference_allsets();
};

template<typename T>
inline void AllSets<T>::PrintSets()
{
	for (int i = 0; i < sets.size(); i++) {
		for (int j = 0; j < sets[i].size(); j++) {
			cout << sets[i][j]<<" ";
		}
		cout << endl;
	}
}


template<typename T>
inline vector<T> AllSets<T>::symmetrical_difference(vector<T> arr1, vector<T> arr2)
{
	vector<T> rez;
	for (int i = 0; i < arr1.size(); i++) {
		int count = 0;
		for (int j = 0; j < arr2.size(); j++)
		{
			if (arr1[i] == arr2[j]) {
				count++;
			}
		}
		if (count == 0) {
			rez.push_back(arr1[i]);
		}

	}
	for (int i = 0; i < arr2.size(); i++) {
		int count = 0;
		for (int j = 0; j < arr1.size(); j++)
		{
			if (arr2[i] == arr1[j]) {
				count++;
			}
		}
		if (count == 0) {
			rez.push_back(arr2[i]);
		}

	}
	return rez;
}


template<typename T>
inline AllSets<T>::~AllSets()
{
	sets.clear();
	REZ.clear();
}


template<typename T>
inline void AllSets<T>::addition(vector<T> arr)
{

	arr.pop_back();
	sets.push_back(arr);
}

template<typename T>
inline vector<T> AllSets<T>::symmetric_difference_allsets()
{
	if (sets.size() > 1) {
		REZ = symmetrical_difference(sets[0], sets[1]);
		for (int i = 2; i < sets.size(); i++) {
			REZ = symmetrical_difference(REZ, sets[i]);
		}
		sort(REZ.begin(), REZ.end());
		auto element = unique(REZ.begin(), REZ.end());
		REZ.erase(element, REZ.end());
		if (REZ.size() == 0) {
			throw exception ("\nсимметрическая разность - пустое множество");
		}
		return REZ;
	}
	else throw exception("\nнекоректный ввод");
}
