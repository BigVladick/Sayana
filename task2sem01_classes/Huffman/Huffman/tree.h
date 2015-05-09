#pragma once

template <class U>
struct Node
{
	U* value;
	Node* left;
	Node* right;
	Node() {}
	Node(U* v) : value(v), left(nullptr), right(nullptr) {}
	friend ostream& operator<<(ostream& cout, Node& time)
	{
		cout << *time.value;
		return cout;
	}
	friend bool operator==(Node& a, Node& b)
	{
		return *a.value == *b.value;
	}
	friend bool operator<(Node& a, Node& b)
	{
		return *a.value < *b.value;
	}
	friend bool operator>(Node& a, Node& b)
	{
		return !(a < b || a == b);
	}
};

// специальное дерево для этого алгоритма, повторно использовать не стоит
template <class U>
class Tree
{

public:
	
private:
	void postfixFree(Node<U>* x)
	{

		x ? postfixFree(x->left) : 0;
		x ? postfixFree(x->right) : 0;
		if (x)
			delete x;
	}
	void print(Node<U>* x)
	{
		x ? print(x->left) : 0;
		if (x)
			cout << *x->value << endl;
		x ? print(x->right) : 0;
	}
public:
	Node<U>* root;
	void print()
	{
		print(root);
	}

	Tree(): root(nullptr) {}
	//Tree(U* x) : root(new Node<U>(x)) {}
	~Tree()
	{
		postfixFree(root);
	}
};