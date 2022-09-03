// artur.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
using namespace std;
int maximum(vector<int> arr) {
	if (arr.size() == 2) {
		if (arr[0] > arr[1]) {
			return arr[0];
		}
		else return arr[1];
	}
	else {
		if (arr.size() > 2) {
			vector<int> buffer;
			for (int i = 0; i < arr.size() / 2; i++) {
				buffer.push_back(arr[i]);
			}
			int temp1 = maximum(buffer);
			buffer.clear();
			for (int i = arr.size() / 2 + 1; i < arr.size(); i++) {
				buffer.push_back(arr[i]);
			}
			int temp2 = maximum(buffer);
			buffer.clear();
			buffer.push_back(temp1);
			buffer.push_back(temp2);
			return maximum(buffer);
		}
		else return arr[0];
	}
}
int main()
{
	int number;
	cin >> number;
	vector<int> arr(number);
	for (int i = 0; i < number; i++)cin >> arr[i];
	cout<<maximum(arr);
}
