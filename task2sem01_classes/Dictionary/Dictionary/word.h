#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*
	 ласс Word 
	- у слова 2 пол€ string: english и russian
	- операторы < > нужны дл€ сортировки. —равнение только по полю english в алфавитном пор€дке
	- оператор == нужен дл€ проверки слов на уникальность в словаре
	-  онструктор копировани€ и оператор присваивани€ - нужны дл€ корректной работы всех 3х структру хранени€
*/


// ¬озвращает самую короткую строку
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
