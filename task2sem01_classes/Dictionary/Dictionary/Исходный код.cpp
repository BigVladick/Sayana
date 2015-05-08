#include <iostream>
#include "list.h"
#include "vector.h"

using namespace std;

/*
	CL06.	Реализовать структуры данных вектор (array), список (list), дерево (tree).
	Написать программу «Словарь» (с использованием указанных структур хранения данных), 
	которая позволяет считывать английские слова и их переводы из файла и по запросу пользователя
	выводить перевод английских слов, добавлять отсутствующие слова, выводить в алфавитном порядке переводы слов в файл
*/

/*
	План разработки:
	+ Шаблонный список
	+ Шаблонный вектор
	- Шаблонное АВЛ дерево
	- Шаблонный словарь
*/

class AVLTree
{


public:

	// http://habrahabr.ru/post/150732/
	struct Node // структура для представления узлов дерева
	{
		int key;
		unsigned char height;
		Node* left;
		Node* right;
		Node(int k) { key = k; left = right = 0; height = 1; }
	};
	Node* root;
	AVLTree() : root(nullptr) {}
	void append(int x)
	{
		root = insert(root, x);
	}
	void remove(int x)
	{
		root = remove(root, x);
	}

	
	
	private:
		unsigned char height(Node* p)
		{
			return p ? p->height : 0;
		}
		int bfactor(Node* p)
		{
			return height(p->right) - height(p->left);
		}
		void fixheight(Node* p)
		{
			unsigned char hl = height(p->left);
			unsigned char hr = height(p->right);
			p->height = (hl>hr ? hl : hr) + 1;
		}
		Node* rotateright(Node* p) // правый поворот вокруг p
		{
			Node* q = p->left;
			p->left = q->right;
			q->right = p;
			fixheight(p);
			fixheight(q);
			return q;
		}

		Node* rotateleft(Node* q) // левый поворот вокруг q
		{
			Node* p = q->right;
			q->right = p->left;
			p->left = q;
			fixheight(q);
			fixheight(p);
			return p;
		}

		Node* balance(Node* p) // балансировка узла p
		{
			fixheight(p);
			if (bfactor(p) == 2)
			{
				if (bfactor(p->right) < 0)
					p->right = rotateright(p->right);
				return rotateleft(p);
			}
			if (bfactor(p) == -2)
			{
				if (bfactor(p->left) > 0)
					p->left = rotateleft(p->left);
				return rotateright(p);
			}
			return p; // балансировка не нужна
		}
		Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
		{
			return p->left ? findmin(p->left) : p;
		}

		Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
		{
			if (p->left == 0)
				return p->right;
			p->left = removemin(p->left);
			return balance(p);
		}

		Node* insert(Node* p, int k) // вставка ключа k в дерево с корнем p
		{
			if (!p) return new Node(k);
			if (k<p->key)
				p->left = insert(p->left, k);
			else
				p->right = insert(p->right, k);
			return balance(p);
		}

		Node* remove(Node* p, int k) // удаление ключа k из дерева p
		{
			if (!p) return 0;
			if (k < p->key)
				p->left = remove(p->left, k);
			else if (k > p->key)
				p->right = remove(p->right, k);
			else //  k == p->key 
			{
				Node* q = p->left;
				Node* r = p->right;
				delete p;
				if (!r) return q;
				Node* min = findmin(r);
				min->right = removemin(r);
				min->left = q;
				return balance(min);
			}
			return balance(p);
		}


};

int main()
{
	// Тесты для списка
	/*
		List<int>* a = new List<int>();
		a->append(new int(1));
		a->append(new int(2));
		int *arr = new int[2]();
		arr[0] = 3;
		arr[1] = 4;
		a->fromArray(arr,2);
		cout << *(a->begin->value) << " " << *(a->begin->next->value) << " " << *(a->begin->next->next->value) << " "
				<< *(a->begin->next->next->next->value)  << endl;
		delete arr;
		arr = a->toArray();
		for (int i = 0; i < 4; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete arr;
		delete a;
	*/

	// Тесты для вектора
		/*
		Vector<int>* b = new  Vector<int>();
		b->append(1);
		b->append(2);
		b->append(3);
		cout << b->at(0) << " " << b->at(1) << " " <<  b->at(2) << endl;
		delete b;
		*/
	AVLTree* tree = new AVLTree();
	tree->append(4);
	tree->append(3);
	tree->append(5);
	cout << tree->root->key << " " << tree->root->left->key << " " << tree->root->right->key << endl;


	return 0;
}