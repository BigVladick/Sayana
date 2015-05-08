#pragma once
#include "complexNumber.h"


/*
����� - ������� �� ������������ ����������� � �������.
����������� < � > ��� ��������� �������.
�������������� � �������� �����������
*/

class Monomial
{
public:
	friend bool operator<(Monomial& a, Monomial& b)
	{
		return a.degree < b.degree;
	}
	friend bool operator>(Monomial& a, Monomial& b)
	{
		return (a.degree > b.degree);
	}

	ComplexNumber coefficient;
	int degree;
	Monomial() {}
	Monomial(ComplexNumber c, int d) : coefficient(c), degree(d) {}
	// ����������� �����������. ��� ���� ���������� ����� ������� Monomial �� ������ �������
	Monomial(const Monomial& from);
	// �������� ������������. ������ ��������, ��� ��� friend. ��������� ����� Monomial �� ������ �������.
	Monomial& operator=(const Monomial& from);
};