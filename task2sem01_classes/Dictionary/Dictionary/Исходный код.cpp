#include <iostream>
#include "list.h"
#include "vector.h"
#include "avl.h"
#include "quickSort.h"
#include "word.h"
#include "dictionary.h"

#include <fstream>
#include <locale.h> 


using namespace std;

/*
	В файле используется кодировка ANSI
*/

/*
	CL06.	Реализовать структуры данных вектор (array), список (list), дерево (tree).
	Написать программу «Словарь» (с использованием указанных структур хранения данных), 
	которая позволяет считывать английские слова и их переводы из файла и по запросу пользователя
	выводить перевод английских слов, добавлять отсутствующие слова, выводить в алфавитном порядке переводы слов в файл
*/

/*
	План разработки:
	+ Шаблонный список
	+ Шаблонный вектор
	+ Шаблонное АВЛ дерево
	+ Класс слово с необходимыми операторами. Дописать конструктор копирования и оператор присваивания.
	+ Dictionary считывает и записывает список Words
	+ добавление уникального слова в список. Завершение задачи
	+ 4 одинаковых функции для List(+), Vector(+), AVL(+)  Описание!
	+ Шаблонный словарь

	Отладка:
	- Вектор падает
	- вынести класс Dictionary
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

	// Вектор сука падает

	// Тест словарь 
	
	Dictionary<Vector<Word>>* dic = new Dictionary<Vector<Word>>();
	dic->read();
	dic->print();
	dic->insert("success", "успех");
	cout << "\n\n";
	dic->print();
	dic->sort();
	dic->write();
	delete dic;
	
	
	

	// Тесты список Word
	/*
		Word* one = new Word("hello", "привет");
		Word* two = new Word("goodbay", "до свидания");
		Word* three = new Word("astral", "блуждать");
		Word arr2[] = { Word("zero", "ноль"), Word("year", "год") };
		List<Word>* list = new List<Word>();
		list->append(one);
		list->append(two);
		list->append(three);
		list->fromArray(arr2,2);
		Word* arr = list->toArray();
		delete list;
		cout << arr[0].english << " " << arr[1].english << " " << arr[2].english << " " << arr[3].english << " " << arr[4].english   <<  endl;
		Quicksort<Word>(0, 5 - 1, arr);
		cout << arr[0].english << " " << arr[1].english << " " << arr[2].english << " " << arr[3].english << " " << arr[4].english << endl;
		delete[] arr;
	*/

	// Тесты для списка
	/*
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
	*/

	// Тесты для вектора
	 /*
		Vector<int>* b = new  Vector<int>();
		b->append(new int(1));
		b->append(new int(2));
		b->append(new int(3));
		b->append(new int(4));
		b->append(new int(5));
		b->print();
		int* mas = b->toArray();
		cout << mas[0] << " " << mas[1] << " " << mas[2] << endl;
		delete b;
	 */	

	// Тесты для дерева
	/*
		AVLTree<int>* tree = new AVLTree<int>();
		tree->append(new int(1));
		tree->append(new int(2));
		tree->append(new int(3));
		//tree->print();
		int* mas = tree->toArray();
		cout << mas[0] << " " << mas[1] << " " << mas[2] << endl;
		//cout << *tree->root->key << " " << *tree->root->left->key << " " << *tree->root->right->key << endl;
		//cout << tree->has(5);
		delete[] mas;
		delete tree;
	*/
	


	return 0;
}