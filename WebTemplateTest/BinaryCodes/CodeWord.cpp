#include "stdafx.h"
#include "CodeWord.h"

CodeWord::CodeWord() 
	:Value(0), count(-1)
{
	ValueStr = string("");
}

void CodeWord::AddValue(unsigned val)
{
	Value ^= val;
}

string CodeWord::GetBinaryValue(int sizeWord)
{
	bitset<32> set(Value);
	string binaryNumber = set.to_string();

	string result = binaryNumber.erase(0, 32 - sizeWord);

	return result;
}

int CodeWord::doBinaryJunk(unsigned n, string * value)
{
	unsigned mask = 1 << (std::numeric_limits<unsigned>::digits - 1);

	unsigned count[2] = { 0 };

	while (mask && !(mask & n))
		mask >>= 1;

	while (mask)
	{
		unsigned digit = (mask & n) != 0;
		++count[digit];

		(*value) += (mask & n) != 0 ? "1" : "0";

		mask >>= 1;
	}

	return count[1];
}

void CodeWord::Calculate()
{
	count = doBinaryJunk(Value, &ValueStr);
}

int CodeWord::GetCountOneBits()
{
	if (count != -1)
		return count;

	count = doBinaryJunk(Value, &ValueStr);
	return count;
}
