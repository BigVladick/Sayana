#include <iostream>
#include <string>

/*
	�������� ���������, ����������� �������� � ���������� �����, ���������� �������� �������,
	� �����, ���������� ��������� �������.
*/

using namespace std;

/*
	���������� ���������� ������, ������� ������� ������� � �������� ��������.
*/
const char romanDigits[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
const int arabicDigits[] = { 1, 5, 10, 50, 100, 500, 1000 };

/*
	�������� ����� ������� � ������� RomanDigits.
	���������� ���������� ������.
*/

int getIndexChar(char a)
{
	int length = strlen(romanDigits);
	for (int i = 0; i < length; i++)
		if (romanDigits[i] == a)
			return i;
	return -1;
}

/*
	����� ���� ������� ������.
	������ �����, ��� ����� �� �������, ��� �� ���������� ������� � ��������?
	VI = 6 ������ ��� I ������, IV = 4 , ������ ��� I �����.
	����, ����� �����? .. ����� ��� ��������.. 
	� �����, �����, ����� : ���� ������ �� ����� ���� ������� �����, ������ ����� ��� ����� � �������.
*/
bool isRightBigger(int position, string roman)
{
			   // ����� ������� � ������� romanDigits
	int index = getIndexChar(roman[position]);

	int length = roman.size();
	// ����, �������� ������� ������, ���� ������� �� ���������� true
	// �� ����� �� ������� �������� ������� �� 3 ������� ������ 
	for (int i = position + 1; i < length && i - position < 4; i++)
		if (index < getIndexChar(roman[i]))
			return true;
	return false;
}

int getArabic(string roman)
{
	int result = 0;
	int length = roman.size();

	// ����� ��������� �������, ������� ����� ������� ������ ������������ ���������.
	// � ���������� ���� �������, ������� ������� ���� �� ������ ������� �����.

	for (int i = 0; i < length; i++)
	{
		if (isRightBigger(i, roman))
		{
			result += arabicDigits[getIndexChar(roman[i])] * -1;
		}
		else
		{
			result += arabicDigits[getIndexChar(roman[i])];
		}
	}

	return result;
}

int main()
{
	cout << "enter text\n";
	string text = "";
	getline(cin, text);
	cout << getArabic(text) << endl;
	return 0;
}