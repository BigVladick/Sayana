#pragma once
#include "tree.h"
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
	void sortTable()
	{
		HuffmanElement* arr = listTable->toArray();
		delete listTable;
		Quicksort<HuffmanElement>(0, sizeTable - 1, arr);
		listTable = new List<HuffmanElement>();
		listTable->fromArray(arr, sizeTable);
		delete[] arr;
	}
public:
	Huffman(string s) : data(s), listTable(new List<HuffmanElement>()), sizeTable(0) {}
	~Huffman()
	{
		delete listTable;
	}
	void buildTree()
	{
		// На основе списка из символов с частотами
		// Построили список символов с частотами как узлов дерева
		List<Node<HuffmanElement>>* list = new List<Node<HuffmanElement>>();
		List<HuffmanElement>::Inner* slot = listTable->begin;
		while (slot)
		{
			list->append(new Node<HuffmanElement>(slot->value));
			slot = slot->next;
		}
		cout << "all list before:\n";
		list->print();
		cout << endl << endl;
		Tree<HuffmanElement>* tree = new Tree<HuffmanElement>();
		//tree->print();
		// пока есть хотябы 1 элемент
		int stop = 0;
		while (list->begin && stop < 2)
		{
			// Случай если есть 2
			if (list->begin && list->begin->next)
			{
				
				if (list->begin->value->value->symbol != '\0' && list->begin->next->value->value->symbol != '\0')
				{ 
					cout << "here\n";
					Node<HuffmanElement>* father = new Node<HuffmanElement>(new HuffmanElement('\0', 0));
					//tree->root = new Node<HuffmanElement>(new HuffmanElement('\0', 0));
					father->left = list->begin->value;
					father->right = list->begin->next->value;
					list->remove(list->begin);
					list->remove(list->begin);
					father->value->frequency = father->left->value->frequency + father->right->value->frequency;
					list->append(father);
					list->sort();
					if (stop == 1)
					list->print();
					//tree->print();
				}
				else
				{

				}
			}
			// Случай если есть только 1
			else
			{

			}
			//list->remove(list->begin);
			stop++;
		}
	}
	void buildTable()
	{
		int l = data.size();
		for (int i = 0; i < l; i++)
		{
			HuffmanElement* current = new HuffmanElement(data[i], 1);
			// найдем такой элемент (попробуем)
			List<HuffmanElement>::Inner * found = listTable->has(current);
			if (found != nullptr)
			{
				// нужно частоту inc
				found->value->frequency++;

			}
			else
			{
				sizeTable++;
				listTable->append(current);
			}
		}
		sortTable();
		//listTable->print();
	}


};