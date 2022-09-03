
#include <iostream>
#include <locale.h> 
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	int** A = new int *[225];
	for (int i = 0; i < 225; ++i)
		A[i] = new int[2]; 
	int** B = new int *[225];
	for (int i = 0; i < 225; ++i)
		B[i] = new int[2]; 
	int i, j, ia, ib, element, moshchA, moshchB;
	//Ввод мощности и элементов графика А
	
		cout << "\n\nВведите мощность графика А : ";
		cin >> moshchA; cout << "\n\n";
		for (i = 0; i < moshchA; i++) {
			cout << (i + 1) << " кортеж графика А:\n";
			for (j = 0; j < 2; j++) {
				cout << "   " << (j + 1) << " компонента " << (i + 1) << " кортежа: ";
				cin >> element; A[i][j] = element;
			}

		}
	

	//Ввод мощности и элементов графика А
	
		cout << "\n\nВведите мощность графика B: ";
		cin >> moshchB; cout << "\n\n";

		for (i = 0; i < moshchB; i++) {
			cout << (i + 1) << " кортеж графика B :\n";
			for (j = 0; j < 2; j++) {
				cout << "   " << (j + 1) << " компонента " << (i + 1) << " кортежа: ";
				cin >> element; B[i][j] = element;
			}
		}
	

	// Меню
	cout << "\nВыберите операцию:\n 1 - Пересечение\n 2 - Объединение\n";
	cout << " 3 - Разность А и В\n 4 - Разность B и A\n 5 - Симметрическая разность\n";
	cout << " 6-дополнение А\n 7 - дополнение В\n 8 - Инверсия графика А\n 9 - Инверсия графика B\n";
	cout << " 10 - Композиция графиков А и В\n 11 - Композиция графиков B и A\n\n 0 - Выход\n\n\n";
	int key;
	cin >> key;
	puts("..........\n\n");

	switch (key) {

	case 1:     // Пересечение
	{
		int D[225][2];
		i = 0;

		//4.2-4.6
		for (ia = 0; ia < moshchA; ia++) {
			for (ib = 0; ib < moshchB; ib++) {
				if (A[ia][0] == B[ib][0] && A[ia][1] == B[ib][1]) {
					D[i][0] = A[ia][0];
					D[i][1] = A[ia][1];
					i++;
					ib = (moshchB - 1);
				}
			}
		}


		if (i == 0) {
			cout << "График D является пустым.\n\n\n";
		}
		else {
			//Вывод результата пересечения на экран
			cout << "График D: \n {";
			for (j = 0; j < i; j++) {
				cout << "<" << D[j][0] << "," << D[j][1] << ">, ";
			}
		}

		break;
	}

	case 2: 	// Объединение
	{

		int C[550][2];


		//(5.2)
		for (i = 0; i < moshchA; i++) {
			C[i][0] = A[i][0];
			C[i][1] = A[i][1];
		}

		//5.3-5.8
		for (ib = 0; ib < moshchB; ib++) {
			for (ia = 0; ia < moshchA; ia++) {
				if (A[ia][0] == B[ib][0] && A[ia][1] == B[ib][1]) {
					ia = (moshchA - 1);
				}
				else {
					if ((ia + 1) == moshchA) {
						C[i][0] = B[ib][0];
						C[i][1] = B[ib][1];
						i++;
					}
				}
			}
		}



		//Вывод результата объединения на экран
		cout << "График C: \n {";
		for (j = 0; j < i; j++) {
			cout << "<" << C[j][0] << "," << C[j][1] << ">, ";
		}
		cout << "\b\b}\n\n\n";


		break;
	}

	case 3: 	// Разность А \ В
	{
		int E[225][2];
		i = 0;

		//6.2-6.8
		for (ia = 0; ia < moshchA; ia++) {
			for (ib = 0; ib < moshchB; ib++) {
				if (A[ia][0] == B[ib][0] && A[ia][1] == B[ib][1]) {
					ib = (moshchB - 1);
				}
				else {
					if (ib == (moshchB - 1)) {
						E[i][0] = A[ia][0];
						E[i][1] = A[ia][1];
						i++;
					}
				}
			}
		}

		if (i == 0) {
			cout << "График E является пустым.\n\n\n";
		}
		else {
			//Вывод результата разности А\В на экран
			cout << "График E: \n {";
			for (j = 0; j < i; j++) {
				cout << "<" << E[j][0] << "," << E[j][1] << ">, ";
			}
			cout << "\b\b}\n\n\n";
		}

		break;
	}

	case 4:     // Разность B \ A
	{
		int F[225][2];
		i = 0;
		//7.2-7.8
		for (ib = 0; ib < moshchB; ib++) {
			for (ia = 0; ia < moshchB; ia++) {
				if (A[ia][0] == B[ib][0] && A[ia][1] == B[ib][1]) {
					ia = (moshchA - 1);
				}
				else {
					if (ia == (moshchA - 1)) {
						F[i][0] = B[ib][0];
						F[i][1] = B[ib][1];
						i++;
					}
				}
			}
		}

		if (i == 0) {
			cout << "График F является пустым.\n\n\n";
		}
		else {
			//Вывод результата разности В\А на экран
			cout << "График F: \n {";
			for (j = 0; j < i; j++) {
				cout << "<" << F[j][0] << "," << F[j][1] << ">, ";
			}
			cout << "\b\b}\n\n\n";
		}

		break;
	}

	case 5:     // Симметрическая разность
	{
		int G[550][2];
		//8.1
		int E[225][2];
		int Enum = 0;


		for (ia = 0; ia < moshchA; ia++) {
			for (ib = 0; ib < moshchB; ib++) {
				if (A[ia][0] == B[ib][0] && A[ia][1] == B[ib][1]) {
					ib = (moshchB - 1);
				}
				else {
					if (ib == (moshchB - 1)) {
						E[Enum][0] = A[ia][0];
						E[Enum][1] = A[ia][1];
						Enum++;
					}
				}
			}
		}
		//8.2
		int F[225][2];
		int Fnum = 0;

		for (ib = 0; ib < moshchB; ib++) {
			for (ia = 0; ia < moshchB; ia++) {
				if (A[ia][0] == B[ib][0] && A[ia][1] == B[ib][1]) {
					ia = (moshchA - 1);
				}
				else {
					if (ia == (moshchA - 1)) {
						F[Fnum][0] = B[ib][0];
						F[Fnum][1] = B[ib][1];
						Fnum++;
					}
			}
			}
		}


		//8.3
		for (i = 0; i < Enum; i++) {
			G[i][0] = E[i][0];
			G[i][1] = E[i][1];
		}

		for (j = 0; j < Fnum; j++, i++) {
			G[i][0] = F[j][0];
			G[i][1] = F[j][1];
		}


		if (i == 0) {
			cout << "График G является пустым.\n\n\n";
		}
		else {
			//Вывод результата симметрической разности на экран
			cout << "График G: \n {";
			for (j = 0; j < i; j++) {
				cout << "<" << G[j][0] << "," << G[j][1] << ">, ";
			}
			cout << "\b\b}\n\n\n";
		}

		break;
	}



	case 6: {		//дополнение А
		int** D = new int *[40000];
		for (int i = 0; i < 40000; ++i)
			D[i] = new int[2];
		int** U = new int *[40000];
		for (int i = 0; i < 40000; ++i)
			U[i] = new int[2];
		int count = 0, moshchD = 0;;
		//создание универсума
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				U[count][0] = i;
				U[count][1] = j;
				count++;
			}
		}
		//9.2
		for (int j = 0; j < 40000; j++) {
			count = 0;
			for (int i = 0; i < moshchA; i++) {
				if (A[i][0] == U[j][0] && A[i][1] == U[j][1])
					count++;
			}
			if (count == 0) {
				D[moshchD][0] = U[j][0];
				D[moshchD][1] = U[j][1];
				moshchD++;
			}
		}
		//выводим график на экран
		for (int i = 0; i < moshchD; i++) {
			cout << D[i][0] << "\t" << D[i][1] << "\n";
		}
		break;
	}

	case 7: {			//дополнение В
		int D[40000][2], U[40000][2], count = 0;
		//задаём универсум
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				U[count][0] = i;
				U[count][1] = j;
				count++;
			}
		}
		int moshchD = 0;
		//10.2
		for (int j = 0; j < 40000; j++) {
			count = 0;
			for (int i = 0; i < moshchB; i++) {
				if (B[i][0] == U[j][0] && B[i][1] == U[j][1])
					count++;
			}
			if (count == 0) {
				D[moshchD][0] = U[j][0];
				D[moshchD][1] = U[j][1];
				moshchD++;
			}
		}
		for (int i = 0; i < moshchD; i++) {
			cout << D[i][0] << "\t" << D[i][1] << "\n";
		}
		break;
	}


	case 8:     // Инверсия графика А
	{ //9.1
		int I[225][2];
		//9.2
		for (ia = 0; ia < moshchA; ia++) {
			I[ia][0] = A[ia][1];
			I[ia][1] = A[ia][0];
		}



		//Вывод результата инверсии графика А на экран
		cout << "График I: \n {";
		for (j = 0; j < moshchA; j++) {
			cout << "<" << I[j][0] << "," << I[j][1] << ">, ";
		}
		cout << "\b\b}\n\n\n";


		break;
	}

	case 9: 	// Инверсия графика B
	{//10.1
		int J[225][2];
		//10.2-10.6
		for (ib = 0; ib < moshchB; ib++) {
			J[ib][0] = B[ib][1];
			J[ib][1] = B[ib][0];
		}


		//Вывод результата инверсии графика B на экран
		cout << "График J: \n {";
		for (j = 0; j < moshchB; j++) {
			cout << "<" << J[j][0] << "," << J[j][1] << ">, ";
		}
		cout << "\b\b}\n\n\n";

		break;
	}

	case 10:     // Композирование А×В
	{//11.1
		int K[225][2];
		int moshchK = 0;
		//10.2-10.9
		for (ia = 0; ia < moshchA; ia++) {
			for (ib = 0; ib < moshchB; ib++) {
				if (A[ia][1] == B[ib][0]) {
					int count = 0;
					for (int i = 0; i < moshchK; i++) {
						if (K[i][0] == A[ia][0] && K[i][1] == B[ib][1]) {
							count++;
						}
					}
					if (count == 0) {
						K[moshchK][0] = A[ia][0];
						K[moshchK][1] = B[ib][1];
						moshchK++;
					}
				}
			}
		}

		//Вывод результата композирвоания графиков А и В на экран
		cout << "График K: \n {";
		for (i = 0; i < moshchK; i++) {
			cout << "<" << K[i][0] << "," << K[i][1] << ">, ";
		}
		cout << "\b\b}\n\n\n";

		break;
	}

	case 11:     // Композирование B×A
	{//12.1
		int M[225][2];
		int moshchM = 0;
		//12.2-2.9
		for (ib = 0; ib < moshchB; ib++) {
			for (ia = 0; ia < moshchA; ia++) {
				if (B[ib][1] == A[ia][0]) {
					int count = 0;
					for (int i = 0; i < moshchM; i++) {
						if (M[i][1] == A[ia][1] && M[i][0] == B[ib][0]) {
							count++;
						}
					}
					if (count == 0) {
						M[moshchM][0] = B[ib][0];
						M[moshchM][1] = A[ia][1];
						moshchM++;
					}
				}
			}
		}


		//Вывод результата композирвоания графиков В и А на экран
		cout << "График M: \n {";
		for (i = 0; i < moshchM; i++) {
			cout << "<" << M[i][0] << "," << M[i][1] << ">, ";
		}
		cout << "\b\b}\n\n\n";

		break;
	}

	}
}
