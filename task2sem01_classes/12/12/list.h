#pragma once
template <class U>

/*
���������� ��������� ������
*/

class List
{

public:
	/*
	Inner - ���� ������� ������
	*/
	struct Inner
	{
		// ��������� �� ��� ��������
		U* value;
		// ��������� �� ���������
		Inner* next;
		// ��������� �� ����������
		Inner* previous;
		Inner() {}
		~Inner()
		{
			delete value;
		}
		Inner(U* val) : value(val), next(nullptr), previous(nullptr) {}
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
	void append(U* value);
	U* toArray();
	~List();
};

template <class U>
void List<U>::fromArray(U arr[], int length)
{
	for (int i = 0; i < length; i++)
		append(new U(arr[i]));
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
void List<U>::append(U* value)
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
		arr[index++] = *slot->value;
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