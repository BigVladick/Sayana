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
	Word(string e, string r) : english(e), russian(r) {}
	// нужны для сортировки
	friend bool operator<(Word& a, Word& b);
	friend bool operator>(Word& a, Word& b);
	// Конструктор копирования
	Word(const Word& from);
	// Оператор присваивания
	Word& operator=(const Word& from);
	friend ostream& operator<<(ostream& cout, Word& time);
};
