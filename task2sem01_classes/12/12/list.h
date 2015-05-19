#pragma once
#include <iostream>

using namespace std;

template <class U>

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
- void append(U value) = добавляет элемент в список ПО ПОРЯДКУ
- U* toArray() = преобразует список в динамический массив и возвращает его
- void print() = вывод всех элементов списка
- bool has(U x) =  есть ли тут элемент с таким значением
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
		Inner() {}
		~Inner() {}
		Inner(U val) : value(), next(nullptr), previous(nullptr) {}
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
	bool has(U x);
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

	delete sacredfice;
	length--;
}

template <class U>
void List<U>::append(U x)
{
	cout << "append\n";
	length++;
	Inner* nova = new Inner(x);
	cout << x << endl;
	cout << nova->value << endl;
	cout << "ja\n";
	if (begin == nullptr)
	{
		begin = nova;
		end = nova;
		return;
	}
	Inner* current = begin;

	if (x < current->value)
	{
		nova->next = current;
		current->previous = nova;
		begin = nova;
	}
	else
	{
		bool found = false;
		while (current->next)
		{
			if (current->next->value >= nova->value)
			{
				found = true;
				break;
			}
			current = current->next;
		}
		if (found)
		{
			nova->next = current->next;
			current->next->previous = nova;
			current->next = nova;
			nova->previous = current;
		}
		else
		{
			end->next = nova;
			nova->previous = end;
			end = nova;
		}
	}
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
bool List<U>::has(U x)
{
	Inner* slot = begin;
	while (slot)
	{
		if (slot->value == x)
			return true;
		slot = slot->next;

	}
	return false;
}