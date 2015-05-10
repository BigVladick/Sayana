#pragma once
#include <iostream>

using namespace std;

template <class U>

/*
	List -  Измененем специально для Хаффмана. Сначала он список, а потом он легко превращается в дерево
	- Inner = структура представляет собой 1 элемент списка-дерева
			- Inner* next = указатель на следующий элемент списка
			- Inner* previous = указатель на предыдущий элемент списка
			- Inner* left = указатель на левого потомка
			- Inner* right = указатель на правого потомка
	- Inner* begin = начало списка
	- Inner* end = конец списка
	- void remove(Inner* sacredfice) - удаляет по адресу, но при этом память не чистится. Потому что этот элемент уходит из списка, но 
									 не из дерева
	- void append(U value) = добавляет элемент в конец списка
	- ~List() = чистит как список
	- void print() = печает как список
	- U* has(U x) =  если элемент с таким значением есть, вернет указатель на него  иначе nullptr
	- void postfixFree(Inner* x) = чистит память как дерево, где x - корень
	- void getCode(Inner* x, char symbol, string code, string& res) = По построенному дереву получает код символа, ответ будет записан в 
																	  в переменную res благодаря ссылке
	- Inner* insert(U x) = добавит по порядку, возвращает новый элемент
	- void print(Inner* x) = печатает как дерево, где x - корень дерева


*/

class List
{

public:
	struct Inner
	{
		U value;
		Inner* next;
		Inner* previous;
		Inner* left;
		Inner* right;
		Inner() {}
		~Inner() {}
		Inner(U val) : value(val), next(nullptr), previous(nullptr), left(nullptr), right(nullptr) {}	
	};

	Inner* begin;
	Inner* end;
	int length;
	List() : begin(nullptr), end(nullptr), length(0){}
	void remove(Inner* sacredfice);
	void append(U value);
	~List();
	void print();
	Inner* has(U x);
	void postfixFree(Inner* x);
	void getCode(Inner* x, char symbol, string code, string& res);
	Inner* insert(U x);
	void print(Inner* x);
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

template <class U>
void List<U>::postfixFree(Inner* x)
{

	x ? postfixFree(x->left) : 0;
	x ? postfixFree(x->right) : 0;
	if (x)
		delete x;
}

template <class U>
void List<U>::getCode(Inner* x, char symbol, string code, string& res)
{
	x ? getCode(x->left, symbol, code + "0", res) : 0;
	if (x && x->value.symbol == symbol)
	{
		res = string(code);
	}

	x ? getCode(x->right, symbol, code + "1", res) : 0;
}

template <class U>
typename List<U>::Inner* List<U>::insert(U x)
{
	length++;
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
		//cout << "here from x = " << x << endl;
		nova->next = current;
		current->previous = nova;
		begin = nova;
	}
	else
	{
		bool found = false;
		while (current->next)
		{
			if (current->next->value >= nova->value) // > было
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

template <class U>
void List<U>::print(Inner* x)
{
	x ? print(x->left) : 0;
	if (x)
		cout << x->value << endl;
	x ? print(x->right) : 0;

}

