#include "word.h"

string minString(string a, string b)
{
	return a.size() >= b.size() ? b : a;
}

bool operator<(Word& a, Word& b)
{
	string min = minString(a.english, b.english);

	int i = 0;
	int lMin = min.size();
	while (i < lMin)
	{
		if (a.english[i] < b.english[i])
			return true;
		else if (a.english[i] > b.english[i])
			return false;
		i++;
	}
	return a.english.size() < b.english.size();
}

bool operator>(Word& a, Word& b)
{
	return !(a < b) && a.english != b.english;
}

bool operator>=(Word& a, Word& b)
{
	return a > b || a == b;
}

Word::Word(const Word& from)
{
	english = from.english;
	russian = from.russian;
}
// Оператор присваивания
Word& Word::operator=(const Word& from)
{
	english = from.english;
	russian = from.russian;
	return *this;
}

ostream& operator<<(ostream& cout, Word& time)
{
	cout << time.english << " - " << time.russian;
	return cout;
}

bool operator==(Word& a, Word& b)
{
	return a.english == b.english && a.russian == b.russian;
}

int Word::getHash(int size)
{
	int  l1 = russian.size();
	int  l2 = english.size();
	char* str = new char[l1+l2]();
	int i = 0;
	for (i; i < l1; i++)
		str[i] = russian[i];
	for (i; i - l1 < l2; i++)
		str[i] = english[i - l1];

	int res = hashFAQ6(str, size);
	delete[] str;
	return res;
}

int Word::hashFAQ6(const char* str, int size)
{
	unsigned int hash = 0;

	for (; *str; str++)
	{
		hash += (unsigned char)(*str);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash % size;

}