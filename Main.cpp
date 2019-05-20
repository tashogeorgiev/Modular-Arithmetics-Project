#include "pch.h"
#include <iostream>
#include <locale>
#include <cmath>
#include "modaritmetics.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "bulgarian");

	int operation;
	int *array, N;

	cout << "Въведете числото 'n' за остатъчния пръстен Zn: " << endl;
	cin >> N;
	array = new int[N];
	MakeArray(array, N);//Задача 1.

	cout << endl << "=====================================" << endl << endl;


	do {
		cout << "Изберете операция в остатъчния пръстен Z" << N << " : 1-събиране; 2-изваждане; 3-умножение; или 4 за да продължите." << endl;
		cin >> operation;
		if (operation == 1) {
			ModAdd(array, N);//Задача 2.
			cout << endl << "=====================================" << endl << endl;
		}
		else if (operation == 2) {
			ModSubtract(array, N);//Задача 3.
			cout << endl << "=====================================" << endl << endl;
		}
		else if (operation == 3) {
			int a, b;
			cout << "Изберете 2 числа:" << endl;
			cin >> a >> b;
			ModMultiply(array, a, b, N);//Задача 4.
			cout << endl << "=====================================" << endl << endl;
		}
		else if (operation == 4) {
			break;
		}
	} while (operation || 4);
	cout << endl << "=====================================" << endl << endl;


	int rows = 2;
	int cols = 0;
	int **div_array = new int*[rows];
	int counter = 1;
	//Създаваме масив от елементите които при умножение дават 1
	for (int a = 0; a < rows; a++) {
		div_array[a] = new int[N];
	}


	int& new_cols = cols;
	DivisionArray(div_array, array, N, rows, cols, new_cols);//Задача 5.
	cout << endl << "=====================================" << endl << endl;


	Reciprocal_Elements(div_array, rows, new_cols);//Задача 6.
	cout << endl << "=====================================" << endl << endl;


	Reciprocal_Bezu(N, array);//Задача 7.
	cout << endl << "=====================================" << endl << endl;


	ModDevide(div_array, array, N);//Задача 8.
	cout << endl << "=====================================" << endl << endl;


	int operation2 = 0;
	do {
		cout << "Изберете 1 за степенуване по първи начин, 2 за втори начин, или 3 за да продължите:" << endl;
		cin >> operation2;
		if (operation2 == 1) {
			ModPower1(array, N);//Задача 9.
			cout << endl << "=====================================" << endl << endl;
		}
		else if (operation2 == 2) {
			ModPower2(array, N);//Задача 10.
			cout << endl << "=====================================" << endl << endl;
		}
		else if (operation2 == 3) {
			cout << endl;
			break;
		}
		else if (operation2 > 3 || operation < 1) {
			cout << "Грешна стойност." << endl;
		}
	} while (operation2 != 3);



	if (FieldFn(N) == true) {
		cout << endl << "=====================================" << endl << endl;

		int root;
		cout << "Въведете число за да проверите дали е примитивен корен: " << endl;
		cin >> root;
		//Задача 12.
		if (PrimitiveRoot(div_array, array, N, root) == true) {
			cout << "Числото " << root << " e примитивен корен." << endl;
		}
		else {
			cout << "Числото " << root << " не e примитивен корен." << endl;
		}
		cout << endl;


		FindPrimitiveRoots(div_array, array, N);//Задача 13.
		cout << endl;


		DiscreteLog(div_array, array, N);//Задача 14.


		delete[] array;
		delete[] div_array;
		div_array = NULL;
		array = NULL;

		return 0;
	}
}
