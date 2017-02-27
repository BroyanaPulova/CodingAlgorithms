#pragma once

#include <vector>
#include "CodeWord.h"

using namespace std;

class Polynom
{
public:
	vector<int> Data;
	vector<bool> Vector;

	Polynom();
	Polynom(vector<int> data);
	Polynom(bool* array, int length);
	Polynom(const char* array, int length);
	Polynom(int data, int wordSize);

	Polynom DiviterPolynome(Polynom polynom, bool& isExit);

	void ShiftArrayToRight();
	void ShiftArrayToLeft(int RightShiftCounter);

	bool operator==(const Polynom& x)
	{
		if (this->Data.size() != x.Data.size())
			return false;

		for (int i = 0; i < this->Data.size(); i++)
		{
			if (x.Data[i] != this->Data[i])
				return false;
		}

		return true;
	}

	Polynom operator+(const Polynom& x)
	{
		bool *array = new bool[Vector.size()];
		for (int i = 0; i < Vector.size(); i++)
		{
			array[i] = (Vector[i]) ^ (x.Vector[i]);
		}

		std::reverse(&array[0], &array[Vector.size()]);

		return Polynom(array, Vector.size());
	}

private:
	void GeneratePolynomByArray(bool *array, int length, bool isReverse = true);
};

