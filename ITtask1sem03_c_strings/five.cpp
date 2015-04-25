#include <iostream>
#include <string>

using namespace std;
// ����� ���������� ��������
int const amountSymbols = 42;

/*
�������� � ���������� ����� ��������� � ������������������ ����� � ���� � �������
������ ����� (��������������� ��� �������� �������� � ��������� ����).

*/


/*
	������� �������������� ������ ������� ��������.
*/
void initInputs(char inputs[])
{
	int amountInputs = 0;
	// ������ ��������, ��� ����� �� ������ int ������������ � for ��� ������.
	// ���� ���� ������� � ������ ��� ����� �� A �� Z
	for (char i = 'A'; i <= 'Z'; i++)
	{
		inputs[amountInputs++] = i;
	}
	// ���� ���� ������� � ������ ��� ����� �� 1 �� 9
	for (char i = '1'; i <= '9'; i++)
	{
		inputs[amountInputs++] = i;
	}
	// ������� ��� ���������
	inputs[amountInputs++] = '0';
	inputs[amountInputs++] = '.';
	inputs[amountInputs++] = ',';
	inputs[amountInputs++] = ':';
	inputs[amountInputs++] = '?';
	inputs[amountInputs++] = '-';
	inputs[amountInputs++] = '/';
}

/*
������� �������������� ������ �������� ��������.
��������� �� ������ ��� �� ������� :(
*/
void initOutputs(string outputs[])
{
	int amountOutputs = 0;
	outputs[amountOutputs++] = ".-";
	outputs[amountOutputs++] = "-...";
	outputs[amountOutputs++] = "-.-.";
	outputs[amountOutputs++] = "-..";
	outputs[amountOutputs++] = ".";
	outputs[amountOutputs++] = "..-.";
	outputs[amountOutputs++] = "--.";
	outputs[amountOutputs++] = "....";
	outputs[amountOutputs++] = "..";
	outputs[amountOutputs++] = ".---";
	outputs[amountOutputs++] = "-.-";
	outputs[amountOutputs++] = ".-..";
	outputs[amountOutputs++] = "--";
	outputs[amountOutputs++] = "-.";
	outputs[amountOutputs++] = "---";
	outputs[amountOutputs++] = ".--.";
	outputs[amountOutputs++] = "--.-";
	outputs[amountOutputs++] = ".-.";
	outputs[amountOutputs++] = "...";
	outputs[amountOutputs++] = "-";
	outputs[amountOutputs++] = "..-";
	outputs[amountOutputs++] = "...-";
	outputs[amountOutputs++] = ".--";
	outputs[amountOutputs++] = "-..-";
	outputs[amountOutputs++] = "-.--";
	outputs[amountOutputs++] = "--..";
	outputs[amountOutputs++] = ".----";
	outputs[amountOutputs++] = "..---";
	outputs[amountOutputs++] = "�--";
	outputs[amountOutputs++] = "�.-";
	outputs[amountOutputs++] = "�..";
	outputs[amountOutputs++] = "-�.";
	outputs[amountOutputs++] = "--�";
	outputs[amountOutputs++] = "---..";
	outputs[amountOutputs++] = "----.";
	outputs[amountOutputs++] = "-----";
	outputs[amountOutputs++] = ".-.-.-";
	outputs[amountOutputs++] = "--..--";
	outputs[amountOutputs++] = "---�";
	outputs[amountOutputs++] = "..--..";
	outputs[amountOutputs++] = "-�.-";
	outputs[amountOutputs++] = "--..-.";
}

// ������� ��������� ������ �������� � ������ � ��������� ������� ������� � ������� (������) ����� -1
int getIndexSymbol(char symbols[], char a)
{
	for (int i = 0; i < amountSymbols; i++)
	{
		if (symbols[i] == a)
			return i;
	}
	return -1;
}

// ������� ��������������� ����� � ������� �������
// � ����������� � �����������, ��� �� ������ :)
char toUpper(char a)
{
	// ���� ������ - ������� �����, �� ��� �� � ����������, ����� ���������� � ��� ���� �������� ��������� � ������� �����
	return a >= 'A' && a <= 'Z' ? a : (char)((int)a + (int)('A' - 'a'));
}

// ������� ��������� ������ � �������� ��
string getMorze(string input)
{
	// ������� ������� ������� � �������� �������� � ������������������ ��.
	char* inputs = new char[amountSymbols];
	string* outputs = new string[amountSymbols];
	initInputs(inputs);
	initOutputs(outputs);


	int len = input.size();
	string result = "";
	for (int i = 0; i < len; i++)
	{
		/*
			������, � ��� � ����� ������� �������� �������� � ������� ��������. 
			�������, ��� ��� ������?)
			��, ��� �������� ������� ����������� �������� � ��� ���� ����������.
			�� �������� ������� �������(������) � ������� ������� �������� ��� 
			�� ����� � �������� � ������� �������� ��������.
		*/
		result += outputs[getIndexSymbol(inputs, toUpper(input[i]))];
	}

	// � ������� ������� ����� �� ������ ����, �� � � ���� :)
	// ������� ������ ������ �� �����.
	delete[] inputs;
	delete[] outputs;
	return result;
}

int main()
{
	cout << "enter text\n";
	string text = "";
	getline(cin, text);
	cout << getMorze(text) << endl;
	return 0;
}