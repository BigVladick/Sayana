#include "string.h"

size_t String::strLen(const char *str)
{
	return (*str) ? strLen(++str) + 1 : 0;
}

String::String(const char* text)
{
	int l = strLen(text);
	data = new char[l]();
	length = l;
	for (int i = 0; i < length; i++)
	{
		data[i] = text[i];
	}
}

ostream& operator<<(ostream& cout, String& time)
{
	for (int i = 0; i < time.length; i++)
	{
		cout << time.data[i];
	}
	return cout;
}

bool operator==(String& a, String& b)
{
	if (a.length != b.length)
		return false;
	for (int i = 0; i < a.length; i++)
		if (a.data[i] != b.data[i])
			return false;
	return true;
}
bool operator!=(String& a, String& b)
{
	return !(a == b);
}

String::~String()
{
	//cout << "destr for adress:" << &data[0] << endl;
	//delete[] data;
}

String& operator+(String& one, String& two)
{
	// создали
	String result = String();
	result.length = one.length + two.length;
	result.data = new char[result.length]();
	
	// скопировали
	int k = 0;
	for (k; k < one.length; k++)
	{
		result.data[k] = one.data[k];
	}
	for (int i = k; i - k < two.length; i++)
	{
		result.data[i] = two.data[i-k];
	}
	return String("hui");
}


String& String::operator=(const String& from)
{
	
	length = from.length;
	cout << "l = " << from.length << endl;
	data = new char[length]();
	for (int i = 0; i < from.length; i++)
	{
		data[i] = from.data[i];
	}
	
	return *this;
}
