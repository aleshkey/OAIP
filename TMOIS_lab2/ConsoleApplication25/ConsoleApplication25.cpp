#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int moshchA; int moshchB;
	int way;
	cout << "\nВведите мощность A\n";
	cin >> moshchA;			//пользователь вводит мощность множества А
	vector <int> A(moshchA);
	cout << "\nвыберите способ задания множества: \n\t\t1.Перечислением\n\t\t2.Высказыванием\n";
	cin >> way;
	if (way == 1) {
		// задаем множество А
		cout << "\nВведите элементы множества А\n";
		for (int i = 0; i < moshchA; i++) cin >> A[i];

	}
	if (way == 2) {
		for (int x = 1; x < moshchA+1; x++) {
			A[x-1] = abs(x * x - x + 1);
			cout << A[x-1] << "\t";
		}
	}
	// задаем множесво В
	cout << "\nВведите мощность множества В\n";
	cin >> moshchB;			//пользователь вводит мощность множества В
	vector <int> B(moshchB);
	cout << "\nвыберите способ задания множества: \n\t\t1.Перечислением\n\t\t2.Высказыванием\n";
	cin >> way;
	if (way == 1) {
		cout << "\nВведите элементы множества B\n";
		for (int i = 0; i < moshchB; i++) cin >> B[i];
	}
	if (way == 2) {
		for (int x = 1; x < moshchB+1; x++) {
			B[x-1] = abs(2 * (x*x -11));
			cout << B[x-1] << "\t";
		}
	}
	//осуществляем выбор операции
start:
	cout << "\nВыберите операцию: \n1. Пересечение\n2. Объединение\n3.Разность A и B\n4.Разность B и A\n5.Симметрическая разность множеств А и В\n6.Дополнение множества A\n7.Дополнение множества B\n8. Декартово Произведение A и B\n9.Декартово Произведение B и A\n";
	int key;
	cin >> key;
	switch (key) {
		//пересечение множеств
	case 1: {
		vector <int> D; //создаем множество д
		int i, j;
		for (i = 0; i < moshchA; i++) { // выбираем каждый элемент А и проверяем последний ли он
			for (j = 0; j < moshchB; j++) { //выбираем каждый элемент В
				if (A[i] == B[j]) //проверяем равны ли выбранные элементы
					D.push_back(A[i]);  //если равны, добавляем выбранный элемнт А в Д
			}
		}
		for (i = 0; i < D.size(); i++) cout << D[i] << "\t"; //выводим Д
		break;
	}
			//объединение
	case 2:
	{
		int x = 0;
		vector <int> C(moshchA); //создаем множество С
		for (int i = 0; i < moshchA; i++) C[i] = A[i]; //копируем каждый элемент А в С
		for (int i = 0; i < moshchB; i++) { //выбираем каждый элемент В и проверяем последний ли он
			for (int j = 0; j < C.size(); j++) { //выбираем каждый элемент 
				if (B[i] != C[j]) { //проверяем равны ли выбранные элементы
					x += 1;
				}
			}
			if (x == C.size()) //если нет совпадений выбранного В и всех элементов С, добавляем этот элемент в С
				C.push_back(B[i]);
			x = 0;
		}
		for (int i = 0; i < C.size(); i++) cout << C[i] << "\t"; //выводим множество С
		break;
	}
	//разность А и В
	case 3: {
		int sch = 0;
		vector <int> E; //создаём пустое множество
		for (int i = 0; i < moshchA; i++) { //выбираем элементы А
			for (int j = 0; j < moshchB; j++) //выбираем элементы В
				if (A[i] != B[j]) //если выбранные элементы равны, пропускаем блок и выбираем следующий элемент В
				{
					sch += 1;
				}
			if (sch == moshchB) E.push_back(A[i]); sch = 0; //если выбранные элементы не равны, добавляем выбранный эл А в множество Е
		}
		for (int i = 0; i < E.size(); i++) //выводим элементы множества Е
			cout << E[i] << "\t";
		break; }

	case 4: {
		//разность В и А
		vector <int> F; //создаем пустое множество
		int sch = 0;
		for (int i = 0; i < moshchB; i++) { //выбираем элементы В
			for (int j = 0; j < moshchA; j++) //выбираем элементы А
				if (B[i] != A[j])//если выбранные элементы равны, пропускаем блок и выбираем следующий элемент В
				{
					sch += 1;
				}
			if (sch == moshchA) F.push_back(B[i]); sch = 0; //если выбранные элементы не равны, добавляем выбранный эл А в множество Е
		}
		for (int i = 0; i < F.size(); i++) cout << F[i] << "\t";//выводим элементы множества Е
		break;
	}
	case 5: {
		//Симметрическая разность множеств A и B.
		int sch = 0;
		vector <int> E; //находим разность А и В
		for (int i = 0; i < moshchA; i++) {
			for (int j = 0; j < moshchB; j++)
				if (A[i] != B[j])
				{
					sch += 1;
				}
			if (sch == moshchB) E.push_back(A[i]); sch = 0;
		}
		vector <int> F; //находим разность В и А
		for (int i = 0; i < moshchB; i++) {
			for (int j = 0; j < moshchA; j++)
				if (B[i] != A[j])
				{
					sch += 1;
				}
			if (sch == moshchA) F.push_back(B[i]); sch = 0;
		}
		int x = 0; //находим объединение разностей
		vector <int> G(E.size());
		for (int i = 0; i < E.size(); i++) G[i] = E[i];
		for (int i = 0; i < F.size(); i++) {
			for (int j = 0; j < G.size(); j++) {
				if (F[i] != G[j]) {
					x += 1;
				}
			}
			if (x == G.size())
				G.push_back(F[i]);
			x = 0;
		}
		for (int i = 0; i < G.size(); i++) cout << G[i] << "\t"; //выводим симметрическую разность
		break;
	}

	case 6: {
		//Дополнение множества A
		vector <int> U; //создаём множество универсума
		int x = 1; //присваиваем х значение 1
		while (x <= 200) { //проверяем больше ли х двухсот
			U.push_back(x); //добавляем х в универсум
			x++; //увеличиваем х на 1
		}
		int sch = 0;
		vector <int> H; //создаём пустое множество
		for (int i = 0; i < U.size(); i++) { //выбираем элементы из универсума
			for (int j = 0; j < A.size(); j++) { //выбираем элементы из множества А
				if (U[i] != A[j]) { sch++; }; //сравниваем выбранные элементы
			}
			if (sch == A.size()) { //если не равны, добавляем выбранный элемент универсума в множество Н
				H.push_back(U[i]);
			}
			sch = 0;
		}
		for (int i = 0; i < H.size(); i++) cout << H[i] << "\t"; //выводим множество Н
		break;
	}
	case 7: {
		//Дополнение множества B.
		vector <int> U; //создаем множество универсума
		int x = 1;//присваиваем х значение 1
		while (x <= 200) { //проверяем больше ли х 200
			U.push_back(x); //добавляем х в универсум
			x++;//увеличиваем х на 1
		}
		int sch = 0;
		vector <int> K; //создаем пустое множество 
		for (int i = 0; i < U.size(); i++) { //выбираем элементы универсума
			for (int j = 0; j < B.size(); j++) { //выбираем элементы множества В
				if (U[i] != B[j]) sch++; //сравниваем выбранные элементы
			}
			if (sch == B.size()) { K.push_back(U[i]); } //если не равны, добавляем выбранный элемент в множество К 
			sch = 0;
		}
		for (int i = 0; i < K.size(); i++) cout << K[i] << "\t"; //выводим множество К
		break;
	}
	case 8: {
		//Декартово произведение множеств A и B.
		vector <vector <int>> L;//создаем пустое множество L 
		L.assign(moshchA*moshchB, vector<int>(2));
		int n = 1;

		for (int i = 0; i < moshchA; i++) { //создаем n-нный кортеж и выбираем элементы А
			for (int j = 0; j < moshchB; j++) { //выбираем элементы В
				L[i*moshchB + j][0] = A[i]; //присваиваем первому элементу кортежа значение выбранного элемента А
				L[i*moshchB + j][1] = B[j]; //присваиваем второму элементу кортежа значение выбранного элемента В
				n++;
			}
		}
		for (n = 0; n < moshchA; n++) { //выводим множество кортежей
			for (int j = 0; j < moshchB; j++) {
				cout << L[n*moshchB + j][0] << "\t";
				cout << L[n*moshchB + j][1] << "\n";
			}
		}
		break;
	}
	case 9: {
		//Декартово произведение множеств B и A.
		vector <vector <int>> Z; //создаем пустое множество Z
		Z.assign(moshchA*moshchB, vector<int>(2));
		int n = 1;

		for (int i = 0; i < moshchB; i++) { //создаем n-нный кортеж и выбираем элементы B
			for (int j = 0; j < moshchA; j++) {
				Z[i*moshchA + j][0] = B[i];//присваиваем первому элементу кортежа значение выбранного элемента B
				Z[i*moshchA + j][1] = A[j];//присваиваем второму элементу кортежа значение выбранного элемента A
				n++;
			}
		}
		for (n = 0; n < moshchB; n++) {//выводим множество кортежей
			for (int j = 0; j < moshchA; j++) {
				cout << Z[n*moshchA + j][0] << "\t";
				cout << Z[n*moshchA + j][1] << "\n";
			}
		}
		break;
	}
	return 0;
	}
}






