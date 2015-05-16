#include <fstream>
#include "quickSort.h"

template <class U>


/*
	Dictionary - ���� ����� ������. ���� ������ � ���, ����� �� ����� �������� ������ �������� ������ - ������, ������ ��� ������.
	��� ����� ������������ �������. �� ����� ��������� ������������ ������, ����� ���������� ������� ��� 3� ���������:
	- print();
	- append(U x);
	- fromArray(U* x, int len);
	- U* toArray();
	- bool has(U x);

	���������� ������� �������� Dictionary:
	- U* storage = �������� ��� �������� ������ (���, ������ ��� ������)
	- int amount = ���������� ���� � �������
	- void sort() = �������� ������� � ���������� ������� ����������.
	- void print() = ������� ��� ����� �� �����
	- void read() = ��������� �� ����� data.txt
	- void write() = ���������� � ���� data.txt
	- void insert(string e, string r) = ��������� ����� �����
*/

class Dictionary
{
private:
	U* storage;
	int amount;

public:
	Dictionary() : storage(new U()), amount(0) {}
	~Dictionary();
	//void sort();
	void print();
	void read();
	// ���������� � ����
	void write();
	void insert(string e, string r);
};


template <class U>
Dictionary<U>::~Dictionary()
{
	delete storage;
}

/*
template <class U>
void Dictionary<U>::sort()
{
	Word* arr = storage->toArray();
	delete storage;
	Quicksort<Word>(0, amount - 1, arr);
	storage = new U();
	storage->fromArray(arr, amount);
	delete[] arr;
}
*/

template <class U>
void Dictionary<U>::print()
{
	storage->print();
}

template <class U>
void Dictionary<U>::read()
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
			storage->append(Word(en, ru));
		}
	}
	read.close();
}

// ���������� � ����
template <class U>
void Dictionary<U>::write()
{

	ofstream outFile;
	outFile.open("data.txt", ios::out);
	Word* arr = storage->toArray();
	Quicksort<Word>(0, amount - 1, arr);
	for (int i = 0; i < amount; i++)
	{
		outFile << arr[i].english << " - " << arr[i].russian << "\n";
	}
	delete[] arr;
	outFile.close();
}

template <class U>
void Dictionary<U>::insert(string e, string r)
{
	Word nova = Word(e, r);
	if (!storage->has(nova))
	{
		storage->append(nova);
		amount++;
	}
}