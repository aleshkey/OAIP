#include <iostream>
using namespace std;

void qsort(int *arr, int left, int right) {
	int i, j, x;
	i = left; j = right;
	x = arr[(left + right) / 2];
	do {
		while ((arr[i] < x) && (i < right))i++;
		while ((x < arr[j]) && (j > left)) j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i < j);

	if (left < j) qsort(arr, left, j);
	if (i < right) qsort(arr, i, right);
}

void bubble(int *arr, int n) {
	for (int j = 0; j < n; j++) {
		int num_min = j;
		for (int i = j; i < n; i++) {
			if (arr[i] < arr[num_min]) {
				num_min = i;
			}
		}
		swap(arr[j], arr[num_min]);
	}
}

void gnomesort(int *arr, int n) {
	int i = 1;
	while (i < n) {
		if (i == 0 || arr[i - 1] <= arr[i]) i++;
		else {
			swap(arr[i - 1], arr[i]);
			i--;
		}
	}
}

int main()
{
	int n;
	cout << "kol-vo:\n";
	cin >> n;
	int *arr;
	arr = new int[n];
	int now = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[now] = temp;
		now++;
	}
	int menu;
	cout << "1)bubble\n2)qsort\n3)gnomesort\n";
	cin >> menu;
	switch (menu)
	{
	case 1: {
		bubble(arr, n);
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		break;
	}
	case 2: {
		if (n > 1) {
			qsort(arr, 0, n - 1);
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
		}
		break;
	}
	case 3: {
		gnomesort(arr, n);
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		break;
	}
	default:
		break;
	}
	delete arr;
	return 0;
}

