#pragma once
#include <cstring>
#include <iostream>

using namespace std;

class LongNumber
{
	friend ostream& operator<<(ostream& cout, LongNumber& pol);
	friend LongNumber& operator+(LongNumber& f, LongNumber& s);
	friend LongNumber& operator-(LongNumber& f, LongNumber& s);
	friend LongNumber& operator*(LongNumber& f, LongNumber& s);
	friend LongNumber& operator*(LongNumber& one, int num);
	friend LongNumber& operator/(LongNumber& f, LongNumber& s);
	friend bool operator < (LongNumber& first, LongNumber& second);
	friend bool operator == (LongNumber& first, LongNumber& second);
	friend bool operator != (LongNumber& first, LongNumber& second);
	friend bool operator <= (LongNumber& first, LongNumber& second);
private:
	int length;
	static int const size = 10;
	int value[size];
	bool sign;
	static LongNumber max(LongNumber a, LongNumber b);
	static LongNumber min(LongNumber a, LongNumber b);
	LongNumber& reduce();
	LongNumber& addZeroes(int x);
	

public:
	bool  operator! ();
	LongNumber() {}
	LongNumber(int num);
	LongNumber(char* s);

};
