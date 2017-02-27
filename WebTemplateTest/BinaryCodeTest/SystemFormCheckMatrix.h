
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include "BinaryMatrix1.h"

using namespace std;

class SystemMatrixs
{
public:
	SystemMatrixs(BinaryMatrix* system, BinaryMatrix* check);
	~SystemMatrixs()
	{
		delete system;
		delete check;
	}

	BinaryMatrix* system;
	BinaryMatrix* check;
};

class SystemFormAndCheckMatrix
{
public:
	SystemFormAndCheckMatrix(int n, int k, int *riseMatrix);
	SystemMatrixs GetResultMatrixs();

private:
	BinaryMatrix* initMatrix;
	int N;//������� �� ������  m
	int K;//������ � ��������� n

	int *B;
	bool **H;

	void InitializeMatrixs();
	void ReversalMatrixs();
};

