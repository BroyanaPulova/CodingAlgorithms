#include "stdafx.h"
#include "WrapperHelper.h"
#include <sstream>


char * WrapperHelper::ConvertStr(string str)
{
	char* writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}

char* WrapperHelper::ConcatStrings(string a, string b)
{
	stringstream strStream;
	strStream << a << ";" << endl << b;

	string str = strStream.str();

	char* writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}
