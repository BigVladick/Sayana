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
	int z = 97;
	cout << (char)z << endl;

	return 0;

	string str = "hello";
	cout << str[1] << endl;

	return 0;
	char a = 'a';
	char ab[3] = { 'a', 'b', '\0' };

	String s1 = String("mama");
	String ok = String("ok");
	//s1 += ok;
	String* s2 = s1 + ok;
	cout << *s2 << endl;
	delete s2;

	/*
	int i = 0;
	String x = String();
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
	*/
}