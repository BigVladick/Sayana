#pragma once
#include "list.h"
#include "huffmanElement.h"
#include <string>

/*
	Code - оболочка вокруг символа и его кода
*/
struct Code
{
	char symbol;
	string code;
	Code(): symbol('\0'), code("") {}
	Code(char s, string c) : symbol(s), code(c) {}
};

/*
	Huffman - наш главный класс может кодировать и декодировать
	- string input = для хранения исходной строки
	- string encoded = закодированная строка
	- List<HuffmanElement>* listTable = вот эта штука не обычно. Сначала это список всех символов и их частот встречаемости, а потом
									    он плавно превращается в дерево.
	- Code* codeTable = список кодов для всех символов из input
	- int sizeTable = количество уникальных символов в input
	- void buildTable()= строит список из символом и их частот
	- void buildTree() = строит дерево, на основе списка символов и их частот
	- string Encode() = кодирует исходную строку согласно дереву
	- string Decode() = декодирует исходную строку согласно дереву
*/
class Huffman
{
private:
	string input;
	string encoded;
	List<HuffmanElement>* listTable;
	Code* codeTable;
	int sizeTable;
	void buildTree();
	void buildTable();
public:
	Huffman(string s);
	~Huffman();
	
	string Encode();
	string Decode();
};