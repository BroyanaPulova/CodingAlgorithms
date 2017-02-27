#include "stdafx.h"
#include "ReedMuller.h"
#include <sstream>

ReedMuller::ReedMuller(int r, int m, bool *y)
	:r(r), m(m), Y(y)
{
	n = (int)(pow(2., (double)(m)));
	k = 0;
	chastno = 0;
	countErrors = 0;
	Initialize();
}

int ReedMuller::CalculateCharacteristicVector(GenerateMatrixElement currentElement, bool * Y, GenerateMatrixElement * binG, int n, int level, bool ** temp, bool ** H, bool * Add, int & exist)
{
	int countRows = currentElement.GetNotBuildCountElements(binG, level);
	bool** variacia = currentElement.GenerateCombinations(countRows);

	int countVariations = 1;

	if (countRows > 1) // за да не взима !X1 and X1, а само !X1 
		countVariations = (int)(pow(2., (double)(countRows)));

	Add = new bool[countVariations];

	for (int i = 0; i < countVariations; i++)
	{
		temp[i] = new bool[n];
		H[i] = new bool[n];
		int br = 0;
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = true;

			for (int index = 1, counter = 0; index < level; index++)
			{
				GenerateMatrixElement element = binG[index];

				if (currentElement.ExistBuildElement(index))
					continue;

				bool value = element.binaryValue[j];
				if (variacia[i][counter])
				{
					value = (element.binaryValue[j]) ^ 1;
				}

				temp[i][j] = (temp[i][j] & value);
				counter++;
			}

			H[i][j] = temp[i][j] & Y[j];

			if (H[i][j])
			{
				br++;
			}
		}

		if (br % 2 == 0 || br == 0)
		{
			Add[i] = false;
		}
		else
		{
			Add[i] = true;
			exist++;
		}
	}

	return countVariations;
}

bool ReedMuller::nextComb(int n, int k, int * comb)
{
	int i = k - 1;
	for (; i >= 0, comb[i] == n - k + i + 1; i--);
	if (i < 0) return false;
	comb[i]++;
	for (i++; i < k; i++) comb[i] = comb[i - 1] + 1;

	return true;
}

bool ReedMuller::nextVar(int n, int k, int * var)//май не се използва
{
	int i = k - 1;
	for (; i >= 0, var[i] == n; i--) var[i] = 1;
	if (i < 0) return false;
	var[i]++;
	return true;
}

void ReedMuller::Initialize()
{
	if (r == 0)
	{
		k = 1;
	}
	else if (r >= 1)
	{
		int temp = n;

		while (temp != 1)
		{
			temp = temp / 2;
			k++;
		}

		int tempR = r;

		while (tempR != 1)
		{
			int delimo = 1;
			int delitel = 1;
			int NewTempR = tempR;
			int tempK = k;

			while (NewTempR != 0)
			{
				delimo = delimo * tempK;
				tempK = tempK - 1;
				delitel = delitel * NewTempR;
				NewTempR = NewTempR - 1;
			}

			chastno = chastno + (delimo / delitel);

			tempR--;
		}

		k = k + chastno + 1;
	}

	//минимално разстояниш d=2^(m-r)
	int d = (int)(pow(2., (double)(m - r)));

	//брой греяки който попрашя (d-1)/2
	int countErrors = (d - 1) / 2;

	decG = new GenerateMatrixElement[k];//матрица с к реда
															   //Образуват се пръшите редове на матрицата
															   //G[0] = 2^2^m-1 =>(1<<(1<<m))-1
															   //G[i] = G[0]/(1<<(1<<(m-1))+1)   1 < m < i

	decG[0] = GenerateMatrixElement((__int64)(pow(2., (double)(n)) - 1), n, 0);

	for (int i = 1, j = m - 1; i < k, j >= 0; i++, j--)
	{
		__int64 stepen = (__int64)(pow(2., (double)(j)));
		__int64 value = decG[0].gValue / (__int64)(pow(2., (double)(stepen)) + 1);//2^2^j - 1

		decG[i] = GenerateMatrixElement(value, n, i);
	}
}

void ReedMuller::CreateMatrixs()
{
	nextRows = new GenerateMatrixElement[chastno];
	//В зашисимост от r се образушат останалите редове на матрицата

	//Mtemp = n=m,> Rtemp = k=r
	int Mtemp = m;
	int Rtemp = r;

	if (Mtemp > 1)
	{
		int* combinations = new int[r];

		while ((Rtemp < Mtemp || Mtemp > 1) && Rtemp > 1)
		{
			for (int i = 0; i < Mtemp; i++)
			{
				combinations[i] = i + 1;
			}

			int j = 0;

			do
			{
				cout << "kombinaciqta na redowete e : ";

				for (int i = 0; i < Rtemp; i++)
				{
					cout << combinations[i] << " ";

					if (i == 0)
					{
						nextRows[j] = GenerateMatrixElement();
						nextRows[j].n = n;
						nextRows[j].AddElement(decG[combinations[i]]);
					}

					else
					{
						nextRows[j].AddElement(decG[combinations[i]]);
					}
				}

				cout << nextRows[j].gValue << endl;

				cout << endl;

				for (int i = 0; i < chastno; i++)
				{
					cout << endl;
					cout << nextRows[i].gValue << endl;
				}

				j++;
			}

			while (nextComb(Mtemp, Rtemp, combinations) && j < chastno);

			Rtemp--;
		}
	}

	//добавяне на новите редове в матрицата
	for (int i = 0, j = (k - chastno); i < chastno, j < k; i++, j++)//i za noviq, j za stariq
	{
		decG[j] = nextRows[i];
		decG[j].rowNumber = j;
	}
}

string ReedMuller::Coding()
{
	//Всеки и-ти елемент от думата се умножава с всеки и-ти ред на матрицата
	bool *codingWord = new bool[n];

	for (int i = 0; i < n; i++)
	{
		codingWord[i] = 0;
	}

	stringstream str;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Y[i] == true)
			{
				codingWord[j] = ((codingWord[j]) ^ (decG[i].binaryValue[j]));//полуюените от умновението вектори се събират - това е кодираното съобщение
																			 //codingWord[j] ^= (binG[i][j]);
			}
			str << codingWord[j];
		}
	}

	return str.str();
}

vector<bool> ReedMuller::CalculateAllIncludeVectors(int countElements, GenerateMatrixElement* matrix)
{
	vector<bool> resultVector = vector<bool>(matrix[0].n);

	for (size_t i = 0; i < matrix[0].n; i++)
	{
		resultVector[0] = false;
	}

	for (size_t i = 0; i < countElements; i++)
	{
		if (!matrix[i].includeInFinalResult)
			continue;

		GenerateMatrixElement element = matrix[i];

		for (size_t j = 0; j < element.n; j++)
		{
			resultVector[j] = resultVector[j] ^ element.binaryValue[j];
		}
	}

	return resultVector;
}

string ReedMuller::Decoding()
{
	int countRows = (int)(pow(2., (double)(m - r)));
	bool **H = new bool*[countRows];
	bool *Add = new bool[countRows];

	//obrazuwame vektorite
	int count;
	bool **temp = new bool*[countRows];
	int index = k - 2;

	for (int i = k - 1; i >= 1; i--)
	{
		int exist = 0;
		int countVariations = CalculateCharacteristicVector(decG[i], Y, decG, n, m + 1, temp, H, Add, exist);
		decG[i].includeInFinalResult = exist >= (int)(countVariations / 2) + 1;
	}

	//prowerka za parwiq red 
	vector<bool> resultVector = CalculateAllIncludeVectors(k, decG);

	int countOnes = 0;
	for (auto i = resultVector.begin(); i != resultVector.end(); i++)
	{
		if ((*i))
			countOnes++;
	}

	stringstream str;

	if (countOnes >= n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			resultVector[i] = resultVector[i] ^ decG[0].binaryValue[i];

			str << resultVector[i] << "  ";
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			str << resultVector[i] << "  ";
		}
	}

	return str.str();
}
