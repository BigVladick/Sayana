#include <iostream>
#include <string>

using namespace std;

// Написать программу, которая проверяет, является ли введенная с клавиатуры строка двоичным числом


bool isBinary(string number) {

	// Если длина <=0 или первая цифра не 1, то не полходит
	if ( number.size() <= 0 || number[0] != '1')
		return false;

	// Далее должны быть только 1 и 0
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