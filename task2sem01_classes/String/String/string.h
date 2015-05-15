#pragma once
#include <iostream>

using namespace std;

/*
	String - �����, ������� ����� ����� ������������ � ������� ������ ������������ string. 
	- friend ostream& operator<<(ostream& cout, String& time) - ����� ������� ����� �� �����
	- size_t strLen(const char *str) - ���������� � ������� ���������� ������� ����� ������
	- char* data = ������ ������
	- int length = �������� ������ ������� data
	- String(const char* text) = ������� ����� data � ��������� length
	- bool operator==(String& a, String& b) = ��������� �� ���������
	- bool operator!=(String& a, String& b) =  ��������� �� ����� ���������
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