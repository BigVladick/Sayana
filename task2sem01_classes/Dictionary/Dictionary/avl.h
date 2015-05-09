
/*
	AVLTree - АВЛ дерево. Подробно описано оно здесь http://habrahabr.ru/post/150732/ .
	Так что я опишу то, что я внес дополнительно сюда.
	- int amount = количество элементов в дереве
	- void fromArray(U arr[], int length) = добавить массив элементов
	- void remove(Inner* sacredfice) = удаляет элемент списка по адрессу
	- void append(U value) = добавляет элемент в конец списка
	- U* toArray() = преобразует дерево в динамический массив и возвращает его. Оболочка, логика в функции ниже:
		- void toArray(Node* x, U* ar, int& am)
	- void print() = вывод всех элементов списка. Это оболочка, вся логика в функции ниже.
		- void print(Node* x)
	- bool has(U x) =  есть ли тут элемент с таким значением
	- void postfixFree(Node* x) = освобождает память. Обходит дерево Постфиксным способом (Погугли что это)

*/


template <class U>
class AVLTree
{

public:
	// http://habrahabr.ru/post/150732/
	struct Node // структура для представления узлов дерева
	{
		U key;
		unsigned char height;
		Node* left;
		Node* right;
		Node(U k) { key = k; left = right = 0; height = 1; }
		~Node() {}
	};
	Node* root;
	int amount;
	AVLTree() : root(nullptr), amount(0) {}
	~AVLTree();
	void append(U x);
	bool has(U x);
	void remove(U x);
	void print();
	U* toArray();
	void fromArray(U arr[], int length);

private:
	unsigned char height(Node* p);
	int bfactor(Node* p);
	void fixheight(Node* p);
	Node* rotateright(Node* p); // правый поворот вокруг p
	Node* rotateleft(Node* q); // левый поворот вокруг q
	Node* balance(Node* p); // балансировка узла p
	Node* findmin(Node* p); // поиск узла с минимальным ключом в дереве p 
	Node* removemin(Node* p); // удаление узла с минимальным ключом из дерева p
	Node* insert(Node* p, U k); // вставка ключа k в дерево с корнем p
	Node* remove(Node* p, U k); // удаление ключа k из дерева p
	void postfixFree(Node* x);
	void print(Node* x);
	void toArray(Node* x, U* ar, int& am);
};

template <class U>
AVLTree<U>::~AVLTree()
{
	// обход постфиксным методом
	postfixFree(root);
}

template <class U>
void AVLTree<U>::append(U x)
{
	amount++;
	root = insert(root, x);
}

template <class U>
void AVLTree<U>::remove(U x)
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
typename AVLTree<U>::Node* AVLTree<U>::insert(Node* p, U k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new Node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

template <class U>
typename AVLTree<U>::Node* AVLTree<U>::remove(Node* p, U k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < *(p->key))
		p->left = remove(p->left, k);
	else if (k > *(p->key))
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

template <class U>
bool AVLTree<U>::has(U x)
{
	Node* slot = root;
	while (slot)
	{
		if (slot->key == x)
			return true;
		if (x < slot->key)
			slot = slot->left;
		if (x > slot->key)
			slot = slot->right;
	}
	return false;
}

template <class U>
void AVLTree<U>::print()
{
	print(root);
}

template <class U>
void AVLTree<U>::print(Node* x)
{
	x ? print(x->left) : 0;
	if (x)
		cout << x->key << endl;
	x ? print(x->right) : 0;
	
}

template <class U>
U* AVLTree<U>::toArray()
{
	U* arr = new U[amount]();
	int len = 0;
	toArray(root, arr, len);
	return arr;
}

template <class U>
void AVLTree<U>::toArray(Node* x, U* ar, int& am)
{
	x ? toArray(x->left,ar,am)  : 0;
	if (x)
	{
		ar[am++] = x->key;
	}
	x ? toArray(x->right, ar, am) : 0;
}

template <class U>
void AVLTree<U>::fromArray(U arr[], int length)
{
	for (int i = 0; i < length; i++)
		append(U(arr[i]));
}