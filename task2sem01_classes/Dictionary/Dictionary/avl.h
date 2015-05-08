/*
	Класс АВЛ - дерево
	- описание http://habrahabr.ru/post/150732/
	- очищает данную ему память
	- root = вершина дерева
	- amount = количество элементов в дереве
	- append(U* x) - добавить элемент в дерево
	- remove(U* x) - удалить элемент из дерева

*/


template <class U>
class AVLTree
{

public:
	// http://habrahabr.ru/post/150732/
	struct Node // структура для представления узлов дерева
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
	Node* rotateright(Node* p); // правый поворот вокруг p
	Node* rotateleft(Node* q); // левый поворот вокруг q
	Node* balance(Node* p); // балансировка узла p
	Node* findmin(Node* p); // поиск узла с минимальным ключом в дереве p 
	Node* removemin(Node* p); // удаление узла с минимальным ключом из дерева p
	Node* insert(Node* p, U* k); // вставка ключа k в дерево с корнем p
	Node* remove(Node* p, U* k); // удаление ключа k из дерева p
	void postfixFree(Node* x);
};

template <class U>
AVLTree<U>::~AVLTree()
{
	// обход постфиксным методом
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
typename AVLTree<U>::Node* AVLTree<U>::rotateright(Node* p) // правый поворот вокруг p
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::rotateleft(Node* q) // левый поворот вокруг q
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::balance(Node* p) // балансировка узла p
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

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findmin(p->left) : p;
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::removemin(Node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::insert(Node* p, U* k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new Node(k);
	if (*k<*(p->key))
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::remove(Node* p, U* k) // удаление ключа k из дерева p
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
