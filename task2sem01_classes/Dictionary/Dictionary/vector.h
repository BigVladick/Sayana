#pragma once 
#include <iostream>

using namespace std;

/*
	Класс Vecotr - по сути оболочка вокруг динамического массива
	- int space = количество ячеек всего 
	- U* arr = динамический массив
	- append(U x) = Добавить в свободную ячейку, если есть, иначе расширить в 2 раза кол-во ячеек
	- has(U x) = Проверка есть ли здесь элемент с таким значением
	- print() = вывод всех элементов 
	- fromArray(U* arr, int size) = добавить массив элементов
	- U* toArray() = возвращает динамический массив
	- U at(int index) = возвращает элемент с указанным индексом
*/

template <class U>
class Vector
{
private:
	int space;
	U* arr;
public:
	int length;
	Vector() : space(1), arr(new U [space]()), length(0) {}
	~Vector();
	void append(U x);
	bool has(U x);
	void print();
	void fromArray(U* arr, int size);
	U* toArray();
	U at(int index);

};

template <class U>
Vector<U>::~Vector()
{
	delete[] arr;
}

template <class U>
void Vector<U>::append(U x)
{
	if (length + 1 > space)
	{
		U* slot = new U[space * 2]();
		for (int i = 0; i < length; i++)
		{
			slot[i] = U(arr[i]);
		}
		delete[] arr;
		arr = slot;
		space *= 2;
	}
	arr[length++] = x;
}

template <class U>
U Vector<U>::at(int index)
{
	return arr[index];
}

template <class U>
bool Vector<U>::has(U x)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == x)
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
		arrNova[i] = arr[i];
	}
	return arrNova;
}

template <class U>
void Vector<U>::print()
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << endl;
}

template <class U>
void Vector<U>::fromArray(U* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		append(U(arr[i]));
	}
}