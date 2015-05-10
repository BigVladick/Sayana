#include <iostream>
#include "huffman.h"

using namespace std;

// ���� ���������:
// http://habrahabr.ru/post/144200/

/*
	���� ����������:
	+ ����������� �������� ��� �����.
	- ������ �� �����
	- �������� � �����������

	
*/

int main()
{
	Huffman* huff = new Huffman("beep boop beer!");
	cout << huff->Encode() << endl; // ������������
	cout << huff->Decode() << endl; // �������������
	delete huff;
	return 0;
}