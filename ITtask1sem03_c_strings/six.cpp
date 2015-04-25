#include <iostream>
#include <string>

/*
	Написать программу, переводящую вводимое с клавиатуры число, записанное римскими цифрами,
	в число, записанное арабскими цифрами.
*/

using namespace std;

/*
	Аналогично предыдущей задачи, заводим биекцию входных и выходных символов.
*/
const char romanDigits[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
const int arabicDigits[] = { 1, 5, 10, 50, 100, 500, 1000 };

/*
	Получить номер символа в массиве RomanDigits.
	Аналогично предыдущей задаче.
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
	Здесь ядро решения задачи.
	Смотри думай, как букто ты человек, как ты переводишь римские в арабские?
	VI = 6 потому что I справа, IV = 4 , потому что I слева.
	Окей, какой вывод? .. место для подумать.. 
	А вывод, Саяна, такой : Если справа от числа есть большее число, значит берем это число с минусом.
*/
bool isRightBigger(int position, string roman)
{
			   // номер символа в массиве romanDigits
	int index = getIndexChar(roman[position]);

	int length = roman.size();
	// Итак, смотреть символы справа, если находим то возвращаем true
	// До конца не доходим максимум отходим на 3 позиция вправо 
	for (int i = position + 1; i < length && i - position < 4; i++)
		if (index < getIndexChar(roman[i]))
			return true;
	return false;
}

int getArabic(string roman)
{
	int result = 0;
	int length = roman.size();

	// Здесь благодаря биекции, находим какой римский символ соотвествует арабскому.
	// и используем нашу функцию, которая смотрит если ли справа большее число.

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