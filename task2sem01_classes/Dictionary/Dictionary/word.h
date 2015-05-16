#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*
	Класс Word 
	- у слова 2 поля string: english и russian
	- операторы < > нужны для сортировки. Сравнение только по полю english в алфавитном порядке
	- оператор == нужен для проверки слов на уникальность в словаре
	- Конструктор копирования и оператор присваивания - нужны для корректной работы всех 3х структру хранения
	- int hashFAQ6(const char* str, int size) = хэш функция из интернетов
	- int getHash(int size) = интерфейс пользователя. Берерт хэш от строки вида: english+russian
*/


// Возвращает самую короткую строку
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
	// нужны для сортировки
	friend bool operator<(Word& a, Word& b);
	friend bool operator>(Word& a, Word& b);
	friend bool operator>=(Word& a, Word& b);
	// нужен для уникальной вставки
	friend bool operator==(Word& a, Word& b);
	// Конструктор копирования
	Word(const Word& from);
	// Оператор присваивания
	Word& operator=(const Word& from);
	friend ostream& operator<<(ostream& cout, Word& time);
	int getHash(int size);
};
