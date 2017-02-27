#include "stdafx.h"
#include "MeggetDecoderNew.h"

MeggetDecoderNew::MeggetDecoderNew(int n, int data, bool *yTemp)
	:n(n), data(data), Ytemp(yTemp)
{
}

void MeggetDecoderNew::Initialize()
{
	//Числото се преобразува във двоичен вектор
	Polynom PolynomG = Polynom(data, n);

	int r = PolynomG.Data[0];
	//Намираме k-броя редове на матрицата, k=n-r
	int k = n - r;//r - степента на лопинома G
				  //изчислява се броя на комножествата 
	int countComn = (n - 1) / 2;
	cout << endl;
	cout << "komnojestwata sa" << countComn << "na broi!" << endl;
	cout << endl;
	//генерират се лидерите на комножествата
	int *DecLiders = new int[countComn];//десеттичните лидери на класове
	DecLiders = LiderOfClasses(countComn);

	//лидерите се преобразуват до вeктори 
	//след това се обръщат до полиноми
	polynoms = vector<Polynom>();
	for (int i = 0; i < countComn; i++)
	{
		bitset<64> number = bitset<64>(DecLiders[i]);
		string binaryNumber = number.to_string().erase(0, 64 - n);;
		Polynom polynom = Polynom(binaryNumber.c_str(), binaryNumber.length());
		polynoms.push_back(polynom);
	}

	//полинома се дли на g(x) и остатъка се запива в residueLider[j]
	syndroms = vector<Polynom>();
	for (int i = 0; i < polynoms.size(); i++)
	{
		bool isExist = false;
		syndroms.push_back(polynoms[i].DiviterPolynome(PolynomG, isExist));
	}
	//този остатък трябва да се сравнява със остатъка от делението на У(x) със g(x)
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

		//У се шифтва на десно
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
