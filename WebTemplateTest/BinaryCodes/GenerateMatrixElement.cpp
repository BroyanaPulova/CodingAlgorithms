#include "stdafx.h"
#include "GenerateMatrixElement.h"


GenerateMatrixElement::GenerateMatrixElement()
	:gValue(0), includeInFinalResult(false)
{
}

GenerateMatrixElement::GenerateMatrixElement(__int64 value, int n, int rowNumber)
	: gValue(value), n(n), rowNumber(rowNumber), includeInFinalResult(false)
{
	buildElements = vector<GenerateMatrixElement>();
	BuildBinaryValue();
}

void GenerateMatrixElement::AddElement(GenerateMatrixElement element)
{
	buildElements.push_back(element);
	gValue = gValue == 0 ? element.gValue : gValue & element.gValue;
	BuildBinaryValue();
}

void GenerateMatrixElement::BuildBinaryValue()
{
	binaryValue = new bool[n];
	bitset<64> tempValue(gValue);

	for (int j = 0; j < n; j++)
	{
		binaryValue[n - j - 1] = tempValue[j];
	}
}

bool GenerateMatrixElement::ExistBuildElement(int row)
{
	if (row == rowNumber)
		return true;

	for (auto i = buildElements.begin(); i != buildElements.end(); i++)
	{
		if ((*i).rowNumber == row)
			return true;
	}

	return false;
}

int GenerateMatrixElement::GetNotBuildCountElements(GenerateMatrixElement * matrix, int count)
{
	int countelements = 0;
	for (int i = 1; i < count; i++) //заради единичния вектор е -1
	{
		if (matrix[i].buildElements.size() == 0)
			countelements++;
	}

	int countBuildElemnets = this->buildElements.size();

	if (countBuildElemnets == 0)
		countBuildElemnets++;

	countelements = countelements - countBuildElemnets;

	return countelements;
}

bool ** GenerateMatrixElement::GenerateCombinations(int count)
{
	int size = (int)(pow(2., (double)(count)));

	bool **variacia = new bool*[size];

	for (int i = 0; i < size; i++)
	{
		variacia[i] = new bool[count];
		bitset<64> number = bitset<64>(size - i);
		for (int j = 0; j < count; j++)
		{
			variacia[i][j] = number[j];
		}
	}

	return variacia;
}
