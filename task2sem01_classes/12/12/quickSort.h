#pragma once
/*
Шаблонная быстрая сортировка
*/

template <class T>
void change(int first, int second, T mas[]){
	T tmp = mas[first];
	mas[first] = mas[second];
	mas[second] = tmp;
}

template <class T>
void Quicksort(int begin, int end, T s[]){
	T middle = s[(begin + end) / 2];
	int i = begin;
	int j = end;

	while (i < j){
		while (s[i] < middle)
			++i;
		while (s[j] > middle)
			--j;
		if (i <= j)
		{
			if (i < j)
				change(i, j, s);
			++i;
			--j;
		}
	}

	if (i < end)
		Quicksort(i, end, s);
	if (j > begin)
		Quicksort(begin, j, s);
}