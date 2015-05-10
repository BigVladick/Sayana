#pragma once
#include <iostream>
#include "quickSort.h"

using namespace std;

template <class U>

/*
	��������� ���������� ��� ��������
*/

/*
����� List - ���������� ������. ����������, ������ ���  2 ����� : next  � previous.
- Inner = ��������� ������������ ����� 1 ������� ������
- U value = �������� ����� ��������
- Inner* next = ��������� �� ��������� ������� ������
- Inner* previous = ��������� �� ���������� ������� ������
- Inner* begin = ������ ������
- Inner* end = ����� ������
- int length = ���-�� ��������� � ������
- void fromArray(U arr[], int length) = �������� ������ ���������
- void remove(Inner* sacredfice) = ������� ������� ������ �� �������
- void append(U value) = ��������� ������� � ����� ������
- U* toArray() = ����������� ������ � ������������ ������ � ���������� ���
- void print() = ����� ���� ��������� ������
- U* has(U x) =  ���� ������� � ����� ��������� ����, ������ ��������� �� ����  ����� nullptr
*/

class List
{

public:
	/*
	Inner - ���� ������� ������
	*/
	struct Inner
	{
		// ��������
		U value;
		// ��������� �� ���������
		Inner* next;
		// ��������� �� ����������
		Inner* previous;
		// ��������� �� �����
		Inner* left;
		// ��������� �� ������
		Inner* right;
		// ��������� �� ����
		Inner* father;
		Inner() {}
		~Inner() {}
		Inner(U val) : value(val), next(nullptr), previous(nullptr), left(nullptr), right(nullptr), father(nullptr) {}
		// �������� �� (���� ��� ��������)
		bool isLast() { return left == nullptr && right == nullptr; }
	};
	// ������ ������
	Inner* begin;
	// ����� ������
	Inner* end;
	// length - ����� ����� ������
	int length;
	List() : begin(nullptr), end(nullptr), length(0){}
	// ��������� ������ � ����� ������
	void fromArray(U arr[], int length);
	// ������� ������� �� ������
	void remove(Inner* sacredfice);
	// append - ��������� ������� � ����� ������
	void append(U value);
	U* toArray();
	~List();
	void print();
	// ���� �� ��� ������� � ����� ���������
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
	// ���� � ��������
	if (sacredfice->next && sacredfice->previous)
	{
		(sacredfice->previous)->next = sacredfice->next;
		(sacredfice->next)->previous = sacredfice->previous;
	}
	// ���� � ������
	else if (sacredfice == begin)
	{
		begin = sacredfice->next;
		if (sacredfice->next)
			(sacredfice->next)->previous = nullptr;
	}
	// ���� � �����
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

