#include <iostream>
#include "list.h"
#include "vector.h"
#include "avl.h"
#include "quickSort.h"
#include <math.h>
#include <string>

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
	+ Шаблонный вектор - не ок, нужно чтоб он памятью управлял
	+ Шаблонное АВЛ дерево
	- Класс слово с необходимыми операторами. Дописать конструктор копирования и оператор присваивания.
	- Шаблонный словарь
*/

string minString(string a, string b)
{
	return a.size() >= b.size() ? b : a;
}

class Word
{
public:
	string english;
	string russian;
	Word() {}
	Word(string e, string r) : english(e), russian(r) {}
	friend bool operator<(Word& a, Word& b)
	{
		string min = minString(a.english, b.english);
		
		int i = 0; 
		int lMin = min.size();
		while (i < lMin)
		{
			if (a.english[i] < b.english[i])
				return true;
			else if (a.english[i] > b.english[i])
				return false;
			i++;
		}
		return a.english.size() < b.english.size();
	}
	friend bool operator>(Word& a, Word& b)
	{
		return !(a < b) && a.english != b.english;
	}
};

int main()
{
	Word* one = new Word("hello", "привет");
	Word* two = new Word("goodbay", "до свидания");
	Word* three = new Word("astral", "блуждать");
	List<Word>* list = new List<Word>();
	list->append(one);
	list->append(two);
	list->append(three);
	Word* arr = list->toArray();
	delete list;
	cout << arr[0].english << " " << arr[1].english << " " << arr[2].english <<   endl;
	Quicksort<Word>(0, 3 - 1, arr);
	cout << arr[0].english << " " << arr[1].english << " " << arr[2].english << endl;
	delete[] arr;
	//cout << ((*one) < (*two)) << endl;

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
		//b->append(new int(3));
		cout << *b->at(0) << " " << *b->at(1) << " ";// << *b->at(2) << endl;
		delete b;
	*/	

	// Тесты для дерева
	/*
		AVLTree<int>* tree = new AVLTree<int>();
		tree->append(new int(1));
		tree->append(new int(2));
		tree->append(new int(3));
		cout << *tree->root->key << " " << *tree->root->left->key << " " << *tree->root->right->key << endl;
		delete tree;
	*/


	return 0;
}