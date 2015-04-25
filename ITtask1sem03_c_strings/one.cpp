#include <iostream>
#include <string>

using namespace std;

// �������� ���������, ������� ���������, �������� �� ��������� � ���������� ������ �������� ������


bool isBinary(string number) {

	// ���� ����� <=0 ��� ������ ����� �� 1, �� �� ��������
	if ( number.size() <= 0 || number[0] != '1')
		return false;

	// ����� ������ ���� ������ 1 � 0
	for (int i = 1; i < number.size(); i++)
	{
		if (number[i] != '1' && number[i] != '0')
			return false;
	}
}


int main()
{

	string *input = new string();
	cout << "input string\n";
	getline(cin, *input);
	cout << *input << endl;
	cout << (isBinary(*input)? "yes" : "no") << endl;
	delete(input);
	return 0;
}