#pragma once
#include <iostream>

using namespace std;

/*
	HuffmanElement - ������� ������ ������� � ������� ��� �������������
	- ��������� <, >, <= , >= ������������ ��� ������������� ���������� List<U>.insert(U x)
	- == ������������ ��� �������� ������ ����� ����, ����� ���������� �������� �� �����������
*/

class HuffmanElement
{
public:
	char symbol;
	int frequency;
	HuffmanElement(char s, int f) : symbol(s), frequency(f) {}

	HuffmanElement() {}
	~HuffmanElement() {}
	HuffmanElement(const HuffmanElement& from);
	HuffmanElement& operator=(const HuffmanElement& from);
	friend ostream& operator<<(ostream& cout, HuffmanElement& time);
	friend bool operator==(HuffmanElement& a, HuffmanElement& b);
	friend bool operator<(HuffmanElement& a, HuffmanElement& b);
	friend bool operator>(HuffmanElement& a, HuffmanElement& b);
	friend bool operator<=(HuffmanElement& a, HuffmanElement& b);
	friend bool operator>=(HuffmanElement& a, HuffmanElement& b);
};
