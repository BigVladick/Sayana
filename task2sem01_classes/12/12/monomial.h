#pragma once
#include "complexNumber.h"


/*
Моном - состоит из комплексного коэфициента и степени.
Реализованы < и > как сравнение степени.
Коструструктор и оператор копирования
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
	// Конструктор копирования. Для того создавался новый элемент Monomial на основе страроо
	Monomial(const Monomial& from);
	// Оператор присваивания. Обрати внимание, что без friend. Создается новый Monomial на основе старого.
	Monomial& operator=(const Monomial& from);
};