#include <iostream>
#include "list.h"
#include "vector.h"
#include "avl.h"
#include "quickSort.h"
#include "word.h"
#include "dictionary.h"
#include "hashTable.h"


#include <locale.h> 


using namespace std;

/*
	В файле используется кодировка ANSI
*/

/*
	CL07.	Реализовать структуры данных вектор (array), список (list), двоичное дерево (binary tree), хэш-таблица (hash table).
	Написать программу «Словарь» (с использованием указанных структур хранения данных), которая позволяет считывать
	английские слова и их переводы из файла и по запросу пользователя выводить перевод английских слов.
	Словарь для тестирования dictionary.txt (каб. 4205).
*/

/*
	План разработки:
	+ Шаблонный список
	+ Шаблонный вектор
	+ Шаблонное АВЛ дерево
	+ Класс Word с необходимыми операторами. Дописать конструктор копирования и оператор присваивания.
	+ Dictionary считывает и записывает список Words
	+ 4 одинаковых функции для List(+), Vector(+), AVL(+)
	+ Шаблонный словарь
	+ Комментарии
	+ Написать шаблонную HT и проверить
	+ Проверить ее в словаре
	- Обновить комментарии

*/


int indexOf(string s, char a, int num)
{
	int l = s.size();
	int k = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == a)
		{
			if (k++ == num)
				return i;
		}
	}
	return -1;
}

int main()
{
	// необходимо для вывода русских букв
	setlocale(LC_ALL, "RUS");

	/*
	Word a = Word("vlad", "Влад");
	Word b = Word("cat", "Кирилл");
	cout << a.getHash(1000) << endl;
	cout << b.getHash(1000) << endl;
	// играемся с HT.
	HashTable<Word> ht = HashTable<Word>();
	ht.append(a);
	ht.append(a);
	ht.append(b);
	ht.append(b);
	ht.print();
	*/

	Dictionary<HashTable<Word>>* dic = new Dictionary<HashTable<Word>>();
	dic->read(); // считали 
	dic->print(); // вывели
	dic->insert("success", "успех"); // попытка добавить
	cout << "\n";
	dic->print(); // еще раз вывели
	//dic->sort(); // Нужна только для вектора
	dic->write(); // записали в файл
	delete dic;

	return 0;
}