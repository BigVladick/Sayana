#include "hashTable.h"

HashTable::HashTable()
{
	for (int i = 0; i < size; i++)
		list[i] = nullptr;
}