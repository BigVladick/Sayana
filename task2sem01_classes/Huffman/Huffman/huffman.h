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
		if (a.frequency == b.frequency)
			return a.symbol < b.symbol;
		return a.frequency < b.frequency;
	}
	friend bool operator<=(HuffmanElement& a, HuffmanElement& b)
	{
		return (a.frequency == b.frequency) || (a < b);
	}
	friend bool operator>(HuffmanElement& a, HuffmanElement& b)
	{
		if (a.frequency == b.frequency)
			return a.symbol > b.symbol;
		return a.frequency > b.frequency;
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
		/*
			√арантировано есть хот€бы 1 символ в строке
			ћы изменили функцию remove в списке так, что она не чистит пам€ть
			по завершении части алгоритма мы получим дерево.
		*/
		cout << "building...\n";

		// и нужно рассмотреть когда 1 символ
		if (listTable->begin->next == nullptr)
		{
			listTable->append(HuffmanElement('\0', 0));
			listTable->end->value.frequency = listTable->begin->value.frequency;
			listTable->end->left = listTable->begin;
			listTable->remove(listTable->begin);

		}
		// пока хот€бы 2
		while (listTable->begin && listTable->begin->next)
		{
			// объедин€ем 2 элемента из списка в один и добавл€ем его в список
				int sumFreq = listTable->begin->value.frequency + listTable->begin->next->value.frequency;
				List<HuffmanElement>::Inner* nova = listTable->insert(HuffmanElement('\0', sumFreq));
				//listTable->append(HuffmanElement('\0', 0));
				//listTable->end->value.frequency = listTable->begin->value.frequency + listTable->begin->next->value.frequency;

				nova->left = listTable->begin;
				nova->right = listTable->begin->next;


				listTable->remove(listTable->begin);
				listTable->remove(listTable->begin);

				//cout << "\n";
				//listTable->print(listTable->end);

				//listTable->sort();
				//listTable->print();
				//cout << "\n";
				//listTable->print(listTable->begin);
				//cout << "\n\n";
				//listTable->print(listTable->begin);
				//break;
		}

		// »меем дерево
		// нужно научить список печатать дерев
		

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
		List<HuffmanElement>::Inner* slot = listTable->begin;
		List<HuffmanElement>* sorted = new List<HuffmanElement>();
		while (slot)
		{
			sorted->insert(slot->value);
			slot = slot->next;
		}
		delete listTable;
		listTable = sorted;
		listTable->print();
	}


};