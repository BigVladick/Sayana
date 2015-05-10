#include "monomial.h"

Monomial::Monomial(const Monomial& from)
{
	degree = from.degree;
	coefficient = ComplexNumber(from.coefficient.value.real, from.coefficient.value.imaginary);
}

Monomial& Monomial::operator=(const Monomial& from)
{
	degree = int(from.degree);
	coefficient = ComplexNumber(from.coefficient.value.real, from.coefficient.value.imaginary);
	return *this;
}