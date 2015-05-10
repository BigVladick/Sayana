#pragma once
#include "list.h"
#include "huffmanElement.h"
#include <string>

/*
	Code - �������� ������ ������� � ��� ����
*/
struct Code
{
	char symbol;
	string code;
	Code(): symbol('\0'), code("") {}
	Code(char s, string c) : symbol(s), code(c) {}
};

/*
	Huffman - ��� ������� ����� ����� ���������� � ������������
	- string input = ��� �������� �������� ������
	- string encoded = �������������� ������
	- List<HuffmanElement>* listTable = ��� ��� ����� �� ������. ������� ��� ������ ���� �������� � �� ������ �������������, � �����
									    �� ������ ������������ � ������.
	- Code* codeTable = ������ ����� ��� ���� �������� �� input
	- int sizeTable = ���������� ���������� �������� � input
	- void buildTable()= ������ ������ �� �������� � �� ������
	- void buildTree() = ������ ������, �� ������ ������ �������� � �� ������
	- string Encode() = �������� �������� ������ �������� ������
	- string Decode() = ���������� �������� ������ �������� ������
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