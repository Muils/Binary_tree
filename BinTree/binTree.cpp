#include"binTree.h"


Node * BinTree::Tree(int n, Node *p)
{
	if (n == 0)	return NULL;	//точка выхода из рекурсии
	Node *q = new Node(rand() % 50, p);
	//хотим, чтобы дерево было примерно сбалансировано, поэтому заводим переменные для контроля, сколько потомков идёт налево и сколько направо
	int nL = (n - 1) / 2;
	int nR = n - 1 - nL;
	q->left = Tree(nL, q);
	q->right = Tree(nR, q);
	return q;
}

Node * BinTree::Tree(int n, Node *p, int *A, int &i)
{
	//if (n==0) return NULL;
	Node *q = new Node(A[i], p);
	int nL = (n - 1) / 2;
	int nR = n - 1 - nL;

	/*q->left=Tree(nL, q, A, i++);
	q->right=Tree(nR, q, A, i++);*/

	if (nL)
	{
		i++;
		q->left = Tree(nL, q, A, i);
	}
	if (nR)
	{
		i++;
		q->right = Tree(nR, q, A, i);
	}

	return q;
}


void BinTree::Copy(Node *q, Node *p, int flag)
{
	if (!q) return;	//выход из рекурсии
	Node *t = new Node(q->key, p);
	if (flag)
		p->right = t;
	else
		p->left = t;
	//В случае же, если у q есть потомки, имеет смысл следующая рекурсия:
	Copy(q->left, t, 0);
	Copy(q->right, t, 1);
}

BinTree::BinTree(int n)
{
	root = Tree(n, 0);
}

BinTree::BinTree(int n, int *A)
{
	int i = 0;
	root = Tree(n, 0, A, i);
}

BinTree::BinTree(BinTree &T)
{
	if (T.root == NULL)
		root = NULL;
	else
	{
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
}

BinTree & BinTree::operator = (BinTree &T)
{
	if (this != &T)
	{
		Clear();

		if (T.root == NULL)
		{
			delete root;
			root = NULL;
		}
		else
		{
			root->key = T.root->key;
			Copy(T.root->left, root, 0);
			Copy(T.root->right, root, 1);
		}
	}
	return *this;
}

BinTree::~BinTree()
{
	Clear();
	delete root;
}


Node * BinTree::FindKey(Node *p, int k)
{
	if (!p) return NULL;
	if ((p->key) == k) return p;
	/*FindKey(p->left, k);
	FindKey(p->right, k);*/
	if (FindKey(p->left, k)) return FindKey(p->left, k);
	else return FindKey(p->right, k);
}

Node * BinTree::FindMin(Node *p)
{
	Node *min, *L, *R;
	if (!p) return NULL;
	//if (!p->left && !p->right) return p;
	min = p;
	L = FindMin(p->left);
	R = FindMin(p->right);
	if (L && (L->key < min->key)) min = L;
	if (R && (R->key < min->key)) min = R;

	return min;
}

Node * BinTree::FindMax(Node *p)
{
	Node *max, *L, *R;
	if (!p) return NULL;
	//if (!p->left && !p->right) return p;
	max = p;
	L = FindMax(p->left);
	R = FindMax(p->right);
	if (L && (L->key > max->key)) max = L;
	if (R && (R->key > max->key)) max = R;

	return max;
}

int BinTree::FindHight(Node *p)
{
	if (!p) return 0;
	int h1 = 0, h2 = 0;
	if (p->left) h1 = FindHight(p->left);
	if (p->right) h2 = FindHight(p->right);

	if (h1>h2) return h1 + 1;
	return h2 + 1;
}


void BinTree::Add(int k, Node *p)
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
	if (rand() % 2) Add(k, p->left);
	else Add(k, p->right);
}

void BinTree::DelLeaf(Node *p)
{
	if (p->left == NULL && p->right == NULL)
	{
		if (p->parent->left == p)		//проверка, что р - лист слева
			p->parent->left = NULL;
		else p->parent->right = NULL;
		delete p;
		return;
	}
	if (p->left != NULL) DelLeaf(p->left);
	else DelLeaf(p->right);
}

void BinTree::Del(Node *p)
{
	if (p->left == NULL && p->right == NULL)
	{
		DelLeaf(p);
		return;
	}
	if (p->left && p->right == NULL)
	{
		Node *q = p->parent;
		if (q->left == p)
			q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}
	if (p->left == NULL && p->right)
	{
		Node *q = p->parent;
		if (q->left == p)
			q->left = p->right;
		else q->right = p->right;
		p->right->parent = q;
		delete p;
		return;
	}
	//р имеет оба поддерева
	Node *q = p->parent;
	Node *t = p;
	while (t->left)  t = t->left;
	if (t->right == NULL)			//если дошли до листа; разрывание связей
		t->parent->left = NULL;
	else						//если дошли не до листа; разрывание связей
	{
		t->parent->left = t->right;
		t->right->parent = t->parent;
	}
	if (q->left == p)	q->left = t;
	else q->right = t;

	t->left = p->left;
	t->right = p->right;
	t->parent = q;

	if (t->left)	t->left->parent = t;		//возможно здесь заглючит, но не должно
	t->right->parent = t;

	delete p;
}

void BinTree::TreeTravel_LCR(Node *p)
{
	if (!p) return;
	TreeTravel_LCR(p->left);
	cout << p->key << ' ';
	TreeTravel_LCR(p->right);
}

void BinTree::TreeTravel_LRC(Node *p)
{
	if (!p) return;
	TreeTravel_LRC(p->left);
	TreeTravel_LRC(p->right);
	cout << p->key << ' ';
}

void BinTree::TreeTravel_RLC(Node *p)
{
	if (!p) return;
	TreeTravel_RLC(p->right);
	TreeTravel_RLC(p->left);
	cout << p->key << ' ';
}


void BinTree::PrintTree(int k, Node *p)
{
	if (!p) return;
	PrintTree(k + 5, p->right);
	for (int i = 0; i<k; i++) cout << ' ';
	cout << p->key << endl;
	PrintTree(k + 5, p->left);
}

void BinTree::Clear()
{
	if (!root) return;
	Node *t = root;
	while (t->left) Del(t->left);
	while (t->right) Del(t->right);
}

