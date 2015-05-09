#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



string minString(string a, string b);

class Word
{
public:
	string english;
	string russian;
	Word() {}
	~Word() {}
	Word(string e, string r) : english(e), russian(r) {}
	// ����� ��� ����������
	friend bool operator<(Word& a, Word& b);
	friend bool operator>(Word& a, Word& b);
	// ����� ��� ���������� �������
	friend bool operator==(Word& a, Word& b);
	// ����������� �����������
	Word(const Word& from);
	// �������� ������������
	Word& operator=(const Word& from);
	friend ostream& operator<<(ostream& cout, Word& time);
};
