#include <iostream>
#include "huffman.h"

using namespace std;

// суть алгоритма:
// http://habrahabr.ru/post/144200/

/*
	План разработки:
	+ реализовать алгоритм для строк.
	- читать из файла
	- работать с бинарниками

	
*/

int main()
{
	Huffman* huff = new Huffman("beep boop beer!");
	cout << huff->Encode() << endl; // закодировали
	cout << huff->Decode() << endl; // раскодировали
	delete huff;
	return 0;
}