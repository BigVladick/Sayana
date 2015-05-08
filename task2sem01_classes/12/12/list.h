#pragma once
template <class U>

/*
Двусвязный шаблонный список
*/

class List
{

public:
	/*
	Inner - один элемент списка
	*/
	struct Inner
	{
		// указатель на его значение
		U* value;
		// указатель на следующий
		Inner* next;
		// указатель на предыдущий
		Inner* previous;
		Inner() {}
		~Inner()
		{
			delete value;
		}
		Inner(U* val) : value(val), next(nullptr), previous(nullptr) {}
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