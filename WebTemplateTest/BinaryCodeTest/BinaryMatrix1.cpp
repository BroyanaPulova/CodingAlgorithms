#include "stdafx.h"
#include "BinaryMatrix1.h"

string BinaryMatrix::getString()
{
	stringstream stream;

	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < Columns; j++)
		{
			stream << Matrix[i][j];
		}
	}

	return stream.str();
}
