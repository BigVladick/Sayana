#include <iostream>
#include "list.h"
#include "vector.h"

using namespace std;

/*
	CL06.	����������� ��������� ������ ������ (array), ������ (list), ������ (tree).
	�������� ��������� ��������� (� �������������� ��������� �������� �������� ������), 
	������� ��������� ��������� ���������� ����� � �� �������� �� ����� � �� ������� ������������
	�������� ������� ���������� ����, ��������� ������������� �����, �������� � ���������� ������� �������� ���� � ����
*/

/*
	���� ����������:
	+ ��������� ������
	+ ��������� ������
	- ��������� ��� ������
	- ��������� �������
*/

class AVLTree
{


public:

	// http://habrahabr.ru/post/150732/
	struct Node // ��������� ��� ������������� ����� ������
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
		Node* rotateright(Node* p) // ������ ������� ������ p
		{
			Node* q = p->left;
			p->left = q->right;
			q->right = p;
			fixheight(p);
			fixheight(q);
			return q;
		}

		Node* rotateleft(Node* q) // ����� ������� ������ q
		{
			Node* p = q->right;
			q->right = p->left;
			p->left = q;
			fixheight(q);
			fixheight(p);
			return p;
		}

		Node* balance(Node* p) // ������������ ���� p
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
			return p; // ������������ �� �����
		}
		Node* findmin(Node* p) // ����� ���� � ����������� ������ � ������ p 
		{
			return p->left ? findmin(p->left) : p;
		}

		Node* removemin(Node* p) // �������� ���� � ����������� ������ �� ������ p
		{
			if (p->left == 0)
				return p->right;
			p->left = removemin(p->left);
			return balance(p);
		}

		Node* insert(Node* p, int k) // ������� ����� k � ������ � ������ p
		{
			if (!p) return new Node(k);
			if (k<p->key)
				p->left = insert(p->left, k);
			else
				p->right = insert(p->right, k);
			return balance(p);
		}

		Node* remove(Node* p, int k) // �������� ����� k �� ������ p
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
	// ����� ��� ������
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

	// ����� ��� �������
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