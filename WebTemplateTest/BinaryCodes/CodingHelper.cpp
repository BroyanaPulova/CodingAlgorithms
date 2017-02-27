#include "stdafx.h"
#include "CodingHelper.h"

bool CodingHelper::NextComb(int n, int k, int * comb)
{
	int i = k - 1;
	for (; i >= 0, comb[i] == n - k + i + 1; i--);
	if (i < 0) return false;
	comb[i]++;
	for (i++; i < k; i++) comb[i] = comb[i - 1] + 1;

	return true;
}

vector<CodeWord> CodingHelper::Combinations(int m, int n, int * B)
{
	int combinations = (int)(pow(2., (double)(n)));
	vector<CodeWord> result = vector<CodeWord>();

	int *C = new int[combinations];
	for (int k = 0; k <= (int)(pow(2., (double)(m)) - 1); k++)
	{
		if (k > m || m < 1)
			break;

		for (int i = 0; i < k; i++)
			C[i] = i + 1;

		do
		{
			CodeWord element;
			for (int i = 0; i < k; i++) //B[C[i]-1]
			{
				element.AddValue(B[C[i] - 1]);
			}

			if (k != 0)
			{
				element.Calculate();
				result.push_back(element);
			}

		} while (NextComb(m, k, C));
	}

	sort(result.begin(), result.end());

	return result;
}
