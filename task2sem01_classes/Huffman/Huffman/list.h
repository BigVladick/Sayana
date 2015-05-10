#pragma once
#include <iostream>
#include "quickSort.h"

using namespace std;

template <class U>

/*
	Измененем специально для Хаффмана
*/

/*
Класс List - двусвязный список. Двусвязный, потому что  2 связи : next  и previous.
- Inner = структура представляет собой 1 элемент списка
- U value = значение этого элемента
- Inner* next = указатель на следующий элемент списка
- Inner* previous = указатель на предыдущий элемент списка
- Inner* begin = начало списка
- Inner* end = конец списка
- int length = кол-во элементов в списке
- void fromArray(U arr[], int length) = добавить массив элементов
- void remove(Inner* sacredfice) = удаляет элемент списка по адрессу
- void append(U value) = добавляет элемент в конец списка
- U* toArray() = преобразует список в динамический массив и возвращает его
- void print() = вывод всех элементов списка
- U* has(U x) =  если элемент с таким значением есть, вернет указатель на него  иначе nullptr
*/

class List
{

public:
	/*
	Inner - один элемент списка
	*/
	struct Inner
	{
		// значение
		U value;
		// указатель на следующий
		Inner* next;
		// указатель на предыдущий
		Inner* previous;
		// указатель на левый
		Inner* left;
		// указатель на правый
		Inner* right;
		// указатель на отца
		Inner* father;
		Inner() {}
		~Inner() {}
		Inner(U val) : value(val), next(nullptr), previous(nullptr), left(nullptr), right(nullptr), father(nullptr) {}
		// проверка на (узел без потомков)
		bool isLast() { return left == nullptr && right == nullptr; }
	};
	// начало списка
	Inner* begin;
	// конец списка
	Inner* end;
	// length - длина всего списка
	int length;
	List() : begin(nullptr), end(nullptr), length(0){}
	// добавляет массив в конец списка
	void fromArray(U arr[], int length);
	// удаляет элемент по адресу
	void remove(Inner* sacredfice);
	// append - добавляет элемент в конец списка
	void append(U value);
	U* toArray();
	~List();
	void print();
	// есть ли тут элемент с таким значением
	Inner* has(U x);
	void sort()
	{
		int amount = length;
		U* arr = toArray();
		Inner* slot = begin;
		while (begin)
		{
			slot = begin;
			begin = begin->next;
			delete slot;
		}
		begin = nullptr;
		end = nullptr;
		Quicksort<U>(0, amount - 1, arr);
		fromArray(arr, amount);
		length = amount;
		delete[] arr;
	}
	void print(Inner* x)
	{
		x ? print(x->left) : 0;
		if (x)
			cout << x->value << endl;
		x ? print(x->right) : 0;

	}
};

template <class U>
void List<U>::fromArray(U arr[], int length)
{
	for (int i = 0; i < length; i++)
		append(U(arr[i]));
}

template <class U>
void List<U>::remove(Inner* sacredfice)
{
	if (!sacredfice)
		return;
	// если в середине
	if (sacredfice->next && sacredfice->previous)
	{
		(sacredfice->previous)->next = sacredfice->next;
		(sacredfice->next)->previous = sacredfice->previous;
	}
	// если в начале
	else if (sacredfice == begin)
	{
		begin = sacredfice->next;
		if (sacredfice->next)
			(sacredfice->next)->previous = nullptr;
	}
	// если в конце
	else
	{
		end = sacredfice->previous;
		(sacredfice->previous)->next = nullptr;
	}

	//delete sacredfice;
	length--;
	if (length == 0)
	{
		begin = nullptr;
		end = nullptr;
	}
}

template <class U>
void List<U>::append(U value)
{
	if (begin == nullptr)
	{
		begin = new Inner(value);
		end = begin;
	}
	else
	{
		Inner* slot = new Inner(value);
		slot->previous = end;
		end->next = slot;
		end = slot;
	}
	length++;
}

template <class U>
U* List<U>::toArray()
{
	U* arr = new U[length]();
	Inner* slot = begin;
	int index = 0;
	while (slot)
	{
		arr[index++] = slot->value;
		slot = slot->next;
	}
	return arr;
}

template <class U>
List<U>::~List()
{
	Inner* slot = begin;
	while (begin)
	{
		slot = begin;
		begin = begin->next;
		delete slot;
	}
}

template <class U>
void List<U>::print()
{
	Inner* slot = begin;
	while (slot)
	{
		cout << slot->value << endl;
		slot = slot->next;

	}
}

template <class U>
typename List<U>::Inner* List<U>::has(U x)
{
	Inner* slot = begin;
	while (slot)
	{
		if (slot->value == x)
			return slot;
		slot = slot->next;

	}
	return nullptr;
}

