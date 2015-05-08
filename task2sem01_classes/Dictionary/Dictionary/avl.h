/*
	����� ��� - ������
	- �������� http://habrahabr.ru/post/150732/
	- ������� ������ ��� ������
	- root = ������� ������
	- amount = ���������� ��������� � ������
	- append(U* x) - �������� ������� � ������
	- remove(U* x) - ������� ������� �� ������

*/


template <class U>
class AVLTree
{

public:
	// http://habrahabr.ru/post/150732/
	struct Node // ��������� ��� ������������� ����� ������
	{
		U* key;
		unsigned char height;
		Node* left;
		Node* right;
		Node(U* k) { key = k; left = right = 0; height = 1; }
		~Node()
		{
			delete key;
		}
	};
	Node* root;
	int amount;
	AVLTree() : root(nullptr), amount(0) {}
	~AVLTree();
	void append(U* x);
	void remove(U* x);

private:
	unsigned char height(Node* p);
	int bfactor(Node* p);
	void fixheight(Node* p);
	Node* rotateright(Node* p); // ������ ������� ������ p
	Node* rotateleft(Node* q); // ����� ������� ������ q
	Node* balance(Node* p); // ������������ ���� p
	Node* findmin(Node* p); // ����� ���� � ����������� ������ � ������ p 
	Node* removemin(Node* p); // �������� ���� � ����������� ������ �� ������ p
	Node* insert(Node* p, U* k); // ������� ����� k � ������ � ������ p
	Node* remove(Node* p, U* k); // �������� ����� k �� ������ p
	void postfixFree(Node* x);
};

template <class U>
AVLTree<U>::~AVLTree()
{
	// ����� ����������� �������
	postfixFree(root);
}

template <class U>
void AVLTree<U>::append(U* x)
{
	amount++;
	root = insert(root, x);
}

template <class U>
void AVLTree<U>::remove(U* x)
{
	amount--;
	root = remove(root, x);
}

template <class U>
unsigned char AVLTree<U>::height(Node* p)
{
	return p ? p->height : 0;
}

template <class U>
int AVLTree<U>::bfactor(Node* p)
{
	return height(p->right) - height(p->left);
}

template <class U>
void AVLTree<U>::fixheight(Node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::rotateright(Node* p) // ������ ������� ������ p
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::rotateleft(Node* q) // ����� ������� ������ q
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::balance(Node* p) // ������������ ���� p
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

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::findmin(Node* p) // ����� ���� � ����������� ������ � ������ p 
{
	return p->left ? findmin(p->left) : p;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::removemin(Node* p) // �������� ���� � ����������� ������ �� ������ p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::insert(Node* p, U* k) // ������� ����� k � ������ � ������ p
{
	if (!p) return new Node(k);
	if (*k<*(p->key))
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::remove(Node* p, U* k) // �������� ����� k �� ������ p
{
	if (!p) return 0;
	if (*k < *(p->key))
		p->left = remove(p->left, k);
	else if (*k > *(p->key))
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

template <class U>
void AVLTree<U>::postfixFree(Node* x)
{

	x ? postfixFree(x->left) : 0;
	x ? postfixFree(x->right) : 0;
	if (x)
		delete x;
}
