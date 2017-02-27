#pragma once

#include"CodeWord.h"
#include "Polynom.h"
#include <iostream>
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MeggetDecoderNew
{
public:
	//въвежда се n-дължината на димата
	int n;
	//въвежда се десеттчно чилсо 104
	int data;
	bool *Ytemp;

	MeggetDecoderNew(int n, int data, bool *yTemp);

	void Initialize();

	//ако първия път не се е получило У се шифтва на десно
	//генерира се полинома на У
	//У(х) се дели на g(x) и се получава синдром (остатък), ако е 0 значи е получено вярно съобщение
	//получения остатък се сравнява със остатъка на лидер x^n (00..01)
	//n пъти се се завърта това, ако не е получен остатъка на x^n се завърта още н пъти за да сравни с останалите остатъци
	//ако получим същия остатък, взимаме лидера и го шифтваме на ляво толкова колкото сме шифтвалина дясно
	//събираме двоичния шифтнат лидер с първоначално въведеното У
	//получаваме правилния вектор
	vector<bool> CheckCode();

private:
	Polynom PolynomG;

	//лидерите се преобразуват до вeктори 
	//след това се обръщат до полиноми
	vector<Polynom> polynoms;

	//полинома се дли на g(x) и остатъка се запива в residueLider[j]
	vector<Polynom> syndroms;

	//генерират се лидерите на комножествата
	int* LiderOfClasses(int countComn);
};
