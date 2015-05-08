#pragma once
#include "complexNumber.h"
#include "monomial.h"
#include "list.h"
#include "quickSort.h"

/*
Полином - состоит из списка Мономов.

<< - "красивый" вывод на экран
Операции: +, -, *, /, %
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
	// Список мономов
	List<Monomial>* monomials;
	Polynomial() : monomials(new List<Monomial>) {}
	Polynomial(List<Monomial>* m);
	~Polynomial();

	// подставление значения в полином
	ComplexNumber calc(ComplexNumber x);
private:
	// sort() - применяет QuickSort для сортировки списка по степени Монома.
	void sort();

	// при условии, что уже отсортированно
	// добавить промежуточные нули
	void addZeroes();

	// Приводим пободные и удаляем мономы с нулевым коэфтом
	void reduce();
};





