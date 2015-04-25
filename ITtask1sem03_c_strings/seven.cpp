#include <iostream>
#include <string>

using namespace std;

/*
	¬ строке, состото€щей из из нулей и единиц найти наиболее длинную подстроку, 
	состо€щую из одних нулей (т.е. найти ее начало и длину).

	Ћирическое отступление: поиск подстроки в сроке очень крута€ и интересна€ задача.
	—уществует множество алгоритмов дл€ поиска. ћы же здесь будем использовать самый тупой.
	≈сли тебе интересно ты можешь их погуглить, например алгорит  нута ћориса ѕрата.
*/


/*
	Ќам нужно найти 2 параметра - начала подстроки и длину.
	я решил объединить это в один тип.
*/

struct Result {
	// не пугайс€, это просто инициализаци€ в кратком виде.
	Result(int a, int b) : begin(a), length(b) {}
	int begin;
	int length;
};

Result getSubstring(string text)
{

	/*
		«десь ничего интересного - все тупо просто(
		≈сли нолик, то длина текущей цепочки увеличиваетс€.
		≈сли нет, сравниваем с максимальной длинной. ≈сли она максимальна, то обновл€ем максимум
		и запоминаем результаты.
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