#include <iostream>
#include "list.h"
#include "quickSort.h"
#include "tree.h"
#include "huffman.h"

using namespace std;


// http://habrahabr.ru/post/144200/

/*
	План разработки:
	- реализовать алгоритм для строк.
	- считать из файла.
	- побитовая запись и чтение из файла.
	- заприватить поля
	- закомментить код

	- нужно маленькое дерево
	+ список работает с указателями
	- убрать нафиг указатели
*/

int main()
{
	// тесты для дерева
	/*
		Tree<int>* tree = new Tree<int>(0);
		tree->root->left = new Tree<int>::Node(1);
		tree->root->right = new Tree<int>::Node(2);
		tree->print();
		delete tree;
	*/


	Huffman* huff = new Huffman("beep boop beer!");
	huff->buildTable();
	huff->buildTree();
	delete huff;
	return 0;
}