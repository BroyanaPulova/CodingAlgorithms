//������ �� �� ������� � �� �� ������ ������� ������ � ������� N �� ����� ����� � ��������� � �������� �� ������� �������
//(����� ����� ��� � ���������), ��� ���������� ���� "�" ������� � ����� �� ������ �� ������ ��� � ���������, ����� ������ �� � ��������
//� ���������� �� ����������� �� ������ ������ ����!!!!

#pragma once
#include "CodingHelper.h"

class SyndromeDecoding
{
public:
	long int n = 0;//������� �� ������  m
	long int k = 0;//������ � ��������� n
	long int d = 0;//��������� ����������

				   //1. ������� �� ������������ ������� � �������� ���!
				   //1.1.  ��������� �� ���� �������� � ������������ ������� � �������� ���, ��� �� � ������!
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

	//1.2  ��������� � � ��������� ����� � 10����� �����
	void ConvertToDecNumbers();

	//2. �������� �� ����������� �������
	void GenrateRiseMatrix();

	//4. ����������� �� ��. �������� ->  2^(��������� �� ������)/(���� �� �������� ����) = ���� �� ��������� ������� => ����������
	void CalculateCountSyndroms();

	// 5. ���������� �������� �� ��������� ��������(� ������ ������� �������) :
	//   ������� � = 0000,1000,0100,0010,0001,1100,0110,0011,1010,0101...(������ ������� ������������� ��.)^(������ ������ ����)
	//   ��� ������ ������� ������ � ����� � ��������� �� ���������� ������ �� ���� => �� ����� ������� ����� ��������.
	void GenerateLiders(vector<CodeWord> codes);

	//6. ���������� ���������� ���� ������� �(�������������)[����� ��� �mxn H������������� nxm] ��� ����� ����� �� ������� ���� 
	//   � ��������� ����� ������� ����� ���������� ������� ����.  
	int SyndromTable(int i, int stephen, int p, int n, int k, int constant, int countSyndroms, vector<CodeWord> codes, int ** Syndroms);

	//7.1 ������ y � ��������� �� ��������� �������, ���� �� ������� ���������� ���������� �������
	//vector<CodeWord> corectMensaje = vector<CodeWord>();
	string FindSyntrom();
};
