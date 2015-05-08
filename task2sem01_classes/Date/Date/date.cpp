#include "date.h"



int monthToDays(int n, bool bissextile)
{
	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
		return 31;
	if (n == 2 && bissextile)
		return 29;
	if (n == 2 && !bissextile)
		return 28;
	return 30;
}

// Получить индекс n-го вхождения символа в строку
// Пример indefOf("a.b.c", '.', 0) = 1 , indefOf("a.b.c", '.', 1) = 3, indefOf("a.b.c", '.', 2) = -1
int indexOf(string s, char a, int num)
{
	int l = s.size();
	int k = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == a)
		{
			if (k++ == num)
				return i;
		}
	}
	return -1;
}

// String -> int
int toInt(string s)
{
	int l = s.size();
	int result = 0;
	for (int i = 0; i < l; i++)
	{
		result += pow(10, l - i - 1) * (s[i] - '0');
	}
	return result;
}


Date& operator--(Date& d)
{
	Date date = Date(d.day, d.month, d.year);
	date.day--;
	if (date.day == 0)
	{
		if (date.month == 1)
		{
			date.day = monthToDays(12, date.year % 4 == 0);
		}
		else
		{
			date.day = monthToDays(date.month - 1, date.year % 4 == 0);
			date.month--;
		}
	}
	return date;

}

Date& operator++(Date& d)
{
	Date date = Date(d.day, d.month, d.year);
	date.day++;
	if (date.day > monthToDays(date.month, date.year % 4 == 0))
	{
		date.day = 1;
		date.month++;
	}
	if (date.month > 12)
	{
		date.month = 1;
		date.year++;
	}
	return date;
}

ostream& operator<<(ostream& cout, Date& date)
{
	if (date.day < 10)
		cout << "0";
	cout << date.day << ".";
	if (date.month < 10)
		cout << "0";
	cout << date.month << ".";
	if (date.year < 1000)
		cout << "0";
	else if (date.year < 100)
		cout << "00";
	else if (date.year < 10)
		cout << "000";
	cout << date.year;
	return cout;
}

Date::Date(string input)
{
	string dayS = "";
	string monthS = "";
	string yearS = "";
	int stage = 0;
	int start = 0;
	int l = input.size();

	// парсим ручками
	int finish = indexOf(input, '.', stage++);
	for (int i = start; i < finish; i++)
		dayS += input[i];
	start = finish + 1;
	finish = indexOf(input, '.', stage);
	for (int i = start; i < finish; i++)
		monthS += input[i];
	start = finish + 1;
	for (int i = start; i < l; i++)
		yearS += input[i];
	day = toInt(dayS);
	month = toInt(monthS);
	year = toInt(yearS);
};

long Date::getDiff(Date one, Date two)
{
	long result = 0;
	int bissextile1 = one.year / 4;
	int bissextile2 = two.year / 4;
	int i = 1;
	i = i + 1;
	i += 1;
	result += -(bissextile1 * 366) - ((one.year - bissextile1) * 365) + (bissextile2 * 366) + ((two.year - bissextile2) * 365);

	for (int i = 0; i < one.month - 1; i++)
	{
		result -= monthToDays(i, one.year % 4 == 0);
	}

	for (int i = 0; i < two.month - 1; i++)
	{
		result += monthToDays(i, two.year % 4 == 0);
	}

	result -= one.day;
	result += two.day;

	return result;
}