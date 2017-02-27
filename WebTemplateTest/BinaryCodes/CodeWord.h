#pragma once
#include <iostream>
#include<bitset>

using namespace std;

class CodeWord
{
public:
	long int Value;
	int count;

	CodeWord();

	void AddValue(unsigned val);
	void Calculate();

	int GetCountOneBits();
	string GetBinaryValue(int sizeWord);
	
	bool operator<(const CodeWord other) const
	{
		return this->count < other.count;
	}

	bool operator() (const CodeWord& element1, const CodeWord& element2)
	{
		return (element1.count < element2.count);
	}

private:
	long int value = 0;
	string ValueStr;

	int doBinaryJunk(unsigned n, string* value);
};
