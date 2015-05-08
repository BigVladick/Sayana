#pragma once
#include <iostream>
#include <math.h>

using namespace std;

// �������� ������� n-�� ���������. ������� �� ���������� ������
int indexOf(string s, char a, int num);

// String -> int
int toInt(string s);

class TimeStamp
{
private:
	// �������� �����
	friend ostream& operator<<(ostream& cout, TimeStamp& time);
	int hour;
	int minute;
	int second;
public:
	int static getDiff(TimeStamp a, TimeStamp b);
	TimeStamp(int h, int m, int s) : hour(h), minute(m), second(s) {}
	TimeStamp(string input);
	TimeStamp();
	~TimeStamp();
};

