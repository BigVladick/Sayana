#include <iostream>
#include <string>
#include <math.h>

// двоичное число  в десятичное

using namespace std;

int fromBinaryToDecimal(string binary)
{
	int result = 0;
	int length = binary.size();
	// здесь все как в жизни мы умножаем цифры на 2^n
	for (int i = length - 1; i >= 0; i--)
	{
		// это выражение берет цифры в int, начиная с конца
		// ты можешь посмотореть поставивь cout
		int digit = (int)binary.at((binary.size() - 1 - i)) - (int)'0';
		// умножаем цифру на соотвестующую степень двойки
		result += pow(2, i) * digit;
	}
	return result;
}

int main()
{
	cout << "enter number\n";
	string number = "";
	// считать строку нужно по-особому, простой cin не сработает, помому что строка - это массив.
	getline(cin, number);
	cout << fromBinaryToDecimal(number) << endl;
	return 0;
}