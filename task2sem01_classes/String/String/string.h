#pragma once
#include <iostream>

using namespace std;

/*
*	 ����� String - ����� ����������� ���������� std::string
*  friend bool operator==(String& a, String& b) = ������������ ���������
*  friend bool operator!=(String& a, String& b) = ��������� �� ��������� ����
*  friend String* operator+(String& one, String& two) = �������� ����� ������������ ������ = ����� 2�
*  friend ostream& operator<<(ostream& cout, String& time) = �����. �� ����� �������� � ������))
*  static size_t strLen(const char *str) = ����� ����� ������
*  static void strCpy(char* in_str, char* src_str) = �������� ������ ������ � ������
*  char* data = ������ char
*  int length = ����� �������� ������ ��. � ������� � ������� strLen.
*  String& operator+=(const String& from) = ��������� � ������������ �����
*  const char& operator[](int) const = �������� []. �������� ��� ������ �����������. ������ ��������� ��������� � ���))
*  String(const char* text) = ������������� data �� ������� ������
*  ~String() = ������� ��� ������
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