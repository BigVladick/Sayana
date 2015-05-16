#pragma once

#include <iostream>
using namespace std;

class HashTable
{
	struct Node
	{
		string value;
		Node* next;
		Node* previous;
		Node(string v) : value(v) {}
	};


private:
	static const int size = 1000;
	Node* list[size];
public:
	HashTable();

};