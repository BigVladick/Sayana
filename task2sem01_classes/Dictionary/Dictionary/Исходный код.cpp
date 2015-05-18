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
	� ����� ������������ ��������� ANSI
*/

/*
	CL07.	����������� ��������� ������ ������ (array), ������ (list), �������� ������ (binary tree), ���-������� (hash table).
	�������� ��������� ��������� (� �������������� ��������� �������� �������� ������), ������� ��������� ���������
	���������� ����� � �� �������� �� ����� � �� ������� ������������ �������� ������� ���������� ����.
	������� ��� ������������ dictionary.txt (���. 4205).
*/

/*
	���� ����������:
	+ ��������� ������
	+ ��������� ������
	+ ��������� ��� ������
	+ ����� Word � ������������ �����������. �������� ����������� ����������� � �������� ������������.
	+ Dictionary ��������� � ���������� ������ Words
	+ 4 ���������� ������� ��� List(+), Vector(+), AVL(+)
	+ ��������� �������
	+ �����������
	+ �������� ��������� HT � ���������
	+ ��������� �� � �������
	- �������� �����������

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
	// ���������� ��� ������ ������� ����
	setlocale(LC_ALL, "RUS");

	/*
	Word a = Word("vlad", "����");
	Word b = Word("cat", "������");
	cout << a.getHash(1000) << endl;
	cout << b.getHash(1000) << endl;
	// �������� � HT.
	HashTable<Word> ht = HashTable<Word>();
	ht.append(a);
	ht.append(a);
	ht.append(b);
	ht.append(b);
	ht.print();
	*/

	Dictionary<HashTable<Word>>* dic = new Dictionary<HashTable<Word>>();
	dic->read(); // ������� 
	dic->print(); // ������
	dic->insert("success", "�����"); // ������� ��������
	cout << "\n";
	dic->print(); // ��� ��� ������
	//dic->sort(); // ����� ������ ��� �������
	dic->write(); // �������� � ����
	delete dic;

	return 0;
}