#include "stdafx.h"
//#include "SpectreLinearCode.h"
//
//SpectreLinearCode::SpectreLinearCode(int m, int n, int*B)
//	:m(m), n(n), B(B)
//{
//}
//
//string SpectreLinearCode::Code()
//{
//	vector<CodeWord> elements = CodingHelper::Combinations(m, n, B);
//
//	stringstream stream;
//
//	for (auto i = elements.begin(); i != elements.end(); i++)
//	{
//		stream << (*i).GetBinaryValue(n) << endl;
//	}
//
//	return stream.str();
//}