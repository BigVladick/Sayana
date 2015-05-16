#pragma once
#include <iostream>
#include "list.h"

using namespace std;

/*
	HashTable - хэш таблица, коллизиции разрешаются методом цепочек. 
				Значит нужен список, благо список у нас уже есть и тогда все просто!!!
	static const int size = 1000 - размер , ХФ(хэш функция) вычисляется по этому модулю
	List<U> lists[size] = массив списков
	int length = кол-во элементов
	Ну и 5 интерфейсных функий
*/

template <class U>
class HashTable
{
private:
	static const int size = 1000;
	List<U> lists[size];
	int length;
public:
	HashTable(): length(0) {}
	// Необходимый интерфейс словаря
	void append(U x);
	void print();
	bool has(U x);
	void fromArray(U* x, int len);
	U* toArray();
};

template <class U>
void HashTable<U>::append(U x)
{
	lists[x.getHash(size)].append(x);
	length++;
}

template <class U>
void HashTable<U>::print()
{
	for (int i = 0; i < size; i++)
		if (lists[i].length > 0)
		{
			lists[i].print();
		}
}

template <class U>
bool HashTable<U>::has(U x)
{
	for (int i = 0; i < size; i++)
		if (lists[i].length > 0)
		{
			if (lists[i].has(x))
				return true;
		}
	// лучше не трогать для char*
	return false;
}

template <class U>
void HashTable<U>::fromArray(U* x, int len)
{
	for (int i = 0; i < len; i++)
		append(x[i]);
}

template <class U>
U* HashTable<U>::toArray()
{
	U* arr = new U[length]();
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (lists[i].length > 0)
		{
			U* slot = lists[i].toArray();
			for (int j = 0; j < lists[i].length; j++)
			{
				arr[index++] = slot[j];
			}
			delete[] slot;
		}
	}
	return arr;
}