#include <iostream>
#include "hashTable.h"

using namespace std;

int size = 1000;

unsigned int HashFAQ6(const char* str)
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

int main()
{
	char mas[100] = { '\0' };
	cin >> mas;
	cout << HashFAQ6(mas) << endl;

	return 0;
}