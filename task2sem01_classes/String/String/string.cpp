#include "string.h"

size_t String::strLen(const char *str)
{
	return (*str) ? strLen(++str) + 1 : 0;
}

void String::strCpy(char* in_str, char* src_str)
{
	for (int i = 0; i < strLen(in_str); i++)
		in_str[i] = src_str[i];
}

int String::size()
{
	return length;
}

String::String(char* _str)
{
	int l = strLen(_str);
	data = new char[l + 1];
	length = l;
	strCpy(data, _str);
}

ostream& operator<<(ostream& cout, String& time)
{
	return cout << time.data;
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
	delete[] data;
}

String* operator+(String& one, String& two)
{
	String* result = new  String();
	result->length = one.length + two.length;
	result->data = new char[result->length + 1]();
	int k = 0;
	for (k; k < one.length; k++)
	{
		result->data[k] = one.data[k];
	}
	for (int i = k; i - k < two.length; i++)
	{
		result->data[i] = two.data[i - k];
	}
	return result;
}

String& String::operator+= (const String& from)
{
	int sz = strLen(this->data) + strLen(from.data);

	char* ts = new char[sz + 1];

	for (int i = 0; i < strLen(this->data); i++)
		ts[i] = this->data[i];
	for (int ii = strLen(this->data), j = 0; ii <= sz; ii++, j++)
		ts[ii] = from.data[j];

	delete this->data;
	this->data = ts;
	return *this;
}

const char& String::operator[](int i) const
{
	//std::cerr << "Index out of range. \n";
	return (i >= 0 && i < strLen(this->data)) ? this->data[i] : 0;
}