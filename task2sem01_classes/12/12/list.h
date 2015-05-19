#pragma once
#include <iostream>

using namespace std;

template <class U>

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
- void append(U value) = ��������� ������� � ������ �� �������
- U* toArray() = ����������� ������ � ������������ ������ � ���������� ���
- void print() = ����� ���� ��������� ������
- bool has(U x) =  ���� �� ��� ������� � ����� ���������
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
		Inner() {}
		~Inner() {}
		Inner(U val) : value(), next(nullptr), previous(nullptr) {}
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