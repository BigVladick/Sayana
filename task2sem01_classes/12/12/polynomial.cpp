#include "polynomial.h"

Polynomial::Polynomial(List<Monomial>* m)
{
	monomials = new List<Monomial>();
	List<Monomial>::Inner* slot = m->begin;
	while (slot)
	{
		monomials->append(new Monomial(*slot->value));
		slot = slot->next;
	}

}

Polynomial::~Polynomial()
{
	delete monomials;
}

ComplexNumber Polynomial::calc(ComplexNumber x)
{
	ComplexNumber result = ComplexNumber(0, 0);
	sort();
	reduce();
	List<Monomial>::Inner* slot = monomials->begin;
	while (slot)
	{
		int deg = 0;
		ComplexNumber xDeg = ComplexNumber(1, 0);
		while (deg < slot->value->degree)
		{
			xDeg = xDeg * x;
			deg++;
		}
		ComplexNumber mul = (slot->value->coefficient * xDeg);
		result = result + mul;
		slot = slot->next;
	}
	return result;
}

void Polynomial::sort()
{
	int length = monomials->length;
	// список -> массив
	Monomial* arr = monomials->toArray();

	// Быстрая сортировка
	Quicksort<Monomial>(0, length - 1, arr);

	// массив -> список
	delete monomials;
	monomials = new List < Monomial >();
	monomials->fromArray(arr, length);
	delete[] arr;
}

void Polynomial::addZeroes()
{
	int end = monomials->end->value->degree;
	ComplexNumber zero = ComplexNumber(0, 0);
	List<Monomial>::Inner* slot = monomials->begin;
	for (int i = 0; i < end; i++)
	{
		if (slot->value->degree == i)
		{
			slot = slot->next;
		}
		else
		{
			monomials->append(new Monomial(zero, i));
		}
	}
}

void Polynomial::reduce()
{
	// одинаковые степени складываются
	List<Monomial>::Inner* slot = monomials->begin;
	while (slot)
	{
		while (slot->next &&  slot->value->degree == slot->next->value->degree)
		{
			slot->value->coefficient = slot->next->value->coefficient + slot->value->coefficient;
			monomials->remove(slot->next);
			// теперь нужно удалить элемент с адресом slot->next
		}
		slot = slot->next;
	}


	// удаляем нули
	slot = monomials->begin;
	List<Monomial>::Inner* memory = nullptr;
	while (slot)
	{
		memory = nullptr;
		if (slot->value->coefficient == ComplexNumber(0, 0))
		{
			memory = slot;
		}
		slot = slot->next;
		if (memory)
			monomials->remove(memory);
	}
}


ostream& operator<<(ostream& cout, Polynomial& pol)
{
	List<Monomial>::Inner* slot = pol.monomials->begin;
	while (slot)
	{
		cout << "(";
		cout << slot->value->coefficient;
		cout << ")";
		if (slot->value->degree > 0)
		{
			cout << "*x";
			if (slot->value->degree > 1)
				cout << "^" << slot->value->degree;
		}
		slot = slot->next;
		if (slot != nullptr)
			cout << "+";
	}
	if (pol.monomials->length == 0)
		cout << "0";
	return cout;
}

Polynomial* operator+(Polynomial& first, Polynomial& second)
{
	Polynomial* result = new Polynomial(first.monomials);
	// прибавим второй список к первому
	Monomial* secondList = second.monomials->toArray();


	result->monomials->fromArray(secondList, second.monomials->length);
	delete secondList;

	// отсортируем
	result->sort();

	// приведем пободные
	result->reduce();
	return result;
}

Polynomial* operator-(Polynomial& first, Polynomial& second)
{
	Polynomial* result = new Polynomial(first.monomials);

	// прибавим второй список к первому * -1
	Monomial* secondList = second.monomials->toArray();
	for (int i = 0; i < second.monomials->length; i++)
		secondList[i].coefficient = secondList[i].coefficient * ComplexNumber(-1, 0);

	result->monomials->fromArray(secondList, second.monomials->length);

	delete secondList;

	// отсортируем
	result->sort();


	// приведем пободные
	result->reduce();


	return result;
}

Polynomial* operator*(Polynomial& first, Polynomial& second)
{
	List<Monomial>::Inner* firstBegin = first.monomials->begin;
	List<Monomial>::Inner* secondBegin = second.monomials->begin;
	Polynomial* result = new Polynomial();
	while (firstBegin)
	{
		secondBegin = second.monomials->begin;
		while (secondBegin)
		{
			//cout << "here\n";
			ComplexNumber complex = ComplexNumber(firstBegin->value->coefficient * secondBegin->value->coefficient);
			int degree = firstBegin->value->degree + secondBegin->value->degree;
			result->monomials->append(new Monomial(complex, degree));

			secondBegin = secondBegin->next;
		}
		firstBegin = firstBegin->next;
	}
	result->sort();
	result->reduce();
	return result;
}

Polynomial* operator/(Polynomial& first, Polynomial& second)
{
	// http://www.cyberforum.ru/cpp-beginners/thread328191.html


	// не трогаем входные данные - создаем копии
	//cout << "before start:\n";
	Polynomial* b = new Polynomial(first.monomials);
	Polynomial* c = new Polynomial(second.monomials);
	Polynomial* result = new Polynomial();

	//cout << "b=" << *b << endl;
	//cout << "c=" << *c << endl;


	int diffDim = 100;

	while (diffDim > 0)
	{
		delete c;
		c = new Polynomial(second.monomials);
		// шаг1 повысим степень делителя до степени знаменателя. Дполним промужуточными нулями.
		b->addZeroes();
		b->sort();
		c->addZeroes();
		int dim1 = b->monomials->length;
		int dim2 = c->monomials->length;
		diffDim = dim1 - dim2;
		List<Monomial>::Inner* secondBegin = c->monomials->begin;
		while (secondBegin)
		{
			secondBegin->value->degree += diffDim;
			secondBegin = secondBegin->next;
		}
		c->addZeroes();
		c->sort();
		//cout << "step one:\n";
		//cout << "b=" << *b << endl;
		//cout << "c=" << *c << endl;

		// шаг2 умножить на коэф-т старшего монома
		ComplexNumber olderCoefficient = b->monomials->end->value->coefficient;
		secondBegin = c->monomials->begin;
		result->monomials->append(new Monomial(olderCoefficient, diffDim));
		while (secondBegin)
		{
			secondBegin->value->coefficient = secondBegin->value->coefficient * olderCoefficient;
			secondBegin = secondBegin->next;
		}
		//cout << "step two:\n";
		//cout << "b=" << *b << endl;
		//cout << "c=" << *c << endl;


		// шаг 3 вычесть делитель из делимого. Отнимем степени обратно
		Polynomial* diff = *b - *c;
		delete b;
		b = diff;
		c->reduce();
		b->reduce();
		b->sort();
		secondBegin = c->monomials->begin;
		while (secondBegin)
		{
			secondBegin->value->degree -= diffDim;
			secondBegin = secondBegin->next;
		}
		//cout << "step three:\n";
		//cout << "b=" << *b << endl;
		//cout << "c=" << *c << endl;

		//cout << "\n\n";

	}


	delete b; //
	delete c;
	result->sort();
	return result;
}


Polynomial* operator%(Polynomial& first, Polynomial& second)
{
	Polynomial* divRes = first / second;
	Polynomial* mulRes = *divRes * second;
	Polynomial* diffRes = first - *mulRes;
	diffRes->reduce();
	diffRes->sort();
	delete divRes;
	delete mulRes;
	return diffRes;
}
