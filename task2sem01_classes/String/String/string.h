#pragma once
#include <iostream>

using namespace std;

/*
*	  ласс String - очень сокращенна€ реализаци€ std::string
*  friend bool operator==(String& a, String& b) = посимвольное сравнение
*  friend bool operator!=(String& a, String& b) = отрицание от оператора выше
*  friend String* operator+(String& one, String& two) = получить новую динамическую строку = сумме 2х
*  friend ostream& operator<<(ostream& cout, String& time) = вывод. Ќе сразу приходит в голову))
*  static size_t strLen(const char *str) = найти длину строки
*  static void strCpy(char* in_str, char* src_str) = копирует вторую строку в первую
*  char* data = массив char
*  int length = можно принципе убрать ее. » считать с помощью strLen.
*  String& operator+=(const String& from) = прибавить к существующей новую
*  const char& operator[](int) const = оператор []. ѕосмотри как просто реализуетс€. “олько синтаксис запомнить и все))
*  String(const char* text) = иницилизируем data от входной строки
*  ~String() = удал€ем наш массив
*/

class String
{
	friend bool operator==(String& a, String& b);
	friend bool operator!=(String& a, String& b);
	friend String* operator+(String& one, String& two);
	friend ostream& operator<<(ostream& cout, String& time);
	

private:
	static size_t strLen(const char *str);
	static void strCpy(char* in_str, char* src_str);
	char* data;
	int length;
public:
	int size();
	String& operator+=(const String& from);
	String() : data(nullptr), length(0) {}
	~String();
	String(char* _str);
	const char& operator[](int) const;

};