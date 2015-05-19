#pragma once
#include <iostream>
#include "list.h"
#include "complexNumber.h"
#include "monomial.h"
#include "polynomial.h"
#include "longNumber.h"

using namespace std;

// Внимание - операторы должны создавать новый объект!!

/*
CL13.	Реализовать шаблон класса «полином». Работоспособность тестируется для вариантов
	    специализации с целыми, вещественными, комплексными, длинными целыми числами.
*/


int main()
{
	LongNumber x1 = LongNumber("21");
	LongNumber x2 = LongNumber("3");
	LongNumber x3 = x1 + x2;
	cout << x3 << endl;
	return 0;

	ComplexNumber a = ComplexNumber(1, 1);
	ComplexNumber b = ComplexNumber(1, -1);
	ComplexNumber c = ComplexNumber(-1, 1);
	ComplexNumber d = ComplexNumber(-1, -1);
	List<Monomial<ComplexNumber>>* monomials = new List<Monomial<ComplexNumber>>();
	monomials->append(Monomial<ComplexNumber>(a, 0)); // (1+i)
	monomials->append(Monomial<ComplexNumber>(b, 1)); // (1-i)*x
	monomials->append(Monomial<ComplexNumber>(c, 2)); // (-1+i)*x^2
	monomials->append(Monomial<ComplexNumber>(d, 3)); // (-1-i)*x^3
	//monomials->print();

	
	List<Monomial<int>>* monomials2 = new List<Monomial<int>>();
	monomials2->append(Monomial<int>(1, 0));
	monomials2->append(Monomial<int>(1, 1));
	//monomials2->append(Monomial<int>(3, 2));
	//monomials2->append(Monomial<int>(4, 3));
	//monomials2->print();

	Polynomial<int> polynomial2 = Polynomial<int>(monomials2);
	cout << polynomial2 << endl;
	Polynomial<int>* res = polynomial2 % polynomial2;
	cout << *res << endl;
	delete res;
	

	Polynomial<ComplexNumber> polynomial = Polynomial<ComplexNumber>(monomials);
	Polynomial<ComplexNumber>* diff = polynomial * polynomial;
	//cout << *diff << endl;
	//cout << *diff << endl;
	delete monomials;


	/*
	List<Monomial>* monomials1 = new List<Monomial>();
	monomials1->append(Monomial(ComplexNumber(1, 1), 0)); 
	monomials1->append(Monomial(ComplexNumber(1, -1), 1)); 
	monomials1->append(Monomial(ComplexNumber(-1, 1), 2)); 
	monomials1->append(Monomial(ComplexNumber(-1, -1), 3)); 
	Polynomial polynomial = Polynomial(monomials1); // деструктор почисит первый раз
	Polynomial* diff = polynomial - polynomial;
	Polynomial* sum = polynomial + polynomial;
	Polynomial* mul = polynomial * polynomial;


	cout << "a:=" << polynomial << endl;
	cout << "a-a:=" << *diff << endl;
	cout << "a+a:=" << *sum << endl;
	cout << "a*a:=" << *mul << endl;

	delete monomials1;
	delete diff;
	delete sum;
	delete mul;

	cout << "now I am doing division\n";

	// x^3 -12x - 42
	List<Monomial>* monomials2 = new List<Monomial>();
	monomials2->append(Monomial(ComplexNumber(-42, 0), 0));
	monomials2->append(Monomial(ComplexNumber(-12, 0), 2));
	monomials2->append(Monomial(ComplexNumber(1, 0), 3));

	// x - 3
	List<Monomial>* monomials3 = new List<Monomial>();
	monomials3->append(Monomial(ComplexNumber(-3, 0), 0));
	monomials3->append(Monomial(ComplexNumber(1, 0), 1));
	Polynomial b = Polynomial(monomials2);
	Polynomial c = Polynomial(monomials3);
	cout << "b:=" << b << endl;
	cout << "c:=" << c << endl;
	Polynomial* div = b / c;
	Polynomial* div2 = b % c;
	cout << "b/c:=" << *div << endl;
	cout << "b%c:=" << *div2 << endl;
	//polynomial.calc(ComplexNumber(1, 0));
	cout << "a(1):=" << polynomial.calc(ComplexNumber(1, 0)) << endl;

	delete monomials2;
	delete monomials3;
	delete div;
	delete div2;
	*/

	return 0;
}