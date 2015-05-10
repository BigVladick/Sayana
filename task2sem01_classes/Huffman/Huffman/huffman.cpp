#include "huffman.h"

Huffman::Huffman(string s) : input(s), encoded(""), listTable(new List<HuffmanElement>()), sizeTable(0), codeTable(nullptr)
{
	buildTable();
	buildTree();
}


Huffman::~Huffman()
{
	listTable->postfixFree(listTable->begin);
}

void Huffman::buildTree()
{
	/*
	������������� ���� ������ 1 ������ � ������
	�� �������� ������� remove � ������ ���, ��� ��� �� ������ ������
	�� ���������� ����� ��������� �� ������� ������.
	*/
	cout << "building tree...\n";

	// � ����� ����������� ����� 1 ������
	if (listTable->begin->next == nullptr)
	{
		listTable->append(HuffmanElement('\0', 0));
		listTable->end->value.frequency = listTable->begin->value.frequency;
		listTable->end->left = listTable->begin;
		listTable->remove(listTable->begin);

	}
	// ���� ������ 2
	int stop = 0;
	while (listTable->begin && listTable->begin->next)
	{
		// ���������� 2 �������� �� ������ � ���� � ��������� ��� � ������
		int sumFreq = listTable->begin->value.frequency + listTable->begin->next->value.frequency;
		List<HuffmanElement>::Inner* nova = listTable->insert(HuffmanElement('\0', sumFreq));

		nova->left = listTable->begin;
		nova->right = listTable->begin->next;


		listTable->remove(listTable->begin);
		listTable->remove(listTable->begin);

		stop++;
	}
}

void Huffman::buildTable()
{
	cout << "building table...\n";
	int l = input.size();
	for (int i = 0; i < l; i++)
	{
		HuffmanElement current = HuffmanElement(input[i], 1);
		// ������ ����� ������� (���������)
		List<HuffmanElement>::Inner* found = listTable->has(current);
		if (found != nullptr)
		{
			// ����� ������� inc
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
		//cout << slot->value << endl;
		slot = slot->next;
	}
	delete listTable;
	listTable = sorted;

	// �������� ������� ��������
	codeTable = new Code[sizeTable]();
	slot = listTable->begin;
	int index = 0;
	while (slot)
	{
		codeTable[index++].symbol = slot->value.symbol;
		slot = slot->next;
	}
}

string Huffman::Encode()
{
	for (int i = 0; i < sizeTable; i++)
	{
		string res = "";
		listTable->getCode(listTable->begin, codeTable[i].symbol, "", res);
		codeTable[i].code = string(res);
	}

	int l = input.size();
	for (int i = 0; i < l; i++)
	{
		int index = 0;
		for (int j = 0; j < sizeTable; j++)
		{
			if (codeTable[j].symbol == input[i])
			{
				index = j;
				break;
			}
		}
		encoded += codeTable[index].code;
	}
	return encoded;
}

string Huffman::Decode()
{
	int l = encoded.size();
	string decoded = "";
	List<HuffmanElement>::Inner* slot = listTable->begin;
	for (int i = 0; i < l; i++)
	{
		if (encoded[i] == '0')
		{
			slot = slot->left;
			if (slot->value.symbol != '\0')
			{
				decoded += slot->value.symbol;
				slot = listTable->begin;
			}
		}
		if (encoded[i] == '1')
		{
			slot = slot->right;
			if (slot->value.symbol != '\0')
			{
				decoded += slot->value.symbol;
				slot = listTable->begin;
			}
		}
	}
	return decoded;
}