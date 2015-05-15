#pragma once
#include <iostream>

using namespace std;

/*
	String - класс, который можно будет использовать в будущем вместо стандартного string. 
	- friend ostream& operator<<(ostream& cout, String& time) - самый обычный вывод на экран
	- size_t strLen(const char *str) - рекурсвино с помощью указателей считаем длину строки
	- char* data = хранит массив
	- int length = очевидно длинна массива data
	- String(const char* text) = создает новый data и обновляет length
	- bool operator==(String& a, String& b) = сравнение по символьно
	- bool operator!=(String& a, String& b) =  отрицание от этого сравнения
*/

class String
{
	friend bool operator==(String& a, String& b);
	friend bool operator!=(String& a, String& b);
	friend String& operator+(String& one, String& two);
	friend ostream& operator<<(ostream& cout, String& time);
	
private:
	size_t strLen(const char *str);
	char* data;
	int length;
public:
	String& operator=(const String& from);
	String() : data(nullptr), length(0) {}
	~String();
	String(const char* text);
	
};