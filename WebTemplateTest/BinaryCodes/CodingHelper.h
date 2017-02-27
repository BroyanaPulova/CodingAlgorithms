#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include"CodeWord.h"

using namespace std;

class CodingHelper
{
public:
	static bool NextComb(int n, int k, int *comb);
	static vector<CodeWord> Combinations(int m, int n, int*B);
};

