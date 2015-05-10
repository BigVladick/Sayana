#pragma once
#include <iostream>

using namespace std;

/*
	HuffmanElement - обертка вокруг символа и частоты его встречаемости
	- операторы <, >, <= , >= используются при упорядоченном добавление List<U>.insert(U x)
	- == используется при создании списка этого типа, чтобы одинаковых символов не встречалось
*/

class HuffmanElement
{
public:
	char symbol;
	int frequency;
	HuffmanElement(char s, int f) : symbol(s), frequency(f) {}

	HuffmanElement() {}
	~HuffmanElement() {}
	HuffmanElement(const HuffmanElement& from);
	HuffmanElement& operator=(const HuffmanElement& from);
	friend ostream& operator<<(ostream& cout, HuffmanElement& time);
	friend bool operator==(HuffmanElement& a, HuffmanElement& b);
	friend bool operator<(HuffmanElement& a, HuffmanElement& b);
	friend bool operator>(HuffmanElement& a, HuffmanElement& b);
	friend bool operator<=(HuffmanElement& a, HuffmanElement& b);
	friend bool operator>=(HuffmanElement& a, HuffmanElement& b);
};
