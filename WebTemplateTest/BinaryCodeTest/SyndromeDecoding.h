//ТРЯБВА ДА СЕ ДОГЛЕДА И ДА СЕ ДОБАВИ НУЛЕВИЯ ВЕКТОР С ДЪЛЖИНА N НА ПЪРВО МЯСТО В ТАБЛИЦАТА С ЛИДЕРИТЕ НА СЪСЕДНИ КЛАСОВЕ
//(ТОЕСТ ПЪРВИ РЕД В ТАБЛИЦАТА), АКО ВЪВЕДЕНАТА ДУМА "У" СЪВПАДА С НЯКОЯ ОТ ДУМИТЕ НА ПЪРВИЯ РЕД В ТАБЛИЦАТА, ЗНАЧИ ДУМАТА НЕ Е СГРЕШЕНА
//И ПРИНАДЛЕЖИ НА МНОЖЕСТВОТО ОТ НАШИТЕ КОДОВИ ДУМИ!!!!

#pragma once
#include "CodingHelper.h"

class SyndromeDecoding
{
public:
	long int n = 0;//дължина на думата  m
	long int k = 0;//редове в матрицата n
	long int d = 0;//минимално разстояние

				   //1. Въвежда се проверовъчна матрица в нормален вид!
				   //1.1.  проверява се дали наистина е проверовъчна матрица в нормален вид, ако не е ГРЕШКА!
	SyndromeDecoding(long int n, long int k, long int d, bool **h, bool *y);

	string Decode();
private:
	bool **H;//prowerowachna
	bool **G;//poravdashta
	bool *Y;//sgresheniq wektor
	int *Gdec;//desettichen G  2^k-1
	int *Hdec;//desettichna H

	int countSyndroms;
	int **Syndroms;

	//prowerka dali weche ne sme poluchili sledwashtiq lider na saseden klas
	bool ExistA(int a, int p, int i, int n, int k, int **Syndroms);

	//1.2  Запазваме Н в Едномерен масив с 10тични числа
	void ConvertToDecNumbers();

	//2. Генерира се Пораждащата матрица
	void GenrateRiseMatrix();

	//4. Изчисляване на бр. синдроми ->  2^(дължината на думата)/(броя на кодовите думи) = броя на съседните класове => синдромите
	void CalculateCountSyndroms();

	// 5. Генерираме лидерите на съседните класоове(и самите съседни класове) :
	//   вектора Х = 0000,1000,0100,0010,0001,1100,0110,0011,1010,0101...(докато стигнем гореполучения бр.)^(всички кодови думи)
	//   ако някъде получим вектор Х който е използван го пропускаме защото от това => че двата съседни класа съвпадат.
	void GenerateLiders(vector<CodeWord> codes);

	//6. Генерираме синдромите като умножим Н(транспонирана)[тоест ако Нmxn Hтранспонирана nxm] със всеки лидер на съседен клас 
	//   и записваме всеки синдром срещу съответния съседен клас.  
	int SyndromTable(int i, int stephen, int p, int n, int k, int constant, int countSyndroms, vector<CodeWord> codes, int ** Syndroms);

	//7.1 търсим y в таблицата на съседните класове, като го намерим определяме съответния синдром
	//vector<CodeWord> corectMensaje = vector<CodeWord>();
	string FindSyntrom();
};
