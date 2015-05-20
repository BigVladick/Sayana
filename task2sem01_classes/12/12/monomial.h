#pragma once
//#include "complexNumber.h"


/*
����� - ������� �� ������������ ����������� � �������.
����������� < � > ��� ��������� �������.
�������������� � �������� �����������
*/

template <class U>
class Monomial
{
public:
	friend ostream& operator<<(ostream& cout, Monomial& b) // 
	{
		cout << "(" << b.coefficient << ")*x^" << b.degree;
		return cout;
	}
	friend bool operator<(Monomial& a, Monomial& b)
	{
		return a.degree < b.degree;
	}
	friend bool operator>=(Monomial& a, Monomial& b)
	{
		return a > b || a.degree == b.degree;
	}
	friend bool operator>(Monomial& a, Monomial& b)
	{
		return (a.degree > b.degree);
	}

	U coefficient;
	int degree;
	Monomial() {}
	Monomial(U c, int d) : coefficient(c), degree(d) {}
	// ����������� �����������. ��� ���� ���������� ����� ������� Monomial �� ������ �������
	Monomial(const Monomial& from);
	// �������� ������������. ������ ��������, ��� ��� friend. ��������� ����� Monomial �� ������ �������.
	Monomial& operator=(const Monomial& from)
	{
		degree = int(from.degree);
		coefficient = U(from.coefficient);
		return *this;
	}
};

template <class U>
Monomial<U>::Monomial(const Monomial& from)
{
	degree = from.degree;
	coefficient = U(from.coefficient);
}
