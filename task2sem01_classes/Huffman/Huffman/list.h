#pragma once
#include <iostream>

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
- void remove(Inner* sacredfice) = удаляет элемент списка по адрессу
- void append(U value) = добавляет элемент в конец списка
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
		Inner() {}
		~Inner() {}
		Inner(U val) : value(val), next(nullptr), previous(nullptr), left(nullptr), right(nullptr) {}
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
	// удаляет элемент по адресу
	void remove(Inner* sacredfice);
	// append - добавляет элемент в конец списка
	void append(U value);
	~List();
	void print();
	// есть ли тут элемент с таким значением
	Inner* has(U x);
	Inner* insert(U x)
	{
		Inner* nova = new Inner(x);
		if (begin == nullptr)
		{
			begin = nova;
			end = nova;
			return nova;
		}
		Inner* current = begin;
		// добавляем в начало
		if (x < current->value)
		{
			nova->next = current;
			current->previous = nova;
			begin = nova;
			if (current->next == end)
			{
				end = current;
			}
		}
		else
		{
			bool found = false;
			while (current->next)
			{
				if (current->next->value > nova->value)
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
		return nova;
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

