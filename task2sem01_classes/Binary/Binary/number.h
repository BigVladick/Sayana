#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number
{
	friend ostream& operator<<(ostream& cout, Number& pol);
	friend bool operator < (Number& first, Number& second);
	friend Number* operator*(Number& first, Number& second);
	friend Number* operator+(Number& first, Number& second);
private:
	static int const base = 2; // основание системы счисления
	string value;
	int length;
	void reverse();
	//void reduce();
	void addZeroes(int x);
public:
	Number() : value(""), length(0) {}
	Number(string s) :value(string(s)), length(s.size()) {}
	static Number& max(Number& a, Number& b)
	{
		return a < b ? b : a;
	}
	static Number& min(Number& a, Number& b)
	{
		return a < b ? a : b;
	}

};