#pragma once 
#include <iostream>

using namespace std;

/*
	Шаблонный класс вектор:
	- space = общее количество ячеек в массиве
	- length = кол-во занятый ячеек массива
	- arr = сам динамический массив 
	- append(U x) = добавить в конец массива
	- at(int index) = обратиться по индексу
	- has (U x) = проверка есть ли с таким значением
	- 
*/

template <class U>
class Vector
{
private:
	int space;
	U** arr;
public:
	int length;
	Vector() : space(1), arr(new U *[space]()), length(0) {}
	~Vector();
	void append(U* x);
	bool has(U x);
	void print();
	U* toArray();
	U* at(int index);

};

template <class U>
Vector<U>::~Vector()
{
	for (int i = 0; i < length; i++)
	{
		delete[] arr[i];
	}
}

template <class U>
void Vector<U>::append(U* x)
{
	// место кончилось
	if (length + 1 > space)
	{
		U** slot = new U*[space * 2]();
		for (int i = 0; i < length; i++)
		{
			slot[i] = new U(*arr[i]);
		}
		for (int i = 0; i < length; i++)
		{
			delete[] arr[i];
		}
		
		arr = slot;
		space *= 2;
	}
	arr[length++] = x;
}

template <class U>
U* Vector<U>::at(int index)
{
	return arr[index];
}

template <class U>
bool Vector<U>::has(U x)
{
	for (int i = 0; i < length; i++)
	{
		if (*arr[i] == x)
		{
			return true;
		}
	}
	return false;
}

template <class U>
U* Vector<U>::toArray()
{
	U* arrNova = new U[length]();
	for (int i = 0; i < length; i++)
	{
		arrNova[i] = *arr[i];
	}
	return arrNova;
}

template <class U>
void Vector<U>::print()
{
	for (int i = 0; i < length; i++)
		cout << *arr[i] << endl;
}