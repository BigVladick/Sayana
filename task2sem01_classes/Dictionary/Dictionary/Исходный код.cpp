#include <iostream>
#include "list.h"
#include "vector.h"
#include "avl.h"
#include "quickSort.h"
#include "word.h"

#include <fstream>
#include <locale.h> 


using namespace std;

/*
	� ����� ������������ ��������� ANSI
*/

/*
	CL06.	����������� ��������� ������ ������ (array), ������ (list), ������ (tree).
	�������� ��������� ��������� (� �������������� ��������� �������� �������� ������), 
	������� ��������� ��������� ���������� ����� � �� �������� �� ����� � �� ������� ������������
	�������� ������� ���������� ����, ��������� ������������� �����, �������� � ���������� ������� �������� ���� � ����
*/

/*
	���� ����������:
	+ ��������� ������
	+ ��������� ������
	+ ��������� ��� ������
	+ ����� ����� � ������������ �����������. �������� ����������� ����������� � �������� ������������.
	+ Dictionary ��������� � ���������� ������ Words
	- ��������� �������
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

class Dictionary
{
private:
	List<Word>* storage;
	int amount;
public:
	Dictionary() : storage(new List<Word>()), amount(0) {}
	~Dictionary()
	{
		delete storage;
	}
	void print()
	{
		storage->print();
	}
	// ������ � ���������
	void read()
	{
		// �������
		ifstream read;
		read.open("data.txt", ios::in);
		
		if (read.is_open())
		{
			string str = "";
			while (getline(read, str))
			{
				amount++;
				string ru = "";
				string en = "";
				int l = str.size();
				int splitter = indexOf(str, '-', 0);
				for (int i = 0; i < splitter - 1; i++)
				{
					en += str[i];
				}
				for (int i = splitter + 2; i < l; i++)
					ru += str[i];
				storage->append(new Word(en, ru));
			}
		}
		read.close();

		// �������������
		Word* arr = storage->toArray();
		delete storage;
		Quicksort<Word>(0, amount - 1, arr);
		storage = new List<Word>();
		storage->fromArray(arr, amount);
		delete[] arr;

	}
	// ���������� � ����
	void write()
	{
		ofstream outFile;
		outFile.open("data.txt", ios::out);
		Word* arr = storage->toArray();
		for (int i = 0; i < amount; i++)
		{
			outFile << arr[i].english << " - " << arr[i].russian << "\n";
		}
		outFile.close();
	}
};

int main()
{
	// ���������� ��� ������ ������� ����
	setlocale(LC_ALL, "RUS");

	Dictionary* dic = new Dictionary();
	dic->read();
	dic->print();
	//dic->write();
	delete dic;

	// ����� ������ Word
	/*
		Word* one = new Word("hello", "������");
		Word* two = new Word("goodbay", "�� ��������");
		Word* three = new Word("astral", "��������");
		Word arr2[] = { Word("zero", "����"), Word("year", "���") };
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

	// ����� ��� ������
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

	// ����� ��� �������
	/*
		Vector<int>* b = new  Vector<int>();
		b->append(new int(1));
		b->append(new int(2));
		b->append(new int(3));
		cout << *b->at(0) << " " << *b->at(1) << " ";// << *b->at(2) << endl;
		delete b;
	*/	

	// ����� ��� ������
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