#include <iostream>
#include <string>
#include <math.h>

/*
�������� ���������, ������� ����������� ��������� ������������� ���������� �����
� ����� � ��������� ������� ��������� (�� 2 �� 10).
*/

using namespace std;

string fromDecimalToCustom(int number, int base)
{
	/*
	����� �����: ������� ������ ������� ��� ���������
	����� ��������������� ����� ������� ����� �� ��������� ����� �������
	� ���������� � ������ ������� �� �������.
	� ����� ����� ���������� ���������� ������ �� ������� ����� � ���� ��������� � �������� �������.
	*/

	string result = "";
	while (number > 0)
	{
		// ������� �� �������
		int modulo = number % base;
		// ������������� int � char.
		char digit = (char)(modulo + (int)'0');
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
	cout << "enter number and base\n";
	int number, base = 0;
	cin >> number >> base;
	cout << fromDecimalToCustom(number, base) << endl;
	return 0;
}