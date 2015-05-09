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