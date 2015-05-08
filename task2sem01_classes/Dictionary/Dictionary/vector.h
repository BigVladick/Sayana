/*
	Шаблонный класс вектор:
	- space = общее количество ячеек в массиве
	- length = кол-во занятый ячеек массива
	- arr = сам динамический массив 
	- append(U x) = добавить в конец массива
	- at(int index) = обратиться по индексу
*/

template <class U>
class Vector
{
private:
	int space;
	U* arr;
public:
	int length;
	Vector() : space(1), arr(new U[space]()), length(0) {}
	~Vector();
	void append(U x);
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
	// место кончилось
	if (length + 1 > space)
	{
		U* slot = new U[space * 2]();
		for (int i = 0; i < length; i++)
		{
			slot[i] = U(arr[i]);
		}
		delete arr;
		arr = slot;
		space *= 2;
	}
	arr[length++] = int(x);
}

template <class U>
U Vector<U>::at(int index)
{
	return arr[index];
}