#include "NativeLib.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <array>
#include "ShannonFano.h"
#include "Huffman.h"
#include <bitset>
#include <stdexcept>
#include<fstream>

MYAPI char* HuffmanEncode(const char* text)
{
	char * writable;

	try
	{
		CodingAlgorithm *huffman = new Huffman(text);
		string str = huffman->Encode();
		writable = new char[str.size() + 1];
		std::copy(str.begin(), str.end(), writable);
		writable[str.size()] = '\0';
	}
	catch (exception exc)
	{
		writable = (char*)exc.what();
	}
	return writable;
}

MYAPI char* HuffmanDecode(const char* text, const char* plainText)
{
	CodingAlgorithm *huffman = new Huffman(plainText);
	string encode = huffman->Encode();
	string str = huffman->Decode(text);
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}

MYAPI char* HuffmanShowTable(const char* text)
{
	Huffman *huffman = new Huffman(text);
	string encode = huffman->Encode();
	string str = huffman->ShowTable();
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}

MYAPI char* ShannonFanoEncode(const char* text)
{
	CodingAlgorithm *shannonFano = new ShannonFano(text);
	string str = shannonFano->Encode();
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}

MYAPI char* ShannonFanoDecode(const char* text, const char* plainText)
{
	CodingAlgorithm *shannonFano = new ShannonFano(plainText);
	string encode = shannonFano->Encode();
	string str = shannonFano->Decode(text);
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}

MYAPI char* ShannonFanoShowTable(const char* text)
{
	ShannonFano *shannonFano = new ShannonFano(text);
	string encode = shannonFano->Encode();
	string str = shannonFano->ShowTable();
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}

