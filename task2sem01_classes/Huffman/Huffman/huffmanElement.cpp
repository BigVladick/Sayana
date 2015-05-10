#include "huffmanElement.h"


bool operator==(HuffmanElement& a, HuffmanElement& b)
{
	return a.symbol == b.symbol;
}

HuffmanElement::HuffmanElement(const HuffmanElement& from)
{
	symbol = from.symbol;
	frequency = from.frequency;
}
HuffmanElement& HuffmanElement::operator=(const HuffmanElement& from)
{
	symbol = from.symbol;
	frequency = from.frequency;
	return *this;
}
ostream& operator<<(ostream& cout, HuffmanElement& time)
{
	cout << time.symbol << " " << time.frequency;
	return cout;
}
bool operator<(HuffmanElement& a, HuffmanElement& b)
{
	if (a.frequency == b.frequency)
		return a.symbol < b.symbol;
	return a.frequency < b.frequency;
}
bool operator<=(HuffmanElement& a, HuffmanElement& b)
{
	return (a.frequency == b.frequency) || (a < b);
}
bool operator>=(HuffmanElement& a, HuffmanElement& b)
{
	return (a.frequency == b.frequency) || (a > b);
}
bool operator>(HuffmanElement& a, HuffmanElement& b)
{
	if (a.frequency == b.frequency)
		return a.symbol > b.symbol;
	return a.frequency > b.frequency;
}
