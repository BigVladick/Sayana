#include <iostream>
#include <string>

using namespace std;

/*
	� ������, ����������� �� �� ����� � ������ ����� �������� ������� ���������, 
	��������� �� ����� ����� (�.�. ����� �� ������ � �����).

	���������� �����������: ����� ��������� � ����� ����� ������ � ���������� ������.
	���������� ��������� ���������� ��� ������. �� �� ����� ����� ������������ ����� �����.
	���� ���� ��������� �� ������ �� ���������, �������� ������� ����� ������ �����.
*/


/*
	��� ����� ����� 2 ��������� - ������ ��������� � �����.
	� ����� ���������� ��� � ���� ���.
*/

struct Result {
	// �� �������, ��� ������ ������������� � ������� ����.
	Result(int a, int b) : begin(a), length(b) {}
	int begin;
	int length;
};

Result getSubstring(string text)
{

	/*
		����� ������ ����������� - ��� ���� ������(
		���� �����, �� ����� ������� ������� �������������.
		���� ���, ���������� � ������������ �������. ���� ��� �����������, �� ��������� ��������
		� ���������� ����������.
	*/

	int length = text.size();

	int bestLength = 0;
	int bestStart = -1;

	int currentLength = 0;
	int currentStart = -1;

	for (int i = 0; i < length; i++)
	{
		if (text[i] == '0')
		{
			if (currentStart == -1)
				currentStart = i;
			currentLength++;

			if (currentLength > bestLength)
			{
				bestLength = currentLength;
				bestStart = currentStart;
			}
		}
		else
		{
			currentLength = 0;
			currentStart = -1;
		}
	}
	return Result(bestStart, bestLength);
}


int main()
{
	string text = "";
	Result res = getSubstring("101000100");
	cout << res.begin << " " << res.length << endl;
	return 0;
}