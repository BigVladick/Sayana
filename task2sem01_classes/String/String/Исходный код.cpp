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
- R����������� (+)
- ���������� ����������� � �������� ������������
- �������� ������������ �� char*
- ����������
*/

int main()
{
	String m = String("m");
	String n = String("n");
	String slot = String();
	slot = m + n;
	//String mn = m + n;
	return 0;
}