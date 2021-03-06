#pragma once
#include <iostream>


using namespace std;


/*
����������� �����
*/

class ComplexNumber
{
	friend ostream& operator<<(ostream& cout, ComplexNumber& complex);
	friend istream& operator>>(istream& cin, ComplexNumber& complex);
	friend ComplexNumber& operator+(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator-(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator*(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator*(ComplexNumber& one, int num);
	friend ComplexNumber& operator/(ComplexNumber& one, ComplexNumber& two);
	friend bool operator==(ComplexNumber& one, ComplexNumber& two);
	friend bool operator!=(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator++(ComplexNumber& one);
	friend ComplexNumber& operator--(ComplexNumber& one);
	
	// ��� �������� ������������ ����� ������� �� ������ � ������������ ������.
public:
	struct ComplexValue
	{
		ComplexValue() { ComplexValue(0, 0); }
		ComplexValue(double re, double im) : real(re), imaginary(im) {}
		double real;
		double imaginary;
	};
	bool  operator! ();
	ComplexNumber& operator=(int num)
	{
		value = ComplexValue(num, 0);
		return *this;
	}
	ComplexValue value;
	ComplexNumber() { ComplexNumber(0, 0); }
	ComplexNumber(int x);
	ComplexNumber(double re, double im) : value(ComplexValue(re, im)) {}
};

