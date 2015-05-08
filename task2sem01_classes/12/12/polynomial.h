#pragma once
#include "complexNumber.h"
#include "monomial.h"
#include "list.h"
#include "quickSort.h"

/*
������� - ������� �� ������ �������.

<< - "��������" ����� �� �����
��������: +, -, *, /, %
*/

class Polynomial
{
	friend ostream& operator<<(ostream& cout, Polynomial& pol);
	friend Polynomial* operator+(Polynomial& first, Polynomial& second);
	friend Polynomial* operator-(Polynomial& first, Polynomial& second);
	friend Polynomial* operator*(Polynomial& first, Polynomial& second);
	friend Polynomial* operator/(Polynomial& first, Polynomial& second);
	friend Polynomial* operator%(Polynomial& first, Polynomial& second);
public:
	// ������ �������
	List<Monomial>* monomials;
	Polynomial() : monomials(new List<Monomial>) {}
	Polynomial(List<Monomial>* m);
	~Polynomial();

	// ������������ �������� � �������
	ComplexNumber calc(ComplexNumber x);
private:
	// sort() - ��������� QuickSort ��� ���������� ������ �� ������� ������.
	void sort();

	// ��� �������, ��� ��� ��������������
	// �������� ������������� ����
	void addZeroes();

	// �������� �������� � ������� ������ � ������� �������
	void reduce();
};





