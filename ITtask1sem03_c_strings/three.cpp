#include <iostream>
#include <string>
#include <math.h>

/*
Написать программу, которая преобразует введенное пользователем десятичное число
в число в указанной системе счисления (от 2 до 10).
*/

using namespace std;

string fromDecimalToCustom(int number, int base)
{
	/*
	Смысл такой: заводим пустую строчку под результат
	Далее последовательно делим искомое число на основание новой системы
	и прибавляем к строке остатки от деления.
	И далее нужно переврнуть полученную строку те завести новую с теми символами в обратном порядке.
	*/

	string result = "";
	while (number > 0)
	{
		// остаток от деления
		int modulo = number % base;
		// преобразовать int в char.
		char digit = (char)(modulo + (int)'0');
		result += digit;
		number /= base;
	}

	// теперь нужно перевернуть
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