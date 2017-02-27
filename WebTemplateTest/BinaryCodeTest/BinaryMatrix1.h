#pragma once
#include <string>
#include <sstream>

using namespace std;

struct BinaryMatrix
{
public:
	BinaryMatrix(bool** matrix, long int columns, long int rows)
		:Matrix(matrix), Columns(columns), Rows(rows)
	{
	}

	string getString();

	bool** Matrix;
	long int Columns;
	long int Rows;
};

