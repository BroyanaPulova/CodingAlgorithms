// BinaryCodeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "SystemFormCheckMatrix.h"

using namespace std;

////void TestLinearCode()
////{
////	long int n = 0;//дължина на думата
////	long int m = 0;//редове в матрицата
////
////	cout << "enter n < 64!, enter m" << endl;
////	cin >> n >> m;
////
////	bool **A = new bool*[m];//bin
////	int *B = new int[(int)(pow(2., (double)(n)) - 1)];//dec
////
////	for (int i = 0; i < m; i++)//vavejda se matricata
////	{
////		A[i] = new bool[n];
////		bitset<64> number;
////
////		for (int j = 0; j < n; j++)
////		{
////			cout << "enter elements  " << i << "  " << j << "  0 or 1 - ";
////			cin >> A[i][j];
////			number.set(n - 1 - j, A[i][j]);
////		}
////
////		B[i] = number.to_ulong();
////	}
////
////	SpectreLinearCode* code = new SpectreLinearCode();
////
////	code->Combinations(m, n, B);//namirame kombinaciite
////
////	system("pause");
////}
//
//
//// SystemFormAndCheckMatrix.cpp : Defines the entry point for the console application.
////ТРЯБВА ДА СЕ ДОГЛЕДА И ДА СЕ ДОБАВИ НУЛЕВИЯ ВЕКТОР С ДЪЛЖИНА N НА ПЪРВО МЯСТО В ТАБЛИЦАТА С ЛИДЕРИТЕ НА СЪСЕДНИ КЛАСОВЕ
////(ТОЕСТ ПЪРВИ РЕД В ТАБЛИЦАТА), АКО ВЪВЕДЕНАТА ДУМА "У" СЪВПАДА С НЯКОЯ ОТ ДУМИТЕ НА ПЪРВИЯ РЕД В ТАБЛИЦАТА, ЗНАЧИ ДУМАТА НЕ Е СГРЕШЕНА
////И ПРИНАДЛЕЖИ НА МНОЖЕСТВОТО ОТ НАШИТЕ КОДОВИ ДУМИ!!!!
//
//
////ТРЯБВА ДА СЕ ДОГЛЕДА И ДА СЕ ДОБАВИ НУЛЕВИЯ ВЕКТОР С ДЪЛЖИНА N НА ПЪРВО МЯСТО В ТАБЛИЦАТА С ЛИДЕРИТЕ НА СЪСЕДНИ КЛАСОВЕ
////(ТОЕСТ ПЪРВИ РЕД В ТАБЛИЦАТА), АКО ВЪВЕДЕНАТА ДУМА "У" СЪВПАДА С НЯКОЯ ОТ ДУМИТЕ НА ПЪРВИЯ РЕД В ТАБЛИЦАТА, ЗНАЧИ ДУМАТА НЕ Е СГРЕШЕНА
////И ПРИНАДЛЕЖИ НА МНОЖЕСТВОТО ОТ НАШИТЕ КОДОВИ ДУМИ!!!!
//using namespace std;
//class CodeWord
//{
//public:
//	long int Value;
//	int count;
//
//	CodeWord()
//		:Value(0), count(-1)
//	{
//		ValueStr = string("");
//	}
//
//	void AddValue(unsigned val)
//	{
//		Value ^= val;
//	}
//
//	void Calculate()
//	{
//		count = doBinaryJunk(Value, &ValueStr);
//	}
//
//	int GetCountOneBits()
//	{
//		if (count != -1)
//			return count;
//
//		count = doBinaryJunk(Value, &ValueStr);
//		return count;
//	}
//
//	string GetBinaryValue(int sizeWord)
//	{
//		bitset<32> set(Value);
//		string binaryNumber = set.to_string();
//
//		string result = binaryNumber.erase(0, 32 - sizeWord);
//
//		return result;
//	}
//
//	bool operator<(const CodeWord other) const
//	{
//		return this->count < other.count;
//	}
//
//	bool operator() (const CodeWord& element1, const CodeWord& element2)
//	{
//		return (element1.count < element2.count);
//	}
//
//private:
//	long int value = 0;
//	string ValueStr;
//
//	int doBinaryJunk(unsigned n, string* value)
//	{
//		unsigned mask = 1 << (std::numeric_limits<unsigned>::digits - 1);
//
//		unsigned count[2] = { 0 };
//
//		while (mask && !(mask & n))
//			mask >>= 1;
//
//		while (mask)
//		{
//			unsigned digit = (mask & n) != 0;
//			++count[digit];
//
//			(*value) += (mask & n) != 0 ? "1" : "0";
//
//			mask >>= 1;
//		}
//
//		return count[1];
//	}
//};
//
//bool nextComb(int n, int k, int *comb)
//{
//	int i = k - 1;
//	for (; i >= 0, comb[i] == n - k + i + 1; i--);
//	if (i < 0) return false;
//	comb[i]++;
//	for (i++; i < k; i++) comb[i] = comb[i - 1] + 1;
//	return true;
//}
//
//void Combinations(int m, int n, int k, int*Gdec)
//{
//	int combinations = (int)(pow(2., (double)(n)));
//	vector<CodeWord> result = vector<CodeWord>();
//
//	int *C = new int[combinations];
//	for (int k = 0; k <= (int)(pow(2., (double)(m)) - 1); k++)
//	{
//		if (k > m || m < 1)
//			break;
//
//		for (int i = 0; i < k; i++)
//			C[i] = i + 1;
//
//		do
//		{
//			CodeWord element;
//			for (int i = 0; i < k; i++) //B[C[i]-1]
//			{
//				element.AddValue(Gdec[C[i] - 1]);
//			}
//
//			if (k != 0)
//			{
//				element.Calculate();
//				result.push_back(element);
//			}
//
//		} while (nextComb(m, k, C));
//	}
//
//	cout << endl;
//	int j = 0;
//	for (auto i = result.begin(); i != result.end(), j < (int)(pow(2., (double)(k)) - 1); i++, j++)
//	{
//		Gdec[j] = (*i).Value;
//		cout << "Element " << j << " - " << (*i).GetBinaryValue(n) << " COUNT - " << (*i).GetCountOneBits() << "VALUE - " << (*i).Value << endl;
//		cout << "Gdec[j] =  " << Gdec[j] << endl;
//	}
//}
//
////prowerka dali weche ne sme poluchili sledwashtiq lider na saseden klas
//bool ExistA(int a, int p, int i, int n, int k, int **Syndroms)
//{
//	for (int controli = 0; controli < i - 1 - p; controli++)//prowerqwame dali weche ima takav sindrom
//	{
//		for (int controlj = 0; controlj <= (int)(pow(2., (double)(n - k))); controlj++)
//		{
//			if (Syndroms[controli][controlj] == a)
//			{
//				cout << "tozi sundrom weche go ima" << Syndroms[controli][controlj] << endl;
//				return(true);
//			}
//			else
//			{
//				cout << "tozi sindrom go nqmawse oshte" << endl;
//				return(false);
//			}
//		}
//	}
//}
//
////6. Генерираме синдромите като умножим Н(транспонирана)[тоест ако Нmxn Hтранспонирана nxm] със всеки лидер на съседен клас 
////   и записваме всеки синдром срещу съответния съседен клас.  
//int SyndromTable(int i, int stephen, int p, int n, int k, int constant, int countSyndroms, int *Gdec, int **Syndroms)
//{
//	int size = sizeof(Gdec);//razmera na Gdec*broq sasecni klasowe
//	cout << "size = " << size << endl;
//	Syndroms[i - p] = new int[size];//i=br. sindromi/reda/; j=br.kodowi dumi/koloni/
//	for (int j = 0; j < (int)(pow(2., (double)(k)) - 1); j++)
//	{
//		int a = constant*((int)(pow(2., (double)(stephen))));
//		bool exist = ExistA(a, p, i, n, k, Syndroms);//prowerqwa dali weche ima a
//		cout << "Gdec sadarja:    " << endl;
//		cout << Gdec[j] << endl;
//		if (exist == false)//prowerqwa dali tozi sindrom weche ne e poluchen 
//		{
//			Syndroms[i - p][0] = a;
//			cout << "lidera na klasa e  :   " << "    " << a << "     ";
//			Syndroms[i - p][j + 1] = Gdec[j] ^ Syndroms[i - p][0];
//			cout << "  sindromite na tozi lider sa : " << Syndroms[i - p][j + 1] << "   " << endl;
//		}
//		else if (exist == true)
//		{
//			p++;
//			cout << "p = " << p << endl;
//			break;
//		}
//	}
//	return(**Syndroms);
//}
//
//int TestSyndormDecode()
//{
//	long int n = 0;//дължина на думата  m
//	long int k = 0;//редове в матрицата n
//	long int d = 0;//минимално разстояние
//	cout << "enter n < 64!, enter k, d<=6" << endl;
//	cin >> n >> k >> d;
//	if (n == k || n < k)
//	{
//		cout << "nekorektna matrica";
//		return 0;
//	}
//	else
//	{
//		bool **H = new bool*[k];//prowerowachna
//		bool **G = new bool*[n - k];//poravdashta
//		bool *Y = new bool[n];//sgresheniq wektor
//		int *Gdec = new int[(int)(pow(2., (double)(k)) - 1)];//desettichen G  2^k-1
//		int *Hdec = new int[k];//desettichna H
//
//							   //1. Въвежда се проверовъчна матрица в нормален вид!
//							   //1.1.  проверява се дали наистина е проверовъчна матрица в нормален вид, ако не е ГРЕШКА!
//		for (int i = 0; i < k; i++)
//		{
//			H[i] = new bool[n];
//			bitset<64> number;
//
//			for (size_t initIndex = 0; initIndex < n; initIndex++)
//			{
//				H[i][initIndex] = false;
//			}
//
//			for (int j = 0; j < n; j++)
//			{
//				cout << "enter elements  " << i << "  " << j << "  0 or 1 - ";
//				cin >> H[i][j];
//
//				if (j >= n - k)
//				{
//					if (H[i][n - k + i] == false || (j != n - k + i && H[i][j] == true))
//					{
//						cout << "nekorektna matrica:" << endl;
//					}
//				}
//			}
//		}
//		cout << endl;
//		cout << "H =" << endl;
//		cout << H[0][0] << "  " << H[0][1] << "  " << H[0][2] << "  " << H[0][3] << "  " << endl; //<< H[0][4] << "  " << H[0][5] << endl;
//		cout << H[1][0] << "  " << H[1][1] << "  " << H[1][2] << "  " << H[1][3] << "  " << endl;//<< H[1][4] << "  " << H[1][5] << endl;
//																								 //cout << H[2][0] << "  " << H[2][1] << "  " << H[2][2] << "  " << H[2][3] << "  " << endl;//<< H[2][4] << "  " << H[2][5] << endl;
//		cout << endl;
//
//		//1.2  Запазваме Н в Едномерен масив с 10тични числа
//		cout << "desettichnata H e :" << endl;
//		for (int i = 0; i < n; i++)//zapiswame desettichnite redove na H w Hdec
//		{
//			bitset<64> number;
//			for (int j = 0; j < k; j++)
//			{
//				number.set(k - 1 - j, H[j][i]);
//			}
//			Hdec[i] = number.to_ulong();
//			cout << Hdec[i] << "  ";
//		}
//		cout << endl;
//
//		//2. Генерира се Пораждащата матрица
//		for (int i = 0; i < n - k; i++)
//		{
//			//H[i] = new bool[n];//n reda = i; n-k stalba = j
//			for (int j = 0; j < n; j++)
//			{
//				if (i == 0)
//					G[j] = new bool[n];//n reda = i; n-k stalba = j
//
//				if (j < n - k)
//				{
//					G[i][j] = i == j;
//				}
//				if (j < k)
//				{
//					G[i][j + k + 1] = H[j][i];
//				}
//			}
//		}
//
//		cout << endl;
//		cout << "G =" << endl;
//		cout << G[0][0] << "  " << G[0][1] << "  " << G[0][2] << "  " << G[0][3] << "  " << endl;//<< G[0][4] << "  " << G[0][5] << endl;
//		cout << G[1][0] << "  " << G[1][1] << "  " << G[1][2] << "  " << G[1][3] << "  " << endl;//<< G[1][4] << "  " << G[1][5] << endl;
//																								 //cout << G[2][0] << "  " << G[2][1] << "  " << G[2][2] << "  " << G[2][3] << "  " << G[2][4] << "  " << G[2][5] << endl;
//		cout << endl;
//		cout << "desettichnite stoinosti na G sa :" << endl;
//		for (int i = 0; i < n - k; i++)//zapiswame desettichnite redove na G w Gdec
//		{
//			bitset<64> number;
//			for (int j = 0; j < n; j++)
//			{
//				number.set(n - 1 - j, G[i][j]);
//			}
//			Gdec[i] = number.to_ulong();
//			cout << "desettichnite stoinosti na G sa :      " << Gdec[i] << endl;
//		}
//
//		//3. Генерират се всички кодови думи от пораждащата матрица
//		Combinations(n - k, n, k, Gdec);
//
//		//4. Изчисляване на бр. синдроми ->  2^(дължината на думата)/(броя на кодовите думи) = броя на съседните класове => синдромите
//		int a = (int)(pow(2., (double)(n)));
//		int b = (int)(pow(2., (double)(n - k)));
//		int countSyndroms = a / b;
//		cout << endl;
//		cout << "broq na sasednite klasowe e : " << countSyndroms << endl;
//
//		//5. Генерираме лидерите на съседните класоове (и самите съседни класове):
//		//   вектора Х = 0000,1000,0100,0010,0001,1100,0110,0011,1010,0101...(докато стигнем гореполучения бр.)^(всички кодови думи)
//		//   ако някъде получим вектор Х който е използван го пропускаме защото от това => че двата съседни класа съвпадат.
//		int **Syndroms = new int*[countSyndroms - 1];
//		int p = 0;
//		int stephen = 0;
//		int constant = 1;
//		int br = 1;
//		for (int i = 0, stephen = 0; i <= countSyndroms; i++, stephen++)
//		{
//			if (stephen + br <= n)//1*2^n
//			{
//				SyndromTable(i, stephen, p, n, k, constant, countSyndroms, Gdec, Syndroms);
//			}
//			else if (br = 1)
//			{
//				stephen = 0;
//				constant = 3;
//				br++;
//			}
//			else
//			{
//				stephen = 0;
//				constant = (constant * 2) - 1;
//				br++;
//			}
//		}
//		cout << "sindromie sa: " << endl << endl;;
//		for (int i = 0; i < countSyndroms; i++)
//		{
//			for (int j = 0; j <= (int)(pow(2., (double)(k)) - 1); j++)
//			{
//				cout << "sindromite sa:  " << Syndroms[i][j] << endl;
//			}
//			cout << endl << endl;
//		}
//
//		//6. Генерираме синдромите като умножим Н(транспонирана)[тоест ако Нmxn Hтранспонирана nxm] със всеки лидер на съседен клас 
//		//   и записваме всеки синдром срещу съответния съседен клас.       SyndromTable();
//
//		//7. Вземаме въведения от потребителя вектор У 
//		for (int i = 0; i < n; i++)
//		{
//			cout << "enter Y " << i << " : " << endl;
//			cin >> Y[i];
//		}
//
//		bitset<64> number;//zapiswame 10tichnata stoinost na Y w y
//		for (int j = 0; j < n; j++)
//		{
//			number.set(n - 1 - j, Y[j]);
//		}
//		int y = number.to_ulong();
//
//		//7.1 търсим y в таблицата на съседните класове, като го намерим определяме съответния синдром
//		//vector<CodeWord> corectMensaje = vector<CodeWord>();
//		bool *corectMensaje = new bool[(int)(pow(2., (double)(n - k)))];
//		for (int i = 0; i < countSyndroms; i++)
//		{
//			for (int j = 0; j <= (int)(pow(2., (double)(n - k))) + 1; j++)
//			{
//				if (Syndroms[i][j] == y)
//				{
//					cout << "lidera na sasedniq klas e: " << Syndroms[i][0] << endl;
//					cout << "sindroma e (stalba ot H) :" << "  ";
//					for (int i = 0; i < k; i++)
//					{
//						cout << H[i][j];
//					}
//					cout << endl;
//					cout << "desettichniq sindrom e:  " << Hdec[j] << endl;
//					cout << endl;
//					int corectMensaje = Syndroms[i][0] ^ y;//8. Пресмятаме У^Лидера на класа с този синдром, получения вектор е правилният !					
//					cout << "wqrnoto desettichno saobshtenie e: " << corectMensaje << endl;
//					cout << endl;
//					bitset<32> set(corectMensaje);
//					string binaryNumber = set.to_string();
//					string result = binaryNumber.erase(0, 32 - n);
//					cout << "vqrnoto saobshtenie e:   " << result << endl;
//					//preobrazuvane na desettichnoto saobshtenie e dwoichno
//				}
//			}
//		}
//		system("pause");
//		return 0;
//	}
//}
//ТРЯБВА ДА СЕ ДОГЛЕДА И ДА СЕ ДОБАВИ НУЛЕВИЯ ВЕКТОР С ДЪЛЖИНА N НА ПЪРВО МЯСТО В ТАБЛИЦАТА С ЛИДЕРИТЕ НА СЪСЕДНИ КЛАСОВЕ
//(ТОЕСТ ПЪРВИ РЕД В ТАБЛИЦАТА), АКО ВЪВЕДЕНАТА ДУМА "У" СЪВПАДА С НЯКОЯ ОТ ДУМИТЕ НА ПЪРВИЯ РЕД В ТАБЛИЦАТА, ЗНАЧИ ДУМАТА НЕ Е СГРЕШЕНА
//И ПРИНАДЛЕЖИ НА МНОЖЕСТВОТО ОТ НАШИТЕ КОДОВИ ДУМИ!!!!






int main(char[] args)
{
	int* array_N = new int[3];
	array_N[0] = 71;
	array_N[1] = 43;
	array_N[2] = 29;

	SystemFormAndCheckMatrix matrix = SystemFormAndCheckMatrix(7, 3, array_N);
	SystemMatrixs resultMatrix = matrix.GetResultMatrixs();

	int t = 5;
	//TestSyndormDecode();
}



