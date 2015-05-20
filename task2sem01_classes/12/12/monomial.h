#pragma once
//#include "complexNumber.h"


/*
Моном - состоит из комплексного коэфициента и степени.
Реализованы < и > как сравнение степени.
Коструструктор и оператор копирования
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
	
	Monomial(U c, int d)
	{
		degree = d;
		coefficient = *new U(c);
		//coefficient = *(new U(c)) ;
	}
	
	// Конструктор копирования. Для того создавался новый элемент Monomial на основе страроо
	Monomial(const Monomial& from);
	// Оператор присваивания. Обрати внимание, что без friend. Создается новый Monomial на основе старого.
	/*
	Monomial& operator=(const Monomial& from)
	{
		cout << "used = \n";
		degree = int(from.degree);
		coefficient =* new U(from.coefficient);
		return *this;
	}
	*/
	
};


template <class U>
Monomial<U>::Monomial(const Monomial& from)
{
	degree = from.degree;
	coefficient = *new U(from.coefficient);
}

