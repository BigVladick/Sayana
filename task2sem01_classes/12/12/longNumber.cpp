#include "longNumber.h"

LongNumber::LongNumber(char* s)
{
	length = strlen(s);
	value = new int[length]();
	for (int i = 0; i < length; i++)
		value[i] = s[i] - '0';
}

LongNumber::LongNumber(int* s, int l)
{
	length = l;
	value = new int[length];
	for (int i = 0; i < length; i++)
		value[i] = s[i];
}

LongNumber::~LongNumber()
{
	delete[] value;
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

bool operator == (LongNumber& a, LongNumber& b)
{
	return ( !(a < b) && !(b < a) );
}

bool operator <= (LongNumber& a, LongNumber& b)
{
	return a == b || a < b;
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
	return LongNumber(arr);
}

LongNumber& LongNumber::max(LongNumber& a, LongNumber& b)
{
	return a < b ? b : a;
}
LongNumber& LongNumber::min(LongNumber& a, LongNumber& b)
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
	LongNumber x = LongNumber(arr);
	x.reduce();
	return x;
}

LongNumber& operator*(LongNumber& f, LongNumber& s)
{

	LongNumber ans = LongNumber("0");

	LongNumber first = LongNumber::max(f, s);
	LongNumber second = LongNumber::min(f, s);
	string result = "";

	// ������� ��������� ��������� ����� �� 1 �����
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
	return ans;
}

LongNumber& operator/(LongNumber& f, LongNumber& s)
{
	LongNumber first = LongNumber::max(f, s);
	LongNumber second = LongNumber::min(f, s);
	
	//LongNumber  *b = new LongNumber(first.value, first.length);
	//LongNumber  *c = new LongNumber(second.value, second.length);
	
	
	string result = "";
	/*

	// ������� ����� 1 ��������
	while (c < b)
	{
		
		// ��� ������ ������� �����.
		delete c;
		c = new LongNumber(second.value, second.length);
		
		int diff = b->length - c->length;
		if (b->value[0] < c->value[0])
			diff--;
		c->addZeroes(diff);
		cout << "here ok\n";
		break;
		// ��� 2 ����� ��������
		int times = 0;
		while (c <= b)
		{
			*b = *b - *c;
			times++;
		}
		result += char(times + '0');
		delete c;
		c = new LongNumber(second.value, second.length);
	}
	int l = result.size();
	char* arr = new char[l+1];
	for (int i = 0; i < l; i++)
		arr[i] = result[i];
	delete b;
	delete c;
	*/
	return LongNumber("42");
}