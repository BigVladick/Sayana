#include <iostream>
#include <string>
#include <math.h>

// �������� �����  � ����������

using namespace std;

int fromBinaryToDecimal(string binary)
{
	int result = 0;
	int length = binary.size();
	// ����� ��� ��� � ����� �� �������� ����� �� 2^n
	for (int i = length - 1; i >= 0; i--)
	{
		// ��� ��������� ����� ����� � int, ������� � �����
		// �� ������ ����������� ��������� cout
		int digit = (int)binary.at((binary.size() - 1 - i)) - (int)'0';
		// �������� ����� �� ������������� ������� ������
		result += pow(2, i) * digit;
	}
	return result;
}

int main()
{
	cout << "enter number\n";
	string number = "";
	// ������� ������ ����� ��-�������, ������� cin �� ���������, ������ ��� ������ - ��� ������.
	getline(cin, number);
	cout << fromBinaryToDecimal(number) << endl;
	return 0;
}