#include "stdafx.h"
#include "SystemFormAndCheckMatrix.h"
#include <bitset>
#include <fstream>


SystemFormAndCheckMatrix::SystemFormAndCheckMatrix(int n, int k, int *riseMatrix)
	:N(n), K(k), B(riseMatrix)
{
	bool** matrix = new bool*[n];

	for (size_t i = 0; i < K; i++)
	{
		matrix[i] = new bool[N];
		bitset<64> number = bitset<64>(riseMatrix[i]);

		for (int j = N - 1; j >= 0; j--)
		{
			matrix[i][N - 1 - j] = number[j];
		}
	}

	initMatrix = new BinaryMatrix(matrix, n, k);
}

SystemMatrixs SystemFormAndCheckMatrix::GetResultMatrixs()
{
	InitializeMatrixs();
	ReversalMatrixs();

	return SystemMatrixs(initMatrix, new BinaryMatrix(H, N, N - K));
}

void SystemFormAndCheckMatrix::InitializeMatrixs()
{
	bool** A = initMatrix->Matrix;

	for (int i = 0; i < N; i++)//zapiswame desettichnite stalbowe e B
	{
		bitset<64> number;
		for (int j = 0; j < K; j++)
		{
			number.set(K - 1 - j, A[j][i]);
		}
		B[i] = number.to_ulong();
	}

	int br = 0;
	//ako ima k wektora s teglo 1
	for (int i = 0; i < N; i++) //razmestwane na stalbowe 
	{
		for (int j = 0; j <= K; j++)
		{
			int stepen = (int)(pow(2., (double)(j)));
			if (B[i] == stepen && br < K)
			{
				if (i == N - K - stepen + 1)
				{
					br++;
				}
				else
				{
					std::swap(B[i], B[N - K - stepen]);
					br++;
				}
			}
		}
	}

	while (br < K)
	{
		//ot B0 do Bk-1
		for (int i = 0, s = K - 1; i < K - 1, s >= 0; i++, s--)// s za stepenta, i za indeksa na B
		{
			if (B[i] != (int)(pow(2., (double)(s))))//ako w edini`nata matrica ima stalb s 2 edinici
			{
				for (int p = 0; p < K; p++)//reda na A = p
				{
					if (A[p][i] == 1 && p != i)
					{
						for (int j = 0; j < N; j++)//j = stalb na 2
						{
							A[p][j] = A[p][j] ^ A[i][j];// sabirame 2ta reda s edinichka w problemniq stalb
						}
						br++;
					}
				}
			}
		}
	}

	initMatrix->Matrix = A;
}

void SystemFormAndCheckMatrix::ReversalMatrixs()
{
	H = new bool*[N - K];
	bool** A = initMatrix->Matrix;

	for (int i = 0; i < N - K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0)
				H[j] = new bool[N];//n reda = i; n-k stalba = j

			if (j >= N - K - 1)
			{
				H[i][j] = i + K == j;
			}

			if (j < N - K && i < K)
			{
				H[j][i] = A[i][j + K];
			}
		}
	}
}

SystemMatrixs::SystemMatrixs(BinaryMatrix * system, BinaryMatrix * check)
	:system(system), check(check)
{
}
