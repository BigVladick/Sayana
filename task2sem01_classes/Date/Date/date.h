#pragma once
#include <iostream>


using namespace std;

// на вхоже номер месяц и високосность года
int monthToDays(int n, bool bissextile);

// Получить индекс n-го вхождения символа в строку
// Пример indefOf("a.b.c", '.', 0) = 1 , indefOf("a.b.c", '.', 1) = 3, indefOf("a.b.c", '.', 2) = -1
int indexOf(string s, char a, int num);

// String -> int
int toInt(string s);

class Date
{
private:
	int day;
	int month;
	int year;
	friend ostream& operator<<(ostream& cout, Date& date);
	friend Date& operator++(Date& d);
	friend Date& operator--(Date& d);
public:

	// Конструктор по строке
	// Строка будет парситься от анлг "parse"
	Date(string input);


	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	// 1996 - 2015
	long static getDiff(Date one, Date two);

};

