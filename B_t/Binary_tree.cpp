#include"Binary_tree.h"


//_______________________________________

void BinTree::Copy(Node *q, Node *p, int flag)
{
	if (q == NULL) return;
	Node *t = new Node(q->key, p);
	if (flag) p->right = t;
	else p->left = t;
	Copy(q->left, t, 0);
	Copy(q->right, t, 1);
}

Node * BinTree::Tree(int n, Node *p)
{
	if (n == 0) return NULL;
	Node *q = new Node(rand() % 50, p);
	int nL, nR;
	nL = (n - 1) / 2; nR = n - 1 - nL;
	q->left = Tree(nL, q);
	q->right = Tree(nR, q);
	return q;
}

Node *BinTree::Tree(int n, Node *p, int *mass, int count = -1) {

	if (n == 0) return NULL;
	count++;
	Node *q = new Node(mass[count], p);
	int nL, nR;
	nL = (n - 1) / 2; nR = n - 1 - nL;
	q->left = Tree(nL, q, mass, count);
	q->right = Tree(nR, q, mass, count);
	return q;
}

BinTree::BinTree(int n){
	root = Tree(n, 0);
}

BinTree::BinTree(int *a, int n) {
	root = Tree(n, 0, a);
}


BinTree::BinTree(BinTree &T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
}

BinTree &BinTree::operator= (BinTree &T)
{
	if (this != &T)
	{
		Clear();
		if (T.root == NULL) root = NULL;
		else {
			root->key = T.root->key;
			Copy(T.root->left, root, 0);
			Copy(T.root->right, root, 1);
		}
	}
	return *this;
}

void BinTree::Add(int k, Node *p)
//добавление узла с ключом k после узла p
{
	if (p->left == NULL)
	{
		Node *q = new Node(k, p);
		p->left = q;
		return;
	}
	if (p->right == NULL)
	{
		Node *q = new Node(k, p);
		p->right = q;
		return;
	}
	if (rand() % 2)Add(k, p->left);
	else Add(k, p->right);
}

void BinTree::DelList(Node *p)
//удаление листа в поддереве с корнем p
{
	if (p->left == NULL && p->right == NULL)
	{
		if (p->parent->left == p)
			p->parent->left = NULL;
		else p->parent->right = NULL;
		delete p;
		return;
	}
	if (p->left) DelList(p->left);
	else DelList(p->right);
}

void BinTree::Del(Node *p)
//удаление узла p
{
	if (p->left == NULL && p->right == NULL)
	{
		DelList(p); return;
	}
	if (p->left &&  p->right == NULL)
	{
		Node *q = p->parent;
		if (q->left == p) q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}
	if (p->left == NULL && p->right)
	{
		Node *q = p->parent;
		if (q->left == p) q->left = p->right;
		else q->right = p->right;
		p->right->parent = q;
		delete p;
		return;
	}
	//когда p имеет оба поддерева
	Node *q = p->parent;
	Node *t = p;
	while(t->left)t = t->left;

	if (t->right == NULL)
		t->parent->left = NULL;
	else {
		t->parent->left = t->right;
		t->right->parent = t->parent;
	}
	if (q->left == p) q->left = t;
	else q->right = t;

	t->left = p->left;
	t->right = p->right;
	t->parent = q;

	if (t->left)t->left->parent = t;
	t->right->parent = t;

	delete p;
}

void BinTree::TreeTravelsal_LCR(Node *p)
//обход "лево-корень-право"
{
	if (!p)return;
	TreeTravelsal_LCR(p->left);
	std::cout << p->key << ' ';
	TreeTravelsal_LCR(p->right);
}

void BinTree::PrintTree(int k, Node *p)
//выод дерева с корнем p на консоль
{
	if (!p) return;
	PrintTree(k + 5, p->right);
	for (int i = 0; i<k; i++) std::cout << ' ';
	std::cout << p->key << std::endl;
	PrintTree(k + 5, p->left);
}
void BinTree::Clear() {
	Del(root);
}