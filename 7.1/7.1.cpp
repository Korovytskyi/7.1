#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** z, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z, const int row1, const int row2, const int colCount);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 4;
	int High = 45;
	int rowCount = 9;
	int colCount = 7;

	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[colCount];
	Create(z, rowCount, colCount, Low, High);
	Print(z, rowCount, colCount);
	Sort(z, rowCount, colCount);
	Print(z, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		
	
	return 0;
}
void Create(int** z, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			z[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << z[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** z, int rowCount, int colCount)
{
	for (int i = 0; i < colCount - 1; i++)
		for (int j = 0; j < colCount - i - 1; j++)
			if ((z[0][j] > z[0][j + 1])
				|| (z[0][j] == z[0][j + 1] && z[1][j] > z[1][j + 1])
				|| (z[0][j] == z[0][j + 1] && z[1][j] == z[1][j + 1] && z[2][j] > z[2][j + 1]))
				Change(z, j, j + 1, rowCount);
}
void Change(int** z, int col1, int col2, int rowCount)
{
	int tmp;
	for (int row = 0; row < rowCount; row++)
	{
		tmp = z[row][col1];
		z[row][col1] = z[row][col2];
		z[row][col2] = tmp;
	}
}
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (z[i][j] % 2 == 0 && (i % 2 != 0))
			{
				S += z[i][j];
				k++;
				z[i][j] = 0;
			}
}