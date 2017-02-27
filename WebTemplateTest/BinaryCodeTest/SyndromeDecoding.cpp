#include "stdafx.h"
#include "SyndromeDecoding.h"
#include <vector>

SyndromeDecoding::SyndromeDecoding(long int n, long int k, long int d, bool **h, bool *y)
	:n(n), k(k), d(d), H(h), Y(y)
{
	G = new bool*[n - k];//poravdashta
	Gdec = new int[(int)(pow(2., (double)(k)) - 1)];//desettichen G  2^k-1
	Hdec = new int[k];//desettichna H
}

string SyndromeDecoding::Decode()
{
	ConvertToDecNumbers();
	GenrateRiseMatrix();
	vector<CodeWord> codes = CodingHelper::Combinations(k, n, Gdec);
	CalculateCountSyndroms();
	GenerateLiders(codes);
	return FindSyntrom();
}

void SyndromeDecoding::CalculateCountSyndroms()
{
	int a = (int)(pow(2., (double)(n)));
	int b = (int)(pow(2., (double)(n - k)));

	countSyndroms = a / b;
}

void SyndromeDecoding::GenerateLiders(vector<CodeWord> codes)
{
	Syndroms = new int*[countSyndroms - 1];
	int p = 0;
	int stephen = 0;
	int constant = 1;
	int br = 1;
	for (int i = 0, stephen = 0; i <= countSyndroms; i++, stephen++)
	{
		if (stephen + br <= n)//1*2^n
		{
			SyndromTable(i, stephen, p, n, k, constant, countSyndroms, codes, Syndroms);
		}
		else if (br = 1)
		{
			stephen = 0;
			constant = 3;
			br++;
		}
		else
		{
			stephen = 0;
			constant = (constant * 2) - 1;
			br++;
		}
	}
}

string SyndromeDecoding::FindSyntrom()
{
	bitset<64> number;//zapiswame 10tichnata stoinost na Y w y
	for (int j = 0; j < n; j++)
	{
		number.set(n - 1 - j, Y[j]);
	}
	int y = number.to_ulong();

	bool *corectMensaje = new bool[(int)(pow(2., (double)(n - k)))];
	for (int i = 0; i < countSyndroms; i++)
	{
		for (int j = 0; j <= (int)(pow(2., (double)(n - k))) + 1; j++)
		{
			if (Syndroms[i][j] == y)
			{
				for (int i = 0; i < k; i++)
				{
					cout << H[i][j];
				}
				int corectMensaje = Syndroms[i][0] ^ y;//8. Пресмятаме У^Лидера на класа с този синдром, получения вектор е правилният !					

				bitset<32> set(corectMensaje);
				string binaryNumber = set.to_string();
				string result = binaryNumber.erase(0, 32 - n);

				return result;
				//preobrazuvane na desettichnoto saobshtenie e dwoichno
			}
		}
	}
}

bool SyndromeDecoding::ExistA(int a, int p, int i, int n, int k, int ** Syndroms)
{
	for (int controli = 0; controli < i - 1 - p; controli++)//prowerqwame dali weche ima takav sindrom
	{
		for (int controlj = 0; controlj <= (int)(pow(2., (double)(n - k))); controlj++)
		{
			if (Syndroms[controli][controlj] == a)
			{
				cout << "tozi sundrom weche go ima" << Syndroms[controli][controlj] << endl;
				return(true);
			}
			else
			{
				cout << "tozi sindrom go nqmawse oshte" << endl;
				return(false);
			}
		}
	}
}

int SyndromeDecoding::SyndromTable(int i, int stephen, int p, int n, int k, int constant, int countSyndroms, vector<CodeWord> codes, int ** Syndroms)
{
	int size = codes.size();//razmera na Gdec*broq sasecni klasowe
	cout << "size = " << size << endl;
	Syndroms[i - p] = new int[size];//i=br. sindromi/reda/; j=br.kodowi dumi/koloni/
	for (int j = 0; j < (int)(pow(2., (double)(n - k)) + 1); j++)
	{
		int a = constant*((int)(pow(2., (double)(stephen))));
		bool exist = ExistA(a, p, i, n, k, Syndroms);//prowerqwa dali weche ima a
		if (exist == false)//prowerqwa dali tozi sindrom weche ne e poluchen 
		{
			Syndroms[i - p][0] = a;
			Syndroms[i - p][j + 1] = codes[j].Value ^ Syndroms[i - p][0];
		}
		else if (exist == true)
		{
			p++;
			break;
		}
	}
	return(**Syndroms);
}

void SyndromeDecoding::ConvertToDecNumbers()
{
	for (int i = 0; i < n; i++)//zapiswame desettichnite redove na H w Hdec
	{
		bitset<64> number;
		for (int j = 0; j < k; j++)
		{
			number.set(k - 1 - j, H[j][i]);
		}
		Hdec[i] = number.to_ulong();
		cout << Hdec[i] << "  ";
	}
}

//n - columns
//k - rols
void SyndromeDecoding::GenrateRiseMatrix()
{
	for (int i = 0; i < n - k; i++)
	{
		//H[i] = new bool[n];//n reda = i; n-k stalba = j
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
				G[j] = new bool[n];//n reda = i; n-k stalba = j

			if (j < n - k)
			{
				G[i][j] = i == j;
			}
			if (j < k)
			{
				G[i][j + k + 1] = H[j][i];
			}
		}
	}

	for (int i = 0; i < n - k; i++)//zapiswame desettichnite redove na G w Gdec
	{
		bitset<64> number;
		for (int j = 0; j < n; j++)
		{
			number.set(n - 1 - j, G[i][j]);
		}
		Gdec[i] = number.to_ulong();
	}
}
