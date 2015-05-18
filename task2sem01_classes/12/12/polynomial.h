#pragma once
#include <iostream>
#include "complexNumber.h"
#include "monomial.h"
#include "list.h"

using namespace std;

/*
ѕолином - состоит из списка ћономов.

<< - "красивый" вывод на экран
ќперации: +, -, *, /, %
*/

/*
template <class U>
class Polynomial;

template <class U>
Polynomial<U>* operator+(Polynomial<U>& first, Polynomial<U>& second);
*/

template <class U>
class Polynomial
{
	friend ostream& operator<<(ostream& cout, Polynomial& pol)
	{
		List<Monomial<U>>::Inner* slot = pol.monomials->begin;
		while (slot)
		{
			cout << "(";
			cout << slot->value.coefficient;
			cout << ")";
			if (slot->value.degree > 0)
			{
				cout << "*x";
				if (slot->value.degree > 1)
					cout << "^" << slot->value.degree;
			}
			slot = slot->next;
			if (slot != nullptr)
				cout << "+";
		}
		if (pol.monomials->length == 0)
			cout << "0";
		return cout;
	}
	friend Polynomial* operator+(Polynomial& first, Polynomial& second)
	{
		Polynomial* result = new Polynomial(first.monomials);
		// прибавим второй список к первому
		Monomial<U>* secondList = second.monomials->toArray();
		result->monomials->fromArray(secondList, second.monomials->length);
		delete secondList;
		// приведем пободные
		result->reduce();
		return result;
	}
	friend Polynomial* operator-(Polynomial& first, Polynomial& second)
	{
		Polynomial* result = new Polynomial(first.monomials);

		// прибавим второй список к первому * -1
		Monomial<U>* secondList = second.monomials->toArray();
		for (int i = 0; i < second.monomials->length; i++)
			secondList[i].coefficient = secondList[i].coefficient * (-1);

		result->monomials->fromArray(secondList, second.monomials->length);

		delete secondList;

		// приведем пободные
		result->reduce();


		return result;
	}
	friend Polynomial* operator*(Polynomial& first, Polynomial& second)
	{
		List<Monomial<U>>::Inner* firstBegin = first.monomials->begin;
		List<Monomial<U>>::Inner* secondBegin = second.monomials->begin;
		Polynomial* result = new Polynomial();
		while (firstBegin)
		{
			secondBegin = second.monomials->begin;
			while (secondBegin)
			{
				//cout << "here\n";
				U complex = U(firstBegin->value.coefficient * secondBegin->value.coefficient);
				int degree = firstBegin->value.degree + secondBegin->value.degree;
				result->monomials->append(Monomial<U>(complex, degree));

				secondBegin = secondBegin->next;
			}
			firstBegin = firstBegin->next;
		}
		result->reduce();
		return result;
	}
	friend Polynomial* operator/(Polynomial& first, Polynomial& second)
	{
		// http://www.cyberforum.ru/cpp-beginners/thread328191.html
		// не трогаем входные данные - создаем копии
		Polynomial* b = new Polynomial(first.monomials);
		Polynomial* c = new Polynomial(second.monomials);
		Polynomial* result = new Polynomial();

		
		if (first == second)
		{
			U one = 1;
			result->monomials->append(Monomial<U>(one, 0));
			return result;
		}

		int diffDim = 100;

		while (diffDim > 0)
		{
			delete c;
			c = new Polynomial(second.monomials);
			// шаг1 повысим степень делител€ до степени знаменател€. ƒполним промужуточными нул€ми.
			b->addZeroes();
			c->addZeroes();
			int dim1 = b->monomials->length;
			int dim2 = c->monomials->length;
			diffDim = dim1 - dim2;
			List<Monomial<U>>::Inner* secondBegin = c->monomials->begin;
			while (secondBegin)
			{
				secondBegin->value.degree += diffDim;
				secondBegin = secondBegin->next;
			}
			c->addZeroes();

			// шаг2 умножить на коэф-т старшего монома
			U olderCoefficient = b->monomials->end->value.coefficient;
			secondBegin = c->monomials->begin;
			result->monomials->append(Monomial<U>(olderCoefficient, diffDim));
			while (secondBegin)
			{
				secondBegin->value.coefficient = secondBegin->value.coefficient * olderCoefficient;
				secondBegin = secondBegin->next;
			}

			// шаг 3 вычесть делитель из делимого. ќтнимем степени обратно
			Polynomial* diff = *b - *c;
			delete b;
			b = diff;
			c->reduce();
			b->reduce();
			secondBegin = c->monomials->begin;
			while (secondBegin)
			{
				secondBegin->value.degree -= diffDim;
				secondBegin = secondBegin->next;
			}
		}

		delete b;
		delete c;
		return result;
	}
	friend Polynomial* operator%(Polynomial& first, Polynomial& second)
	{
		Polynomial<U>* divRes = first / second;
		Polynomial<U>* mulRes = *divRes * second;
		Polynomial<U>* diffRes = first - *mulRes;
		diffRes->reduce();
		delete divRes;
		delete mulRes;
		return diffRes;
	}
	friend bool operator==(Polynomial& first, Polynomial& second)
	{
		if (first.monomials->length != second.monomials->length)
		{
			return false;
		}
		else
		{
			List<Monomial<U>>::Inner* f = first.monomials->begin;
			List<Monomial<U>>::Inner* s = second.monomials->begin;
			while (f)
			{
				if (f->value.coefficient != s->value.coefficient || f->value.degree != s->value.degree)
				{
					return false;
				}
				f = f->next;
				s = s->next;
			}
		}
		return true;
	}
public:
	// —писок мономов
	List<Monomial<U>>* monomials;
	Polynomial() : monomials(new List<Monomial<U>>) {}
	Polynomial(List<Monomial<U>>* m);
	~Polynomial();
	// подставление значени€ в полином
	U calc(U x);
private:
	// добавить промежуточные нули
	void addZeroes();
	// ѕриводим пободные и удал€ем мономы с нулевым коэфтом
	void reduce();
};

template <class U>
Polynomial<U>::Polynomial(List<Monomial<U>>* m)
{
	monomials = new List<Monomial<U>>();
	List<Monomial<U>>::Inner* slot = m->begin;
	while (slot)
	{
		monomials->append(Monomial<U>(slot->value));
		slot = slot->next;
	}
}

template <class U>
Polynomial<U>::~Polynomial()
{
	delete monomials;
}


template <class U>
U Polynomial<U>::calc(U x)
{
	U result = U(0, 0);
	reduce();
	List<Monomial<U>>::Inner* slot = monomials->begin;
	while (slot)
	{
		int deg = 0;
		U xDeg = U(1, 0);
		while (deg < slot->value.degree)
		{
			xDeg = xDeg * x;
			deg++;
		}
		U mul = (slot->value.coefficient * xDeg);
		result = result + mul;
		slot = slot->next;
	}
	return result;
}

template <class U>
void Polynomial<U>::addZeroes()
{
	int end = monomials->end->value.degree;
	U zero = 0;
	List<Monomial<U>>::Inner* slot = monomials->begin;
	for (int i = 0; i < end; i++)
	{
		if (slot->value.degree == i)
		{
			slot = slot->next;
		}
		else
		{
			monomials->append(Monomial<U>(zero, i));
		}
	}
}

template <class U>
void Polynomial<U>::reduce()
{
	// одинаковые степени складываютс€
	List<Monomial<U>>::Inner* slot = monomials->begin;
	while (slot)
	{
		while (slot->next &&  slot->value.degree == slot->next->value.degree)
		{
			slot->value.coefficient = slot->next->value.coefficient + slot->value.coefficient;
			monomials->remove(slot->next);
			// теперь нужно удалить элемент с адресом slot->next
		}
		slot = slot->next;
	}


	// удал€ем нули
	slot = monomials->begin;
	List<Monomial<U>>::Inner* memory = nullptr;
	while (slot)
	{
		memory = nullptr;
		if (!slot->value.coefficient)
		{
			memory = slot;
		}
		slot = slot->next;
		if (memory)
			monomials->remove(memory);
	}
}

