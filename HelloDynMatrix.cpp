// HelloDynMatrix.cpp:
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

using std::cout;
using std::setw;

int **Create(int m, int n, int a = -120, int b = 230);
void Destroy(int **x, int m);
void Show(int **x, int m, int n);
int Min(int **x, int m, int n);

void init();

int _tmain(int argc, _TCHAR *argv[])
{
	init();
	int **x;
	const int M = 5, N = 9;

	x = Create(M, N);
	Show(x, M, N);
	int min = Min(x, M, N);
	Destroy(x, M);
	return 0;
} // _tmain

int **Create(int m, int n, int a, int b)
{
	int **t = new int *[m];
	for (int i = 0; i < m; i++)
	{
		t[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			t[i][j] = a + rand() % (b - a + 1);
		} // for j
	}	 // for i

	return t;
} // Create

void Destroy(int **x, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete x[i];
	} // for i

	delete x;
} // Destroy

void Show(int **x, int m, int n)
{

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(6) << x[i][j];
		} // for j
		cout << "\n";
	} // for i
	cout << "\n";
} // Show

void init()
{
	srand(GetTickCount());
	SetConsoleOutputCP(1251);
} // init

int Min(int **x, int m, int n)
{
	int min = x[0][0];
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (min > x[i][j])
			{
				min = x[i][j];
			} //if
		}	 //for j
	}		  // for i
	cout << "\nMin: " << min << "\n";
	return min;
}