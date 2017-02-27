#pragma once

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include "GenerateMatrixElement.h"

using namespace std;

class ReedMuller
{
public:
	ReedMuller(int r, int m, bool *y);

private:
	int r;

	//��������� ��:
	//��������� �� ������ n=2^m
	int n;

	//m- �� ����������� �� n
	int m;

	int chastno;

	//���� ������ k = ����(i=0, r) �� (m ��� r)
	int k;

	//��������� ���������� d=2^(m-r)
	int d;

	//���� ������ ����� ������� (d-1)/2
	int countErrors;

	bool **binG;
	bool* Y;
	GenerateMatrixElement *decG;
	GenerateMatrixElement* nextRows;

	int CalculateCharacteristicVector(GenerateMatrixElement currentElement, bool *Y, GenerateMatrixElement* binG, int n, int level, bool** temp, bool** H, bool* Add, int& exist);
	//�������� ������������
	bool nextComb(int n, int k, int *comb);

	//�������� ����������
	bool nextVar(int n, int k, int *var);

	void Initialize();
	void CreateMatrixs();
	vector<bool> CalculateAllIncludeVectors(int countElements, GenerateMatrixElement* matrix);
	
public:
	//��������
	//������� �� ������ ����� ����� �� ���� �������� (��������� �� ������ ������ �� � ������ �� ���� ������ � ���������)
	string Coding();

	//����������
	//���������� ������ �
	//���������� �� r>1 � m>3
	//x1x2 = h1
	//x1 notx2 = h2
	//notx1 x2 = h3
	//notx1 notx2 = h4
	//���������� ����� �� ��������� �
	//�� ����� ������������ ����� ���������
	//��� �� ����� ��������� 0
	//��� �� ������� ��������� 1
	//��� ���������� ������� �� ����� �1 �� �������
	//��� �� ������� �1 �������
	// ������ ���� � �� ,�2, �1
	//���������� ��� ������ �������� � ��� �� 
	//�������� ������ ������ ����� �������� 
	//���������� ������� ������ S1
	//��� ������� �� S1 � ��-������ �� n/2
	//������ ��� ������� � �� �������� � S1
	//��� �� ������ ��� �� �������
	//��������� ������ � ������!!!
	string Decoding();
};