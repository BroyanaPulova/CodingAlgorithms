#pragma once

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class SpectreLinearCode
{
public:
	SpectreLinearCode();

	bool nextComb(int n, int k, int *comb);
	void Combinations(int m, int n, int*B);
};
