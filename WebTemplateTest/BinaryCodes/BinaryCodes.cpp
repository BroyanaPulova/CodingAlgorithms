// This is the main DLL file.

#include "stdafx.h"

#include "BinaryCodes.h"
#include "SpectreLinearCode.h"
#include "WrapperHelper.h"
#include "SystemFormAndCheckMatrix.h"
#include "SyndromeDecoding.h" 
#include "MeggetDecoderNew.h"
#include "ReedMuller.h"
#include"HammingCode.h"
#include <fstream>
#include <math.h>

__declspec(dllexport) char * LinearCode(int m, int n, int * matrix)
{
	char * writable;

	try
	{
		CodingHelper helper = CodingHelper();
		vector<CodeWord> words = helper.Combinations(m, n, matrix);

		stringstream stream;

		for (size_t i = 0; i < words.size(); i++)
		{
			stream << words[i].GetBinaryValue(n) << endl;
		}

		writable = WrapperHelper::ConvertStr(stream.str());

	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}

__declspec(dllexport) char* HammingDecode(long int r, int y)
{
	char * writable;
	int sizeY = pow(2, r) - 1;
	bool* yInput = new bool[sizeY];
	bitset<64> numberY = bitset<64>(y);

	for (int j = sizeY - 1; j >= 0; j--)
	{
		yInput[sizeY - 1 - j] = numberY[j];
	}
	try
	{
		HammingCode* code = new HammingCode(r, yInput);
		HammingResult result = code->CheckCode();

		string str;

		for (size_t i = 0; i < sizeY; i++)
		{
			if (i == result.CorectSyndrom)
			{
				result.Y[i] != result.Y[i];
			}
			str += result.Y[i] == true ? "1" : "0";
		}

		writable = WrapperHelper::ConvertStr(str);
	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}

__declspec(dllexport) char * MeggetDecode(int n, int data, int y)
{
	char * writable;
	bool* yInput = new bool[n];
	bitset<64> numberY = bitset<64>(y);

	for (int j = n - 1; j >= 0; j--)
	{
		yInput[n - 1 - j] = numberY[j];
	}

	try
	{
		MeggetDecoderNew* meggget = new MeggetDecoderNew(n, data, yInput);
		vector<bool> result = meggget->CheckCode();

		string str = "";
		for (size_t i = 0; i < result.size(); i++)
		{
			str += result[i] ? "1" : "0";
		}

		writable = WrapperHelper::ConvertStr(str);
	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}

char * ReedMullerCoding(int r, int m, int y, int yLength)
{
	char * writable;
	bool* yInput = new bool[yLength];
	bitset<64> numberY = bitset<64>(y);

	for (int j = yLength - 1; j >= 0; j--)
	{
		yInput[yLength - 1 - j] = numberY[j];
	}

	try
	{
		ReedMuller* redMuller = new ReedMuller(r, m, yInput);
		string str = redMuller->Coding();
		writable = WrapperHelper::ConvertStr(str);
	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}

char * ReedMullerDecode(int r, int m, int y, int yLength)
{
	char * writable;
	bool* yInput = new bool[yLength];
	bitset<64> numberY = bitset<64>(y);

	for (int j = yLength - 1; j >= 0; j--)
	{
		yInput[yLength - 1 - j] = numberY[j];
	}

	try
	{
		ReedMuller* redMuller = new ReedMuller(r, m, yInput);
		string str = redMuller->Decoding();
		writable = WrapperHelper::ConvertStr(str);
	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}

__declspec(dllexport) char* SystemFormCheckMatrix(int m, int n, int * matrix)
{
	std::fstream fs;
	fs.open("D:\\Games\\SystemFormCheckMatrix.txt");

	fs << " more lorem ipsum";
	fs.close();

	char * writable;

	try
	{
		SystemFormAndCheckMatrix *code = new SystemFormAndCheckMatrix(n, m, matrix);
		SystemMatrixs sysMatrix = code->GetResultMatrixs();
		string check = sysMatrix.check->getString();

		writable = WrapperHelper::ConvertStr(check);

	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}

//n - columns
//k - rows
char * SyndromeDecode(long int n, long int k, long int d, long int y, int* h)
{
	char * writable;

	try
	{
		bool** matrix = new bool*[k];

		for (size_t i = 0; i < k; i++)
		{
			matrix[i] = new bool[n];
			bitset<64> number = bitset<64>(h[i]);

			for (int j = n - 1; j >= 0; j--)
			{
				matrix[i][n - 1 - j] = number[j];
			}
		}

		bool* yInput = new bool[n];
		bitset<64> numberY = bitset<64>(y);

		for (int j = n - 1; j >= 0; j--)
		{
			yInput[n - 1 - j] = numberY[j];
		}

		SyndromeDecoding *syndrom = new SyndromeDecoding(n, k, d, matrix, yInput);
		writable = WrapperHelper::ConvertStr(syndrom->Decode());
	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}

	return writable;
}
