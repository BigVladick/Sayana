#pragma once
#include <iostream>


using namespace std;


/*
Комплексное число
*/

class ComplexNumber
{
	friend ostream& operator<<(ostream& cout, ComplexNumber& complex);
	friend istream& operator>>(istream& cin, ComplexNumber& complex);
	friend ComplexNumber& operator+(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator-(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator*(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator/(ComplexNumber& one, ComplexNumber& two);
	friend bool operator==(ComplexNumber& one, ComplexNumber& two);
	friend bool operator!=(ComplexNumber& one, ComplexNumber& two);
	friend ComplexNumber& operator++(ComplexNumber& one);
	friend ComplexNumber& operator--(ComplexNumber& one);
	// Тип значение комлпексного числа состоит из мнимой и вещественной частей.
public:
	struct ComplexValue
	{
		ComplexValue() { ComplexValue(0, 0); }
		ComplexValue(double re, double im) : real(re), imaginary(im) {}
		double real;
		double imaginary;
	};


	ComplexValue value;
	ComplexNumber() { ComplexNumber(0, 0); }
	ComplexNumber(double re, double im) : value(ComplexValue(re, im)) {}
};

