#include <iostream>
#include <string>
#include <math.h>
#include "date.h"

/*
CL04.	����������� ����� <<����, � ������������� ������������� �� ������ ��������� �������, 
		���������� ������� ����� ������ � ����, ����������, ����������.
*/
using namespace std;

int main()
{
	// ������ ��/��/����

		Date birthday = Date(26, 11, 1996);
		Date today = Date("06.05.2015");
		Date tomorrow = birthday++;
		Date yesterday = birthday--;
		cout << "Sayana's birthday:" << birthday << endl;
		cout << "Day after Sayana's birthday:" << tomorrow << endl;
		cout << "Day before Sayana's birthday:" << yesterday << endl;
		cout << "Sayana's age:" << Date::getDiff(birthday, today) << endl;
		system("pause");
		return 0;

}