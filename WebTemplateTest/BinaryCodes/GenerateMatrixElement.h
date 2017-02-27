#pragma once
#include <bitset>
#include <vector>

using namespace std;

class GenerateMatrixElement
{
public:
	int rowNumber;
	int n;
	__int64 gValue;
	bool* binaryValue;
	bool includeInFinalResult;
	vector<GenerateMatrixElement> buildElements;

	GenerateMatrixElement();
	GenerateMatrixElement(__int64 value, int n, int rowNumber);
		
	void AddElement(GenerateMatrixElement element);
	void BuildBinaryValue();
	bool ExistBuildElement(int row);
	bool** GenerateCombinations(int count);
	int GetNotBuildCountElements(GenerateMatrixElement* matrix, int count);
};

