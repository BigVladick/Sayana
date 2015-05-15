#include <iostream>
#include "string.h"

using namespace std;

/*
CL06.	����������� ����� ������� � ������������� ������������, ���������, ���������� ���������.
*/

/*
*���� ����������:
+ ���������� �� char*
+ �������� ��������� == � !=
+ R����������� (+)
+ ����������
+ �����������
*/

int main()
{
	// ��������
	String m = String("m");
	String n = String("n");

	// ���������
	cout << (m == n) << endl;
	cout << (m != n) << endl;
	
	// 2 ��������� ������������
	m += n;
	cout << m << endl;
	String* nm = (n + m);
	cout << *nm << endl;
	delete nm;
	
	// ���������
	cout << m[1] << endl;
	return 0;
}