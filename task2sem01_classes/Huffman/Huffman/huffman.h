#pragma once
#include "list.h"

class HuffmanElement
{
public:
	char symbol;
	int frequency;
	HuffmanElement(char s, int f) : symbol(s), frequency(f) {}
	friend bool operator==(HuffmanElement& a, HuffmanElement& b)
	{
		return a.symbol == b.symbol;
	}
	HuffmanElement() {}
	~HuffmanElement() {}
	HuffmanElement(const HuffmanElement& from)
	{
		symbol = from.symbol;
		frequency = from.frequency;
	}
	HuffmanElement& operator=(const HuffmanElement& from)
	{
		symbol = from.symbol;
		frequency = from.frequency;
		return *this;
	}
	friend ostream& operator<<(ostream& cout, HuffmanElement& time)
	{
		cout << time.symbol << " " << time.frequency;
		return cout;
	}
	friend bool operator<(HuffmanElement& a, HuffmanElement& b)
	{
		return a.frequency < b.frequency;
	}
	friend bool operator>(HuffmanElement& a, HuffmanElement& b)
	{
		return !(a < b || a == b);
	}
};

class Huffman
{
private:
	string data;
	List<HuffmanElement>* listTable;
	int sizeTable;
public:
	Huffman(string s) : data(s), listTable(new List<HuffmanElement>()), sizeTable(0) {}
	~Huffman()
	{
		delete listTable;
	}

	void buildTree()
	{
		cout << "building...\n";
		// пока хот€бы 2
		while (listTable->begin && listTable->begin->next)
		{
			// оба вне дерева => нужно объедить в дерево
			if (listTable->begin->isLast() && listTable->begin->next->isLast())
			{
				listTable->append(HuffmanElement('\0', 0));
				listTable->end->value.frequency = listTable->begin->value.frequency + listTable->begin->next->value.frequency;
				listTable->end->left = listTable->begin;
				listTable->end->right = listTable->begin->next;
				listTable->begin->father = listTable->end;
				listTable->begin->next->father = listTable->end;
				listTable->sort();
				listTable->print();
			}
			break; // 
			listTable->begin = listTable->begin->next;
		}
	}
	
	void buildTable()
	{
		int l = data.size();
		for (int i = 0; i < l; i++)
		{
			HuffmanElement current = HuffmanElement(data[i], 1);
			// найдем такой элемент (попробуем)
			List<HuffmanElement>::Inner* found = listTable->has(current);
			if (found != nullptr)
			{
				// нужно частоту inc
				found->value.frequency++;

			}
			else
			{
				sizeTable++;
				listTable->append(current);
			}
		}
		listTable->sort();
		listTable->print();
	}


};