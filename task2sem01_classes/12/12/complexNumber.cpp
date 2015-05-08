#include "complexNumber.h"

ComplexNumber& operator+(ComplexNumber& one, ComplexNumber& two)
{
	return ComplexNumber(one.value.real + two.value.real, one.value.imaginary + two.value.imaginary);
}
ComplexNumber& operator-(ComplexNumber& one, ComplexNumber& two)
{
	return ComplexNumber(one.value.real - two.value.real, one.value.imaginary - two.value.imaginary);
}

bool operator==(ComplexNumber& one, ComplexNumber& two)
{
	return one.value.real == two.value.real && one.value.imaginary == two.value.imaginary;
}
bool operator!=(ComplexNumber& one, ComplexNumber& two)
{
	return !(one == two);
}

istream& operator>>(istream& cin, ComplexNumber& complex)
{
	cin >> complex.value.real >> complex.value.imaginary;
	return cin;
}

ComplexNumber& operator++(ComplexNumber& one)
{
	return one + ComplexNumber(1, 1);
}
ComplexNumber& operator--(ComplexNumber& one)
{
	return one - ComplexNumber(1, 1);
}

ComplexNumber& operator*(ComplexNumber& one, ComplexNumber& two)
{
	return ComplexNumber(one.value.real * two.value.real - one.value.imaginary * two.value.imaginary,
		one.value.real * two.value.imaginary + one.value.imaginary * two.value.real);
}

ComplexNumber& operator/(ComplexNumber& one, ComplexNumber& two)
{
	// http://www.fxyz.ru/%D1%84%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D1%8B_%D0%BF%D0%BE_%D0%BC%D0%B0%D1%82%D0%B5%D0%BC%D0%B0%D1%82%D0%B8%D0%BA%D0%B5/%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%B0/%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D1%85_%D1%87%D0%B8%D1%81%D0%B5%D0%BB/
	double sumSquaresSecond = two.value.real *  two.value.real + two.value.imaginary * two.value.imaginary;
	double real = (one.value.real * two.value.real + one.value.imaginary * two.value.imaginary) / sumSquaresSecond;
	double imaginary = (two.value.real * one.value.imaginary - two.value.imaginary * one.value.real) / sumSquaresSecond;
	return ComplexNumber(real, imaginary);
}

ostream& operator<<(ostream& cout, ComplexNumber& complex)
{
	if (!complex.value.real && !complex.value.imaginary)
		cout << "0";

	if (complex.value.real)
		cout << complex.value.real;

	if (complex.value.imaginary > 0 && complex.value.real)
		cout << "+";


	if (complex.value.imaginary)
	{
		if (complex.value.imaginary == 1)
			cout << "i";
		else if (complex.value.imaginary == -1)
			cout << "-i";
		else
			cout << complex.value.imaginary << "i";

	}
	return cout;
}
