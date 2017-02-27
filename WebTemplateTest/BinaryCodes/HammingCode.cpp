#include "stdafx.h"
#include "HammingCode.h"


HammingResult::HammingResult(bool * y, int corectSyndrom)
	:Y(y), CorectSyndrom(corectSyndrom)
{
}

HammingCode::HammingCode(int r, bool *y)
	: R(r), Y(y)
{
	n = (int)(pow(2., (double)(r)) - 1);
	//��������� �� k=n-r
	k = n - r;
	// O������� �� �(n-k;n) � � �������� �� ����������� � ��������� ��� �� ���������� ������� ����� �� 1 �� n, 
	// �� �� �� ������ � � ���������� ����� �� ���������� ���������� (�� �� � ����� �� �� �����)

	H = new bool *[n];
	for (int i = 0; i < n; i++)
	{
		boost::dynamic_bitset<> number(n - k, i + 1);
		H[i] = new bool[n - k];
		for (int j = 0; j < n - k; j++)
		{
			H[i][j] = number[n - k - 1 - j];//na obratno
		}
	}
}

HammingResult HammingCode::CheckCode()
{
	CalculateSyndroms();

	int syndromDec = CalculateDecSyndrom();
	bool *Result = new bool[n];

	// ��� �������� � = 0, ��������� ������ ���� ������
	if (syndromDec == 0)
	{
		for (int i = 0; i < n; i++)
			Result[i] = Y[i];
	}
	// a�� � �������� �� ����, �������� � � ��������� �� � ����� �� ��������
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i + 1 != syndromDec)
				Result[i]= Y[i];

			else if (i + 1 == syndromDec && Y[i] == false)
				Result[i] = true;

			else if (i + 1 == syndromDec && Y[i] == true)
				Result[i] = false;
		}
	}

	return HammingResult(Result, syndromDec);
}

void HammingCode::CalculateSyndroms()
{
	bool *AND = new bool[n];
	Syndrom = new bool[n - k];

	for (int i = n - k - 1; i >= 0; i--)//reda na H
	{
		for (int j = 0; j < n; j++)//stalba na H
		{
			AND[j] = H[j][i] & Y[j];
		}
		int count = 0;
		for (int t = 0; t < n; t++)
		{
			if (AND[t] == 1)
			{
				count++;
			}
		}
		Syndrom[i] = count % 2 != 0;
	}
}

int HammingCode::CalculateDecSyndrom()
{
	bitset<64> number;
	for (int i = 0; i < n - k; i++)
	{
		number.set(i, Syndrom[i]);
	}

	return number.to_ulong();
}

