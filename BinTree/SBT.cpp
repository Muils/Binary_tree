#include"SBT.h"


void SBTree::CreateRoot(int k)
{
	root = new Node(k);
}

SBTree::SBTree(int n)
{
	if (!n) root = NULL;
	else
	{
		CreateRoot(rand() % 50);
		for (int i = 1; i<n; i++)
			Add(rand() % 50, root);
	}
}

SBTree::SBTree(int n, int *A)
{
	if (!n) root = NULL;
	else
	{
		CreateRoot(A[0]);
		for (int j = 1; j<n; j++)
			Add(A[j], root);
	}
}
void SBTree::Add(int k, Node *p)
{
	Node *q;
	if (k < p->key)
		if (p->left == NULL)
		{
			q = new Node(k);
			p->left = q;
			q->parent = p;
		}
		else Add(k, p->left);
	else
		if (p->right == NULL)
		{
			q = new Node(k);
			p->right = q;
			q->parent = p;
		}
		else Add(k, p->right);
}

void SBTree::Del(Node *p)
{
	if (p->left == NULL && p->right == NULL)
	{
		DelLeaf(p);
		return;
	}
	if (p->left && p->right == NULL) 	// нет правого поддерева
	{
		Node *q = p->parent;
		if (q->left == p)
			q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}
	if (p->left == NULL && p->right) 	// нет левого поддерева
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
	Node *t = p->left;
	if (t->right == NULL)
	{
		t->right = p->right;	//связь 1
		p->right->parent = t;	//связь 2

		if (q->left == p) q->left = t;	//связь 3
		else q->right = t;
		t->parent = q;	//связь 4
	}
	else
	{
		while (t->right) t = t->right;

		t->parent->right = t->left;	//связь 1
		if (t->left) t->left->parent = t->parent;		//связь 2

		t->left = p->left;
		t->right = p->right;

		p->right->parent = t;
		p->left->parent = t;

		t->parent = q;

		if (q->right == p) q->right = t;	//связь 5
		else q->left = t;	//связь 6
	}
	delete p;
}

SBTree & SBTree:: operator = (SBTree &T)
{
	if (this != &T)
	{
		Clear();
		delete root;
		if (T.root == NULL)
			root = NULL;
		else
		{
			root = new Node(T.root->key);
			Copy(T.root->left, root, 0);
			Copy(T.root->right, root, 1);
		}
	}
	return *this;
}

void SBTree::TreeTravel_LRC(Node *p, int *A, int &k)
{
	if (!p) return;
	TreeTravel_LRC(p->left, A, k);
	A[k++] = p->key;
	TreeTravel_LRC(p->right, A, k);
}

//Node * SBTree::FindKey(int k, Node *p)
//{  if (!p) return NULL;
//   if (p->key == k) return p;
//	if (k < p->key)
//	{
//		if (p->left==NULL)
//			return NULL;
//		else FindKey(k, p->left);
//	}
//	if(k > p->key)
//	{
//		if (p->right==NULL)
//			return NULL;
//		else FindKey(k, p->right);
//	}
//	if (p->key == k)
//		return p;
//}

Node * SBTree::FindKey(int k, Node *p)
{
	if (!p) return NULL;
	if (p->key == k) return p;

	if (k < p->key)
		return FindKey(k, p->left);
	else  return FindKey(k, p->right);



}

Node *SBTree::FindMin(Node *p)
{
	while (p->left)
		p = p->left;
	return p;
}

Node *SBTree::FindMax(Node *p)
{
	while (p->right)
		p = p->right;
	return p;
}
