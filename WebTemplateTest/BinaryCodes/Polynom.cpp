#include "stdafx.h"
#include "Polynom.h"

Polynom::Polynom()
{
}

Polynom::Polynom(vector<int> data)
{
	Data = vector<int>(data);
}

Polynom::Polynom(bool * array, int length)
{
	Data = vector<int>();
	Vector = vector<bool>();

	GeneratePolynomByArray(array, length);
}

Polynom::Polynom(const char * array, int length)
{
	Vector = vector<bool>();
	Data = vector<int>();

	for (int i = length - 1; i >= 0; i--)
	{
		bool value = array[i] == '1';
		Vector.push_back(value);

		if (!value)
			continue;

		Data.push_back(i);
	}

	std::reverse(Vector.begin(), Vector.end());
}

Polynom::Polynom(int data, int wordSize)
{
	Data = vector<int>();
	Vector = vector<bool>();

	CodeWord result = CodeWord();
	result.AddValue(data);
	string BinaryValue = result.GetBinaryValue(wordSize);

	for (int i = BinaryValue.length() - 1; i >= 0; i--)
	{
		bool Value = BinaryValue[i] == '1' ? true : false;
		Vector.push_back(Value);

		if (!Value)
			continue;

		Data.push_back(i);
	}

	std::reverse(Vector.begin(), Vector.end());
}

Polynom Polynom::DiviterPolynome(Polynom polynom, bool & isExit)
{
	int left = polynom.Data.size();
	int right = Data.size();

	vector<int> PolynomG = polynom.Data;
	vector<int> tempPolynom = vector<int>(Data);
	vector<int> devPolynom;

	while (true)
	{
		int diviter = tempPolynom[0] - PolynomG[0];

		if (diviter < 0)
			break;

		int *resultPolynom = new int[left];

		for (int i = 0; i < left; i++)
		{
			resultPolynom[i] = PolynomG[i] + diviter;
		}

		devPolynom = vector<int>();

		for (int i = 0; i < left; i++)
		{
			bool exist = false;
			for (int s = 0; s < right; s++)
			{
				if (tempPolynom[s] == resultPolynom[i])
				{
					exist = true;
					tempPolynom[s] = -1;
					break;
				}
				else if (tempPolynom[s] > resultPolynom[i])
				{
					devPolynom.push_back(tempPolynom[s]);
					tempPolynom[s] = -1;
				}
				else if (tempPolynom[s] != -1)
					break;
			}

			if (exist)
				continue;
			else
				devPolynom.push_back(resultPolynom[i]);
		}

		for (size_t i = 0; i < right; i++)
		{
			if (tempPolynom[i] != -1)
				devPolynom.push_back(tempPolynom[i]);
		}

		right = devPolynom.size();
		tempPolynom = vector<int>(devPolynom);
	}
	for (auto i = 0; i < devPolynom.size(); i++)
	{
		cout << "ostataka ot delenieto e:" << tempPolynom[i] << endl;
	}
	if (devPolynom.size() != 0)
	{
		isExit = false;
		return Polynom(tempPolynom);
	}
	else if (devPolynom.size() == 0)
	{
		cout << "vavedeno e wqrno saobshtenie" << endl;
		for (int i = 0; i < Data.size(); i++)
		{
			cout << Data[i] << "  ";
		}

		isExit = true;
		return Polynom(vector<int>());
	}
}

void Polynom::ShiftArrayToRight()
{
	int length = Vector.size();
	bool last = Vector[0];
	bool* result = new bool[length];
	vector<bool> resultVector = vector<bool>(length);
	for (int i = 0; i < length - 1; i++)
	{
		resultVector[i] = Vector[i + 1];
	}

	resultVector[length - 1] = last;

	std::reverse(resultVector.begin(), resultVector.end());

	for (int i = 0; i < length; i++)
	{
		result[i] = resultVector[i];
	}

	GeneratePolynomByArray(result, length);
}

void Polynom::ShiftArrayToLeft(int RightShiftCounter)
{
	int length = Vector.size();
	bool* LeftArray = new bool[length];
	int LeftShiftCounter = 0;

	while (LeftShiftCounter != RightShiftCounter)
	{
		bool tempLider = Vector[0];
		for (int i = 1; i < length; i++)
		{
			LeftArray[i - 1] = Vector[i];
		}

		LeftArray[length - 1] = tempLider;
		LeftShiftCounter++;
	}

	std::reverse(&LeftArray[0], &LeftArray[length]);

	GeneratePolynomByArray(LeftArray, length);

	cout << "wektora sled shift na lqwo e:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << LeftArray[i];
	}
	cout << endl;
}

void Polynom::GeneratePolynomByArray(bool * array, int length, bool isReverse)
{
	Vector.clear();
	Data.clear();

	if (isReverse)
	{
		for (int j = length - 1; j >= 0; j--)
		{
			Vector.push_back(array[j]);
			if (!array[j])
				continue;

			Data.push_back(j);
		}
	}
}
