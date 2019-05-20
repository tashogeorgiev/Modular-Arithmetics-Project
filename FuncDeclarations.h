#pragma once
using namespace std;

void MakeArray(int *array, int N);

void ModAdd(int *array, int N);

void ModSubtract(int *array, int N);

void ModMultiply(int *array, int num1, int num2, int N);

int DivisionArray(int ** div_array, int *array, int N, int rows, int cols,int& new_cols);

void Reciprocal_Elements(int **div_array, int rows, int new_cols);

void Reciprocal_Bezu(int N,int *array);

void ModDevide(int **div_array,int *array,int N);

void ModPower1(int *array, int N);

int ModMultiplyPower(int *array, int N, int b, int p);

int DecimalToBinary(int n);

void ModPower2(int *array, int N);

int AmodB(int N, int p);

int FieldFn(int N);

bool PrimitiveRoot(int **div_array, int *array, int N, int root);

void FindPrimitiveRoots(int **div_array, int *array, int N);

void DiscreteLog(int **div_array, int *array, int N);
