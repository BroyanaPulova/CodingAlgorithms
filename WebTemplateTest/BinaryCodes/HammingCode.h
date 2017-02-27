#pragma once

// HammingCode.cpp : Defines the entry point for the console application.
// ���� �� �� ������ � �������� ��������� �� ���������� �� ������!!!

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>

using namespace std;

class HammingResult {
public:
	bool *Y;
	int CorectSyndrom;

	HammingResult(bool *y, int corectSyndrom);
};

class HammingCode
{
public:
	//��������� �� n=2^r-1
	//��������� �� k=n-r
	// O������� �� �(n-k;n) � � �������� �� ����������� � ��������� ��� �� ���������� ������� ����� �� 1 �� n, 
	// �� �� �� ������ � � ���������� ����� �� ���������� ���������� (�� �� � ����� �� �� �����)
	HammingCode(int r, bool *y);
	HammingResult CheckCode();
private:
	int R;
	bool *Y;

	int n;
	int k;
	bool **H;
	bool *Syndrom;

	//���������� �(�������������) ��� � � ���������� �������� �� �
	void CalculateSyndroms();

	//������������ ��������� ������� � ���������� ���� 
	int CalculateDecSyndrom();
};