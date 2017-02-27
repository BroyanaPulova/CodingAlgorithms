#pragma once

// HammingCode.cpp : Defines the entry point for the console application.
// МОЖЕ ДА СЕ ДОПИШЕ И РАЗШИРЕН АЛГОРИТЪМ ЗА ДЕКОДИРАНЕ НА ХЕМИНГ!!!

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>

using namespace std;

class HammingResult {
public:
	bool *Y;
	int CorectSyndrom;

	HammingResult(bool *y, int corectSyndrom);
};

class HammingCode
{
public:
	//Изчислява се n=2^r-1
	//Изчислява се k=n-r
	// Oбразува се Н(n-k;n) В Н колоните са представени в естевствн ред на нарастващи бинарни числа от 1 до n, 
	// за да се получи Н в стандартна форма се разместват стълбовете (но не е нужно да се прави)
	HammingCode(int r, bool *y);
	HammingResult CheckCode();
private:
	int R;
	bool *Y;

	int n;
	int k;
	bool **H;
	bool *Syndrom;

	//Умножаваме Н(транспонирано) със У и получаваме синдрома на У
	void CalculateSyndroms();

	//преобразувам получения синдром в десеттично чило 
	int CalculateDecSyndrom();
};