#include<iostream>
#include"SquareMatrix.h"
using namespace std;
template<typename Type>
void EnterArray(Matrix<Type>*, int);
template<typename Type>
void DisplayArray(Matrix<Type>*, int);
template<typename Type>
void RaceToAPower(Matrix<Type>&);
const int M = 256;
int main()
{

	Matrix<int>* a = new Matrix<int>[M]; Matrix<int> a1;
	int n;
	cout << "Enter the size of array:";
	cin >> n;
	system("pause");
	return 0;
}
template<typename Type>
void DisplayArray(Matrix<Type>* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].DisplayMatrix();
		cout << "------------\n";
	}
}
template<typename Type>
void EnterArray(Matrix<Type>* a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		a[i].EnterTheMatrix();
		cout << "Do you you want to race to a power?(enter 1 or 0)";
		cin >> k;
		if (k != 0) RaceToAPower(a[i]);
	}
	system("cls");
}
template<typename Type>
void RaceToAPower(Matrix<Type>& a)
{
	int p;
	cout << "Enter power:";
	cin >> p;
	for (int i = 0; i < p - 1; i++)
	{
		a = a * a;
	}
}