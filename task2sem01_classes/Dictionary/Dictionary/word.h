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
	// нужны дл€ сортировки
	friend bool operator<(Word& a, Word& b);
	friend bool operator>(Word& a, Word& b);
	// нужен дл€ уникальной вставки
	friend bool operator==(Word& a, Word& b);
	//  онструктор копировани€
	Word(const Word& from);
	// ќператор присваивани€
	Word& operator=(const Word& from);
	friend ostream& operator<<(ostream& cout, Word& time);
};
