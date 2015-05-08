#include <iostream>
#include "list.h"

using namespace std;

/*
	CL06.	Реализовать структуры данных вектор (array), список (list), дерево (tree).
	Написать программу «Словарь» (с использованием указанных структур хранения данных), 
	которая позволяет считывать английские слова и их переводы из файла и по запросу пользователя
	выводить перевод английских слов, добавлять отсутствующие слова, выводить в алфавитном порядке переводы слов в файл
*/

/*
	План разработки:
	+ Шаблонный список
	- Шаблонный вектор
	- Шаблонное АВЛ дерево
	- Шаблонный словарь
*/

int main()
{
	// Тесты для списка
	List<int>* a = new List<int>();
	a->append(new int(1));
	a->append(new int(2));
	int *arr = new int[2]();
	arr[0] = 3;
	arr[1] = 4;
	a->fromArray(arr,2);
	cout << *(a->begin->value) << " " << *(a->begin->next->value) << " " << *(a->begin->next->next->value) << " "
			<< *(a->begin->next->next->next->value)  << endl;
	delete arr;
	arr = a->toArray();
	for (int i = 0; i < 4; i++)
		cout << arr[i] << " ";
	cout << endl;
	delete arr;
	delete a;

	return 0;
}