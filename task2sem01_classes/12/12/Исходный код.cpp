#pragma once
#include <iostream>
#include "quickSort.h"
#include "list.h"
#include "complexNumber.h"
#include "monomial.h"
#include "polynomial.h"

using namespace std;

// Внимание - операторы должны создавать новый объект!!


int main()
{
	
	List<Monomial>* monomials1 = new List<Monomial>();
	monomials1->append(new Monomial(ComplexNumber(1, 1), 0)); // (1+i)
	monomials1->append(new Monomial(ComplexNumber(1, -1), 1)); // (1-i)*x
	monomials1->append(new Monomial(ComplexNumber(-1, 1), 2)); // (-1+i)*x^2
	monomials1->append(new Monomial(ComplexNumber(-1, -1), 3)); // (-1-i)*x^3
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
	monomials2->append(new Monomial(ComplexNumber(-42, 0), 0));
	monomials2->append(new Monomial(ComplexNumber(-12, 0), 2));
	monomials2->append(new Monomial(ComplexNumber(1, 0), 3));

	// x - 3
	List<Monomial>* monomials3 = new List<Monomial>();
	monomials3->append(new Monomial(ComplexNumber(-3, 0), 0));
	monomials3->append(new Monomial(ComplexNumber(1, 0), 1));
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
	

	return 0;
}