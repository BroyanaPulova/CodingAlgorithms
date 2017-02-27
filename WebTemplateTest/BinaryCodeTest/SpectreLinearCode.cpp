#include "stdafx.h"
#include "SpectreLinearCode.h"
#include"SpectreElement.h"

SpectreLinearCode::SpectreLinearCode()
{
}

bool SpectreLinearCode::nextComb(int n, int k, int * comb)
{
	int i = k - 1;
	for (; i >= 0, comb[i] == n - k + i + 1; i--);
	if (i < 0) return false;
	comb[i]++;
	for (i++; i < k; i++) comb[i] = comb[i - 1] + 1;

	return true;
}

void SpectreLinearCode::Combinations(int m, int n, int * B)
{
	int combinations = (int)(pow(2., (double)(n)));
	vector<SpectreElement> result = vector<SpectreElement>();

	int *C = new int[combinations];
	for (int k = 0; k <= (int)(pow(2., (double)(m)) - 1); k++)
	{
		if (k > m || m < 1)
			break;

		for (int i = 0; i < k; i++)
			C[i] = i + 1;

		do
		{
			SpectreElement element;
			for (int i = 0; i < k; i++) //B[C[i]-1]
			{
				element.AddValue(B[C[i] - 1]);
			}

			if (k != 0)
			{
				element.Calculate();
				result.push_back(element);
			}

		} while (nextComb(m, k, C));
	}

	sort(result.begin(), result.end());

	cout << endl;

	int j = 0;
	for (auto i = result.begin(); i != result.end(); i++, j++)
	{
		cout << "Element " << j << " - " << (*i).GetBinaryValue(n) << " COUNT - " << (*i).GetCountOneBits() << "VALUE - " << (*i).Value << endl;
	}
}
