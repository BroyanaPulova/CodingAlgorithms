#include "stdafx.h"
#include "MeggetDecoderNew.h"

MeggetDecoderNew::MeggetDecoderNew(int n, int data, bool *yTemp)
	:n(n), data(data), Ytemp(yTemp)
{
}

void MeggetDecoderNew::Initialize()
{
	//������� �� ����������� ��� ������� ������
	Polynom PolynomG = Polynom(data, n);

	int r = PolynomG.Data[0];
	//�������� k-���� ������ �� ���������, k=n-r
	int k = n - r;//r - �������� �� �������� G
				  //��������� �� ���� �� ������������� 
	int countComn = (n - 1) / 2;
	cout << endl;
	cout << "komnojestwata sa" << countComn << "na broi!" << endl;
	cout << endl;
	//��������� �� �������� �� �������������
	int *DecLiders = new int[countComn];//������������ ������ �� �������
	DecLiders = LiderOfClasses(countComn);

	//�������� �� ������������ �� �e����� 
	//���� ���� �� ������� �� ��������
	polynoms = vector<Polynom>();
	for (int i = 0; i < countComn; i++)
	{
		bitset<64> number = bitset<64>(DecLiders[i]);
		string binaryNumber = number.to_string().erase(0, 64 - n);;
		Polynom polynom = Polynom(binaryNumber.c_str(), binaryNumber.length());
		polynoms.push_back(polynom);
	}

	//�������� �� ��� �� g(x) � �������� �� ������ � residueLider[j]
	syndroms = vector<Polynom>();
	for (int i = 0; i < polynoms.size(); i++)
	{
		bool isExist = false;
		syndroms.push_back(polynoms[i].DiviterPolynome(PolynomG, isExist));
	}
	//���� ������� ������ �� �� �������� ��� �������� �� ��������� �� �(x) ��� g(x)
}

vector<bool> MeggetDecoderNew::CheckCode()
{
	Initialize();

	Polynom PolynomY = Polynom(Ytemp, n);
	bool SyndromExist = false;
	vector<Polynom> residePolynoms = vector<Polynom>();

	int RightShiftCounter = 0;

	while (SyndromExist != true)
	{
		if (RightShiftCounter >= n)
		{
			for (int i = 1; i < syndroms.size(); i++)
			{
				Polynom currentLider = syndroms[i];

				for (int j = 0; j < residePolynoms.size(); j++)
				{
					if (!(residePolynoms[j] == currentLider))
						continue;

					currentLider.ShiftArrayToLeft(RightShiftCounter);

					Polynom Y = Polynom(Ytemp, n);
					Polynom resultPolynom = currentLider + Y;

					cout << "pravilniq vector   " << endl;
					for (int i = 0; i < resultPolynom.Vector.size(); i++)
					{
						cout << resultPolynom.Vector[i] << " + ";
					}
					cout << endl;
				}
			}
		}

		//� �� ������ �� �����
		if (RightShiftCounter > 0)
		{
			PolynomY.ShiftArrayToRight();
		}
		RightShiftCounter++;

		bool isExist;
		Polynom reside = PolynomY.DiviterPolynome(PolynomG, isExist);

		if (isExist)
			return vector<bool>();

		if (reside == syndroms[0])
		{
			polynoms[0].ShiftArrayToLeft(RightShiftCounter - 1);

			Polynom Y = Polynom(Ytemp, n);
			Polynom resultPolynom = polynoms[0] + Y;

			return resultPolynom.Vector;

			SyndromExist = true;
		}
		else
		{
			residePolynoms.push_back(reside);
		}
	}
}

int * MeggetDecoderNew::LiderOfClasses(int countComn)
{
	int* DecLiders = new int[countComn];
	for (int i = 0; i < countComn; i++)
	{
		if (i >= 2)
		{
			DecLiders[i] = (2 * (DecLiders[i - 1])) - 1;
		}
		else if (i == 0)
		{
			DecLiders[i] = 1;
		}
		else if (i == 1)
		{
			DecLiders[i] = 3;
		}
		cout << "desettichnite lideri na klasowe sa:" << DecLiders[i] << endl;
	}

	return DecLiders;
}
