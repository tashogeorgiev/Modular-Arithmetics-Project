#include "pch.h"
#include "modaritmetics.h"
#include <iostream>
#include <cmath>


void MakeArray(int *array, int N) {
	cout << "Елементите на остатъчния пръстен Z" << N << " са: " << endl;
	for (int a = 0; a <= N-1; a++) {
		array[a] = a;
		cout << array[a] << "   ";
	}
	cout << endl;
}

void ModAdd(int *array, int N) {
	int num1 = 0, num2 = 0;
	cout << "Изберете две числа: " << endl;
	cin >> num1 >> num2;
	if (num1 > array[N - 1] || num2 > array[N - 1] || num1 < 0 || num2 < 0) {
		do {
			cout << "Числата трябва да са от остатъчния пръстен Z" << N << ". Въведете ги пак." << endl;
			cin >> num1 >> num2;
		} while (num1 >= array[N - 1] || num2 >= array[N - 1] || num1 < 0 || num2 < 0);
	}

	int sum = num1 + num2;

	if (sum >= N) {
		cout << "Остатъкът по модул '" << N << "' е: " << sum - N << endl;
	}
	else if (sum < N) {
		cout << "Сумата е по малка от модула и няма остатък, резултатът е: " << sum << endl;
	}
	cout << endl;
}

void ModSubtract(int *array, int N) {
	int num1 = 0, num2 = 0;
	cout << "Изберете две числа: " << endl;
	cin >> num1 >> num2;
	if (num1 > array[N - 1] || num2 > array[N - 1] || num1 < 0 || num2 < 0) {
		do {
			cout << "Числата трябва да са от остатъчния пръстен Z" << N << ". Въведете ги пак." << endl;
			cin >> num1 >> num2;
		} while (num1 >= array[N - 1] || num2 >= array[N - 1] || num1 < 0 || num2 < 0);
	}

	int diff = num1 - num2;

	if (diff < 0) {
		cout << "Остатъкът по модул '" << N << "' e: " << N + diff << endl;
	}
	else if (diff >= 0) {
		cout << "Няма остатък, резултатът е : " << diff << endl;
	}
}

void ModMultiply(int *array, int num1, int num2, int N) {
	if (num1 > array[N - 1] || num2 > array[N - 1] || num1 < 0 || num2 < 0) {
		do {
			cout << "Числата трябва да са от остатъчния пръстен Z" << N << ". Въведете ги пак." << endl;
			cin >> num1 >> num2;
		} while (num1 >= array[N - 1] || num2 >= array[N - 1] || num1 < 0 || num2 < 0);
	}

	int result = num1 * num2;
	int temp_result = 0;
	int counter = 1;

	if (result >= N) {
		do {
			temp_result = N * counter;
			counter++;
			if (temp_result > result) {
				temp_result = N * (counter - 2);
				break;
			}
		} while (temp_result < result);
		cout << "Остатъкът по модул '" << N << "' e: " << result - temp_result << endl;
	}
	else if (result < N) {
		cout << "Няма остатък, резултатът е : " << result << endl;
	}
}

int DivisionArray(int ** div_array, int *array, int N, int rows, int cols, int& new_cols) {
	int counter = 1;
	for (int s = 1; s <= N - 1; s++) {
		for (int t = 1; t <= N - 1; t++) {
			for (int a = 1; a <= N - 1; a++) {
				if ((array[s] * array[t]) - (N*a) == 1) {
					counter++;
				}
			}
		}
	}
	cols = counter;
	new_cols = cols;
	div_array[0][0] = 1;
	div_array[1][0] = 1;
	int temp = 1;

	for (int s = 1; s <= N - 1; s++) {
		for (int t = 1; t <= N - 1; t++) {
			for (int a = 1; a <= N - 1; a++) {
				if ((array[s] * array[t]) - (N*a) == 1) {
					div_array[0][temp] = array[s];
					div_array[1][temp] = array[t];
					temp++;
				}
			}
		}
	}

	cout << "Двойките елементи на Z" << N << ", които при умножение дават 1 са : " << endl;
	for (int i = 0; i <= rows - 1; i++) {
		for (int j = 0; j <= cols - 1; j++) {
			cout << div_array[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	return new_cols;
}

void Reciprocal_Elements(int **div_array, int rows, int new_cols) {
	cout << "Реципрочнате сойности на елементите са: " << endl;
	int i = 1;
	int j = 0;

	do {
		cout << "Реципрочната стойност на " << div_array[i][j] << " е 1/" << div_array[i - 1][j] << endl;
		j++;
	} while (j < new_cols);

	cout << endl;
}

void Reciprocal_Bezu(int N,int *array) {
	int b=1000;

	do {
		cout << "Въведете число на което искате реципрочното: ";
		cin >> b;
	} while (b <= array[0] || b > array[N-1]);

		int prime_check = N;
		int c = b;
		while (prime_check != c){
			if (prime_check > c)
				prime_check -= c;
			else
				c -= prime_check;
		}
		int result1 = 0;
		int result2 = 0;

		if (prime_check == 1) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					result1 = (j*b) - (i*N);
					if (result1 == 1) {
						cout << j << "*" << b << " - " << i << "*" << N << " =  1 " << endl;
						result2 = j;
					}
				}
			}
			cout << "Реципрочното число е " << result2 << '.' << endl;
		}
		else if (prime_check != 1) {
			cout << "Числото " << b << " няма реципрочен елемент в Z" << N << endl;
		}

		cout << endl;
}

void ModDevide(int **div_array, int *array, int N) {
	int b = 10000;
	int a = 10000;

	do {
		cout << "Въведете числа от Zn които да се разделят: ";
		cin >> a >> b;
	} while ((b <= array[0] || b > array[N - 1]) && (a <= array[0] || a > array[N - 1]));

	int temp;

	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}

	int b2 = b;
	int cnt = 0;

	for (int i = 0; i <= N - 1; i++) {
		if (b2 == div_array[0][i]) {
			b2 = div_array[1][i];
			cnt++;
		}
	}

	int result = a * b2;
	int temp_result = 0;
	int counter = 1;

	if (cnt == 0) {
		cout << "-1" << endl;
	}
	else if (cnt > 0) {
		do {
			temp_result = N * counter;
			counter++;
			if (temp_result > result) {
				temp_result = N * (counter - 2);
				break;
			}
		} while (temp_result < result);

		cout << a << " : " << b << " = " << a << " * (1/" << b << ") = " << a << " * " << b2 << " = " << result - temp_result << endl;
	}
	cout << endl;
}

int ModMultiplyPower(int *array, int N, int b, int p) {
	int result = b * p;
	int temp_result = 0;
	int counter = 1;

	if (result >= N) {
		do {
			temp_result = N * counter;
			counter++;
			if (temp_result > result) {
				temp_result = N * (counter - 2);
				break;
			}
		} while (temp_result < result);
	}

	return (result - temp_result);
}
int AmodB(int N, int p) {
	int base = N;
	int counter = 2;
	int result = 0;
	if (p < N) {
		return p;
	}
		do {
			N *= counter;
			if (N > p) {
				N -= base;
				result = p - N;
				break;
			}
			else if (N < p) {
				N = base;
			}

			counter++;

		} while (N < p);
		return result;
}
void ModPower1(int *array, int N) {
	int b;
	int p;
	int power;
	int k=0;

	cout << "Въведете основата 'а' и степента 'm' за бързо степенуване по формулата 'a^m =n a^m mod k' : " << endl;
	cout << "a = ";
	cin >> b;
	cout << "m = ";
	cin >> p;

	for (int a = 2; a <= N-1; a++) {
		power = pow(b, array[a]-1);
		if (ModMultiplyPower(array, N, b, power) == 1) {
			cout << "Най-малкото естествено число k, за което a^k ="<< N <<" 1 e: " << a << endl;
			k = a;
			break;
		}
	}

	int counter = 2, counter2 = 2;
	int base = k, base2 = N;
	int result=0, result2=0;
	int k2 = N;

	do {
		k *= counter;
		if (k > p) {
			k -= base;
			result = p - k;
			break;
		}
		else if (k < p) {
			k = base;
		}
		counter++;
	} while (k < p);
	int power2 = pow(b, result);

	if (result == 0 && b < N) {
		cout << b << "^" << p << " =" << N << " " << b << "^" << p << "mod" << base << " =" << N << " " << b << "^" << result << " =" << N << " 1";
	}

	else if (power2 >= N) {
		do {
			k2 *= counter2;
			if (k2 > power2) {
				k2 -= base2;
				result2 = power2 - k2;
				break;
			}
			else if (k2 < power2) {
				k2 = base2;
			}
			counter2++;
		} while (k < p);

		cout << b << "^" << p << " =" << N << " " << b << "^" << p << "mod" << base << " =" << N << " " << b << "^" << result << " =" << N << " " << result2;
	}

	else if (power2 < N) {
		cout << b << "^" << p << " =" << N << " " << b << "^" << p << "mod" << base << " =" << N << " " << b << "^" << result << " =" << N << " " << power2;
	}

	cout << endl;
	cout << endl;
}
int DecimalToBinary(int n) {
	int binaryNumber = 0;
	int remainder, i = 1, step = 1;

	while (n != 0)
	{
		remainder = n % 2;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}
void ModPower2(int *array, int N) {
	int b;
	int p;

	cout << "Въведете основата 'а' и степента 'm' за бързо степенуване по формулата 'a, a^2, a^2^2, a^2^3 ... a^2^k' : " << endl;
	cout << "a = ";
	cin >> b;
	cout << "m = ";
	cin >> p;

	int binaryNumber = DecimalToBinary(p);
	cout << p << "(10) = ";

	int temp, temp2 = binaryNumber;
	int M = 0;

	do { // брой елементи за масива от бинарното число
		temp = temp2 % 10;
		temp2 /= 10;
		if (temp == 1) {
			M++;
		}
	} while (temp2 >= 1);

	int *arr_num = NULL; // масив от бинарното число
	arr_num = new int[M];

	int i = 1;
	int j = 0;
	temp = 0;
	temp2 = binaryNumber;

	do { // където има единица в бинарното число записваме съответната му стойност в десетично число
		temp = temp2 % 10;
		if (temp == 1) {
			temp *= i;
			arr_num[j] = temp;
			j++;
		}
		i *= 2;
		temp2 /= 10;
	} while (temp2 >= 1);

	for (int i = 0; i < M; i++) {
		if (i < M - 1)
			cout << " " << arr_num[i] << " + ";
		else if (i == M - 1)
			cout << arr_num[i] << " = ";
	}
	cout << binaryNumber << "(2)" << endl;

	int power;
	int elements_to_multiply = 1;

	for (int i = 0; i < M; i++) {
		power = pow(b, arr_num[i]);
		cout << b << "^" << arr_num[i] << " =" << N << " ";
		if (arr_num[i] >= 16) {//разбиваме степента за да не прехвърли най-големия integer
			power = pow(b, (arr_num[i] / 2));
			
			if (pow(AmodB(N, power), 2) < N) {
				if (b == 4 or b == 3) {
					elements_to_multiply *= 2 * AmodB(N, power);
					cout << AmodB(N, power) << endl;
				}
				else {
					elements_to_multiply *= AmodB(N, power);
					cout << AmodB(N, power) << endl;
				}
			}
			else {
				elements_to_multiply *= AmodB(N, pow(AmodB(N, power), 2));
				cout << AmodB(N, pow(AmodB(N,power), 2)) << endl;
			}
			continue;
		}

		if (power < N) {
			elements_to_multiply *= power;
			cout << power << endl;
		}
		else {
			elements_to_multiply *= AmodB(N, power);
			cout << AmodB(N, power) << endl;
		}

	}

	cout << "Резултат: ";
	if (elements_to_multiply >= N) {
		cout << AmodB(N, elements_to_multiply) << endl;
	}
	else {
		cout << elements_to_multiply << endl;
	}
	
	delete[] arr_num;
	arr_num = NULL;
}

int FieldFn(int N) {
	bool isPrime = true;

	for (unsigned int i = 2; i <= sqrt(N); i++) {
		if (N%i == 0) {
			isPrime = false;
			break;
		}
	}

	if (isPrime == true) {
		cout << "Пръстенът Z" << N << " е остатъчно поле F" << N << endl;
	}
	else {
		cout << "Пръстенът Z" << N << " не е остатъчно поле F" << N << endl;
	}

	cout << endl;
	return isPrime;
}

bool PrimitiveRoot(int **div_array, int *array, int N, int root) {
	bool check = true;
	for (int i = 2; i <= N - 2; i++) {
		int power;
		power = pow(root, i);
		if (AmodB(N, power) == root) {
			check = false;
			break;
		}
	}
	return check;
}

void FindPrimitiveRoots(int **div_array, int *array, int N) {
	cout << "Примитивните корени на F" << N << " са: ";
	int root;
	for (int i = 1; i < N-1; i++) {
		root = div_array[0][i];
		if (PrimitiveRoot(div_array, array, N, root) == 1) {
			cout << root << "   ";
		}
	}
}

void DiscreteLog(int ** div_array, int *array, int N) {
	int g, b;
	cout << "Въведете основа и елемент от F"<< N <<" за изчисляване на дискретен логаритъм: " << endl;
	cin >> g >> b;
	if (PrimitiveRoot(div_array, array, N, g) == true && (b >=array[0] && b <= array[N-1])) {
		if (b == 1) {
			cout << "Дискретен логаритъм от "<< b <<" при основа " << g << " е равен на = 0" << endl;
		}
		else if (b == g) {
			cout << "Дискретен логаритъм от " << b << " при основа " << g << " е равен на = 1" << endl;
		}
		else {
			for (int i = 2; i <= N - 2; i++) {
				int power = pow(g, i);
				if (AmodB(N, power) == b) {
					cout << "Дискретен логаритъм от " << b << " при основа " << g << " е равен на " << i << endl;
				}
			}
		}
	}
	else cout << endl << "-1" << endl;
}
