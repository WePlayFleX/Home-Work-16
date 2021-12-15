#include <iostream>
#include <ctime>

using namespace std;

const int nMatrRow = 6;
const int nMatrCln = 8;

int main()
{
	srand(time(0));

	int aMatr[nMatrRow][nMatrCln] = { {0} };

	for (int i = 0; i < nMatrRow; i++)
	{
		for (int j = 0; j < nMatrCln; j++)
		{
			aMatr[i][j] = rand() % 50 - 25;
			cout << "\t" << aMatr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	int iMatrMaxNeg = 0;
	int MaxIndexI = 0, MaxIndexJ = 0;

	for (int i = 0; i < nMatrRow; ++i)
	{
		for (int j = 0; j < nMatrCln; ++j)
		{
			if (iMatrMaxNeg > aMatr[i][j])
			{
				iMatrMaxNeg = aMatr[i][j];
				MaxIndexI = i;
				MaxIndexJ = j;
			}
		}
	}
	cout << "Biggest negative element - " << iMatrMaxNeg << endl;
	cout << endl;

	int iMatrMinPos = 0;
	int MinIndexI = 0, MinIndexJ = 0;

	for (int i = 0; i < nMatrRow; ++i)
	{
		for (int j = 0; j < nMatrCln; ++j)
		{
			if (iMatrMinPos <= 0 || (iMatrMinPos > aMatr[i][j] > 0 && aMatr[i][j] > 0))
			{
				iMatrMinPos = aMatr[i][j];
				MinIndexI = i;
				MinIndexJ = j;
			}
		}
	}
	cout << "Smallest positive element - " << iMatrMinPos << endl;
	cout << endl;

	int temp = 0;
	temp = aMatr[MaxIndexI][MaxIndexJ];
	aMatr[MaxIndexI][MaxIndexJ] = aMatr[MinIndexI][MinIndexJ];
	aMatr[MinIndexI][MinIndexJ] = temp;

	for (int i = 0; i < nMatrRow; i++)
	{
		for (int j = 0; j < nMatrCln; j++)
		{
			cout << "\t" << aMatr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}

