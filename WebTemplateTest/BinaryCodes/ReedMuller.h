#pragma once

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include "GenerateMatrixElement.h"

using namespace std;

class ReedMuller
{
public:
	ReedMuller(int r, int m, bool *y);

private:
	int r;

	//изчислява се:
	//дължината на думата n=2^m
	int n;

	//m- за изюисляване на n
	int m;

	int chastno;

	//броя редове k = сума(i=0, r) от (m над r)
	int k;

	//минимално разстояниш d=2^(m-r)
	int d;

	//брой греяки който попрашя (d-1)/2
	int countErrors;

	bool **binG;
	bool* Y;
	GenerateMatrixElement *decG;
	GenerateMatrixElement* nextRows;

	int CalculateCharacteristicVector(GenerateMatrixElement currentElement, bool *Y, GenerateMatrixElement* binG, int n, int level, bool** temp, bool** H, bool* Add, int& exist);
	//образува комбинациите
	bool nextComb(int n, int k, int *comb);

	//образува вариациите
	bool nextVar(int n, int k, int *var);

	void Initialize();
	void CreateMatrixs();
	vector<bool> CalculateAllIncludeVectors(int countElements, GenerateMatrixElement* matrix);
	
public:
	//КОДИРАНЕ
	//Въвежда се думата която трбва да бъде кодирана (дълвината на думата трчбва да е развна на броя редове в матрицата)
	string Coding();

	//ДЕКОДИРАНЕ
	//Получаваме вектор У
	//ДЕКОДИРАНЕ ЗА r>1 и m>3
	//x1x2 = h1
	//x1 notx2 = h2
	//notx1 x2 = h3
	//notx1 notx2 = h4
	//Умножаваме всяко по получения У
	//за всяка произведение броим единиците
	//ако са четно запазваме 0
	//ако са нечетно запазваме 1
	//ако получените единица са четно х1 не участва
	//ако са нечетно х1 участва
	// правим това и за ,х2, х1
	//определяме кои редове участват и кои не 
	//Събираме всички редове които участват 
	//получаваме двоичен вектор S1
	//ако теглото не S1 е по-голямо от n/2
	//първия ред участва и го събираме с S1
	//ако не първия ред не участва
	//получения вектор е верния!!!
	string Decoding();
};