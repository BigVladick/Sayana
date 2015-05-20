#include "longNumber.h"

LongNumber::LongNumber(char* s)
{
	sign = true;
	length = strlen(s);
	value = new int[length]();
	for (int i = 0; i < length; i++)
		value[i] = s[i] - '0';
}

LongNumber::LongNumber(const LongNumber & object)
{
	//cout << "copying\n";
	sign = true;
	length = object.length;
	value = new int[length];
	for (int i = 0; i < length; i++)
		value[i] = object.value[i];
}

bool operator == (LongNumber& a, LongNumber& b)
{
	return (!(a < b) && !(b < a));
}

bool operator <= (LongNumber& a, LongNumber& b)
{
	return a == b || a < b;
}

LongNumber& LongNumber::addZeroes(int x) //+
{
	int* arr = new int[x + length];
	for (int i = 0; i < length; i++)
		arr[i] = value[i];

	for (int i = length; i < length + x; i++)
	{
		arr[i] = 0;
	}
		
	delete value;
	value = arr;
	length = length + x;
	return *this;
}

ostream& operator<<(ostream& cout, LongNumber& pol)
{
	for (int i = 0; i < pol.length; i++)
		cout << pol.value[i];
	return cout;
}

LongNumber& LongNumber::reverse()
{
	for (int i = 0; i < length / 2; i++)
	{
		int slot = value[i];
		value[i] = value[length - 1 - i];
		value[length - 1 - i] = slot;
	}
	return *this;
}

bool operator < (LongNumber& first, LongNumber& second)
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

bool operator > (LongNumber& first, LongNumber& second)
{
	return !(first < second) && !(first == second);
}

bool operator >= (LongNumber& first, LongNumber& second)
{
	return first > second || first == second;
}

LongNumber& LongNumber::reduce()
{
	int amount = 0;
	for (int i = 0; i < length; i++)
		if (value[i] == 0)
			amount++;
		else
			break;
	if (amount == length)
	{
		value = new int[1];
		value[0] = 0;
		length = 1;
	}
	else
	{
		length -= amount;
		int* arr = new int[length];
		string newValue = "";
		for (int i = 0; i < length; i++)
			arr[i] = value[i + amount];
		delete[] value;
		value = arr;
	}
	return *this;
}

LongNumber& operator+(LongNumber& f, LongNumber& s)
{
	if (f.sign && !s.sign)
	{
		return f - s;
	}
	LongNumber first = LongNumber::max(f, s);
	LongNumber second = LongNumber::min(f, s);
	string result = "";
	int slot = 0;

	for (int i = 0; i < second.length; i++)
	{
		int a = first.value[first.length - i - 1];
		int b = second.value[second.length - i - 1];
		int num = (a + b + slot) % 10;
		slot = (a + b + slot) / 10;
		result += char(num + '0');
	}
	int index = second.length;
	while (index < first.length)
	{
		int digit = first.value[first.length - 1 - index++];
		int num = (digit + slot) % 10;
		slot = (digit + slot) / 10;
		result += char(num + '0');
	}
	if (slot)
		result += '1';

	int l = result.size();
	char* arr = new char[l + 1]();
    for (int i = 0; i < l; i++)
		arr[i] = result[l - 1 - i];
	return * (new LongNumber(arr));
}

LongNumber LongNumber::max(LongNumber a, LongNumber b)
{
	return a < b ? b : a;
}
LongNumber LongNumber::min(LongNumber a, LongNumber b)
{
	return a < b ? a : b;
}

LongNumber& operator-(LongNumber& f, LongNumber& s)
{
	LongNumber first = LongNumber::max(f, s);
	LongNumber second = LongNumber::min(f, s);
	string result = "";
	int slot = 0;
	for (int i = 0; i < second.length; i++)
	{
		int a = first.value[first.length - i - 1];
		int b = second.value[second.length - i - 1];
		int num = (a - b - slot);
		num = num < 0 ? num + 10 : num;
		slot = (a - b - slot) < 0 ? 1 : 0;
		result += char(num + '0');
	}
	int index = second.length;
	while (index < first.length)
	{
		int digit = first.value[first.length - 1 - index++];
		int num = (digit - slot) % 10;
		num = num < 0 ? num + 10 : num;
		slot = (digit - slot) < 0 ? 1 : 0;
		result += char(num + '0');
	}

	int l = result.size();
	char* arr = new char[l + 1]();
	for (int i = 0; i < l; i++)
		arr[i] = result[l - 1 - i];
	return (new LongNumber(arr))->reduce();
}

LongNumber& operator*(LongNumber& f, LongNumber& s)
{
	LongNumber ans = LongNumber("0");

	LongNumber first = LongNumber::max(f, s);
	LongNumber second = LongNumber::min(f, s);
	string result = "";

	// сначала реализуем умножение числа на 1 цифру
	for (int i = 0; i < second.length; i++)
	{
		result = "";
		int index = 0;
		int slot = 0;
		int be = second.value[second.length - i - 1];
		while (index < first.length)
		{
			int a = first.value[first.length - 1 - index++];
			int b = be;

			int num = (a * b + slot) % 10;
			slot = (a * b + slot) / 10;
			result += char(num + '0');
		}
		if (slot)
			result += char(slot + '0');

		int l = result.size();
		char* arr = new char[l + 1]();
		for (int i = 0; i < l; i++)
			arr[i] = result[l - 1 - i];
		
		LongNumber x = LongNumber(arr).addZeroes(i);
		ans = ans + x;
	}
	
	return *(new LongNumber(ans));
}

LongNumber& operator*(LongNumber& f, int num)
{
	LongNumber* sl = new LongNumber(f);
	if (num == -1)
	{
		sl->sign = false;
	}
	return *sl;
}

LongNumber& operator/(LongNumber& f, LongNumber& s)
{
	LongNumber first = LongNumber::max(f, s);
	LongNumber second = LongNumber::min(f, s);
	LongNumber* b = new LongNumber(first);
	LongNumber* c = new LongNumber(second);

	string result = "";
	
	// сначала опишу 1 итерацию
	while (*c < *b)
	{
		
		// Шаг 1 добавим нулей.
		delete c;
		c = new LongNumber(second);
		int diff = b->length - c->length;
		if (b->value[0] < c->value[0])
			diff--;
		c->addZeroes(diff);

		// Шаг 2 будет отнимать
		int times = 0;
		while (*c <= *b)
		{
			LongNumber x = *b -*c;
			delete b;
			b = new LongNumber(x);
			times++;
		}
		result += char(times + '0');
		delete c;
		c = new  LongNumber(second);	
	}

	delete b;
	delete c;

	int l = result.size();
	char* arr = new char[l + 1]();
	for (int i = 0; i < l; i++)
		arr[i] = result[i];
	return *(new LongNumber(arr));	
}

LongNumber& operator^(LongNumber& first, int deg)
{
	LongNumber* ans = new LongNumber("1");
	for (int i = 0; i < deg; i++)
	{
		LongNumber x = *ans * first;
		delete ans;
		ans = new  LongNumber(x);
	}
	return *ans;
}

LongNumber::~LongNumber()
{
	//cout << "destr\n";
	delete[] value;
}

bool  LongNumber::operator!()
{
	return *this == LongNumber("0");
}