#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*
	����� Word 
	- � ����� 2 ���� string: english � russian
	- ��������� < > ����� ��� ����������. ��������� ������ �� ���� english � ���������� �������
	- �������� == ����� ��� �������� ���� �� ������������ � �������
	- ����������� ����������� � �������� ������������ - ����� ��� ���������� ������ ���� 3� �������� ��������
	- int hashFAQ6(const char* str, int size) = ��� ������� �� ����������
	- int getHash(int size) = ��������� ������������. ������ ��� �� ������ ����: english+russian
*/


// ���������� ����� �������� ������
string minString(string a, string b);

class Word
{
private:
	int hashFAQ6(const char* str, int size);
public:
	string english;
	string russian;
	Word() {}
	~Word() {}
	Word(string e, string r) : english(e), russian(r) {}
	// ����� ��� ����������
	friend bool operator<(Word& a, Word& b);
	friend bool operator>(Word& a, Word& b);
	friend bool operator>=(Word& a, Word& b);
	// ����� ��� ���������� �������
	friend bool operator==(Word& a, Word& b);
	// ����������� �����������
	Word(const Word& from);
	// �������� ������������
	Word& operator=(const Word& from);
	friend ostream& operator<<(ostream& cout, Word& time);
	int getHash(int size);
};
