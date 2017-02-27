#pragma once
#include <string>

using namespace std;

ref class WrapperHelper
{
public:
	static char* ConvertStr(string str);

	static char* ConcatStrings(string a, string b);
};

