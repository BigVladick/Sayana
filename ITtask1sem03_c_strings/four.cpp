#include <iostream>
#include <string>
#include <math.h>

/*
�������� ���������, ������� ����������� ��������� ������������� ���������� ����� � �����������������.
*/

using namespace std;

/*
� ����� �������, ��� ��������� ����� �������� � ���������� ����������.
���� � ����� ��� ������� �� 16���� ������� ���������.
*/
const int base = 16;
const char hexDigits[base] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string fromDecimalToCustom(int number)
{
	/*
	�������� ���������� ���������� ������, �� ���������� ����, ��� �� ��������� int � char.
	����� �� ���������� ������� �� ������� ��� ������ ������� hexDigits.
	*/
	string result = "";
	while (number > 0)
	{
		// ������� �� �������
		int modulo = number % base;
		// ������������� int � char.
		char digit = hexDigits[modulo];
		result += digit;
		number /= base;
	}

	// ������ ����� �����������
	string newResult = "";
	int len = result.size();

	for (int i = len - 1; i >= 0; i--)
	{
		newResult += result[i];
	}
	return newResult;
}

int main()
{
	cout << "enter number\n";
	int number, base = 0;
	cin >> number;
	cout << fromDecimalToCustom(number) << endl;
	return 0;
}