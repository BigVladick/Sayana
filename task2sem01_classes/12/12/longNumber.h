#pragma once
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class LongNumber
{
	friend ostream& operator<<(ostream& cout, LongNumber& pol); // +
	friend bool operator < (LongNumber& first, LongNumber& second); //+
	friend bool operator > (LongNumber& first, LongNumber& second);
	friend bool operator >= (LongNumber& first, LongNumber& second);
	friend bool operator == (LongNumber& first, LongNumber& second); //+
	friend bool operator <= (LongNumber& first, LongNumber& second); //+
	friend LongNumber& operator+(LongNumber& f, LongNumber& s); // +
	friend LongNumber& operator-(LongNumber& f, LongNumber& s); //+
	friend LongNumber& operator*(LongNumber& f, LongNumber& s); //+
	friend LongNumber& operator*(LongNumber& f, int num);
	friend LongNumber& operator/(LongNumber& f, LongNumber& s); //+
	friend LongNumber& operator^(LongNumber& first, int deg); //+
private:
	bool sign;
	int* value; 
	int length;
	// перевернуть
	LongNumber& reverse(); //+
	// убрать нули из начала
	LongNumber& reduce(); //+
	// добавить нули в конец
	LongNumber& addZeroes(int x); //+
public:
	/*
	LongNumber& operator=(const LongNumber& num)
	{
		//LongNumber* x = new LongNumber(num);
		//return *x;
		cout << "operator = used\n";
		length = num.length;
		value = new int[length];
		for (int i = 0; i < length; i++)
			value[i] = num.value[i];
		return *this;
	}
	*/
	bool  operator! ();
	LongNumber() : sign(true), value(nullptr), length(0) {}
	LongNumber(char* s);
	~LongNumber();
	LongNumber(const LongNumber & object);
	/*
	LongNumber& operator=(const LongNumber& from)
	{
		value = from.value;
		length = from.length;
		sign = from.sign;
		return *this;
	}
	*/
	static LongNumber max(LongNumber a, LongNumber b); //+
	static LongNumber min(LongNumber a, LongNumber b); //+
};