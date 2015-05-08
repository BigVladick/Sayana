#include "number.h"

bool operator == (Number& first, Number& second)
{
	return !(first < second) && !(second < first);
}

bool operator <= (Number& first, Number& second)
{
	return first == second || first < second;
}

Number* operator+(Number& f, Number& s)
{

	Number first = Number::max(f, s);
	Number second = Number::min(f, s);
	string result = "";
	int slot = 0;

	for (int i = 0; i < second.length; i++)
	{
		int a = first.value[first.length - i - 1] - '0';
		int b = second.value[second.length - i - 1] - '0';
		int num = (a + b + slot) % 10;
		slot = (a + b + slot) / 10;
		result += char(num + '0');
	}
	int index = second.length;
	while (index < first.length)
	{
		int digit = first.value[first.length - 1 - index++] - '0';
		int num = (digit + slot) % 10;
		slot = (digit + slot) / 10;
		result += char(num + '0');
	}
	if (slot)
		result += '1';

	Number* ans = new Number(result);
	ans->reverse();
	return ans;
}

Number* operator-(Number& f, Number& s)
{
	Number first = Number::max(f, s);
	Number second = Number::min(f, s);
	string result = "";
	int slot = 0;
	for (int i = 0; i < second.length; i++)
	{
		int a = first.value[first.length - i - 1] - '0';
		int b = second.value[second.length - i - 1] - '0';
		int num = (a - b - slot);
		num = num < 0 ? num + 10 : num;
		slot = (a - b - slot) < 0 ? 1 : 0;
		result += char(num + '0');
	}
	//cout << "result = " << result << endl;
	int index = second.length;
	while (index < first.length)
	{
		//cout << "while was\n";
		int digit = first.value[first.length - 1 - index++] - '0';
		int num = (digit - slot) % 10;
		num = num < 0 ? num + 10 : num;
		slot = (digit - slot) < 0 ? 1 : 0;
		//cout << "num = " << num << endl;
		result += char(num + '0');
	}
	//cout << "result = " << result << endl;
	Number* ans = new Number(result);
	ans->reverse();
	ans->reduce();
	return ans;
}

Number* operator/(Number& f, Number& s)
{
	//cout << "division\n";


	Number first = Number::max(f, s);
	Number second = Number::min(f, s);
	string result = "";

	Number *b = new Number(first.value);
	Number *c = new Number(second.value);
	//cout << "b = " << *b << endl;
	//cout << "c = " << *c << endl;

	// сначала опишу 1 итерацию
	int stop = 0;
	while (*c < *b)
	{
		// Шаг первый добавим нулей.
		//cout << "step one:\n";
		delete c;
		c = new Number(second.value);
		int diff = b->length - c->length;
		if (b->value[0] < c->value[0])
			diff--;
		c->addZeroes(diff);
		//cout << "b = " << *b << endl;
		//cout << "c = " << *c << endl;

		// Шаг 2 будет отнимать
		//cout << "step two:\n";
		int times = 0;
		while (*c <= *b)
		{
			b = *b - *c;
			times++;
		}
		//cout << "times = " << times << endl;
		result += char(times + '0');
		//cout << "b = " << *b << endl;
		//cout << "c = " << *c << endl;

		delete c;
		c = new Number(second.value);
		stop++;
	}
	Number* ans = new Number(result);
	delete b;
	delete c;
	return ans;
}

Number* operator*(Number& f, Number& s)
{
	Number* ans = new Number("");

	Number first = Number::max(f, s);
	Number second = Number::min(f, s);
	string result = "";

	// сначала реализуем умножение числа на 1 цифру
	for (int i = 0; i < second.length; i++)
	{
		result = "";
		int index = 0;
		int slot = 0;
		char be = second.value[second.length - i - 1];
		while (index < first.length)
		{
			int a = first.value[first.length - 1 - index++] - '0';
			int b = be - '0';

			int num = (a * b + slot) % 10;
			slot = (a * b + slot) / 10;
			result += char(num + '0');
		}
		if (slot)
			result += char(slot + '0');
		Number x = Number(result);
		x.reverse();
		x.addZeroes(i);
		ans = *ans + x;
	}

	return ans;
}

Number* operator^(Number& first, int deg)
{
	Number* ans = new Number("1");
	for (int i = 0; i < deg; i++)
	{
		ans = (*ans) * first;
	}
	return ans;
}

ostream& operator<<(ostream& cout, Number& pol)
{
	cout << pol.value;
	return cout;
}

bool operator < (Number& first, Number& second)
{
	if (first.length < second.length)
		return true;
	else if (first.length > second.length)
		return false;
	else
	{
		for (int i = 0; i < first.length; i++)
		{
			if (first.value[i] < second.value[i])
				return true;
			else if (first.value[i] > second.value[i])
				return false;
		}
	}
	return false;
}

Number& Number::operator=(const Number& from)
{
	length = int(from.length);
	value = string(from.value);
	return *this;
}

void Number::reverse()
{
	for (int i = 0; i < length / 2; i++)
	{
		char slot = value[i];
		value[i] = value[length - 1 - i];
		value[length - 1 - i] = slot;
	}
}

void Number::reduce()
{
	int amount = 0;
	for (int i = 0; i < length; i++)
		if (value[i] == '0')
			amount++;
		else
			break;
	if (amount == length)
	{
		value = "0";
		length = 1;
	}
	else
	{
		string newValue = "";
		for (int i = amount; i < length; i++)
			newValue += value[i];
		value = newValue;
		length = newValue.size();
	}
}

void Number::addZeroes(int x)
{
	int i = 0;
	while (i < x)
	{
		value += '0';
		length++;
		i++;
	}
}