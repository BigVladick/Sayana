#include "number.h"

ostream& operator<<(ostream& cout, Number& pol)
{
	cout << pol.value;
	return cout;
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
		int num = (a + b + slot) % Number::base;
		slot = (a + b + slot) / Number::base;
		result += char(num + '0');
	}
	int index = second.length;
	while (index < first.length)
	{
		int digit = first.value[first.length - 1 - index++] - '0';
		int num = (digit + slot) % Number::base;
		slot = (digit + slot) / Number::base;
		result += char(num + '0');
	}
	if (slot)
		result += '1';

	Number* ans = new Number(result);
	ans->reverse();
	return ans;
}

Number* operator*(Number& f, Number& s)
{
	Number* ans = new Number("");

	Number first = Number::max(f, s);
	Number second = Number::min(f, s);
	string result = "";

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

			int num = (a * b + slot) % Number::base;
			slot = (a * b + slot) / Number::base;
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