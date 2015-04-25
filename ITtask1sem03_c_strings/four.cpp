#include <iostream>
#include <string>
#include <math.h>

/*
Ќаписать программу, котора€ преобразует введенное пользователем дес€тичное число в шестнадцатеричное.
*/

using namespace std;

/*
я забыл сказать, что константы можно выносить в глобальные переменные.
Ќиже € вынес все символы из 16чной системы счислени€.
*/
const int base = 16;
const char hexDigits[base] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string fromDecimalToCustom(int number)
{
	/*
	јлгоритм аналогичен предыдущей задачи, за исключение того, как мы переводим int в char.
	«десь мы используем остаток от делени€ как индекс массива hexDigits.
	*/
	string result = "";
	while (number > 0)
	{
		// остаток от делени€
		int modulo = number % base;
		// преобразовать int в char.
		char digit = hexDigits[modulo];
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
	cout << "enter number\n";
	int number, base = 0;
	cin >> number;
	cout << fromDecimalToCustom(number) << endl;
	return 0;
}