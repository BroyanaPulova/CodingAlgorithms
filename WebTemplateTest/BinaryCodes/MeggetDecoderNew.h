#pragma once

#include"CodeWord.h"
#include "Polynom.h"
#include <iostream>
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MeggetDecoderNew
{
public:
	//������� �� n-��������� �� ������
	int n;
	//������� �� ��������� ����� 104
	int data;
	bool *Ytemp;

	MeggetDecoderNew(int n, int data, bool *yTemp);

	void Initialize();

	//��� ������ ��� �� �� � �������� � �� ������ �� �����
	//�������� �� �������� �� �
	//�(�) �� ���� �� g(x) � �� �������� ������� (�������), ��� � 0 ����� � �������� ����� ���������
	//��������� ������� �� �������� ��� �������� �� ����� x^n (00..01)
	//n ���� �� �� ������� ����, ��� �� � ������� �������� �� x^n �� ������� ��� � ���� �� �� ������ � ���������� ��������
	//��� ������� ����� �������, ������� ������ � �� �������� �� ���� ������� ������� ��� ���������� �����
	//�������� �������� ������� ����� � ������������ ���������� �
	//���������� ��������� ������
	vector<bool> CheckCode();

private:
	Polynom PolynomG;

	//�������� �� ������������ �� �e����� 
	//���� ���� �� ������� �� ��������
	vector<Polynom> polynoms;

	//�������� �� ��� �� g(x) � �������� �� ������ � residueLider[j]
	vector<Polynom> syndroms;

	//��������� �� �������� �� �������������
	int* LiderOfClasses(int countComn);
};
