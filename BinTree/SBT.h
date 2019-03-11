#pragma once
#include "BinTree.h"

using namespace std;

class SBTree : public BinTree
{
public:
	SBTree() : BinTree() {};
	SBTree(int n);	//n - кол-во ключей, ключи случайны	//+
	SBTree(int n, int *a);	//a - массив ключей	//+
	SBTree(SBTree &);
	~SBTree() {};
	SBTree &operator = (SBTree &);	//+

	void CreateRoot(int k);	// +
	virtual void Add(int k, Node *p);//добавление узла с ключом k после узла p	// +
	virtual	void Del(Node *p);		// +
	virtual	Node *FindKey(int k, Node *p);	// +
	virtual	Node *FindMin(Node *p);		// +
	virtual	Node *FindMax(Node *p);		// +
	void TreeTravel_LRC(Node *p, int *A, int &k);	//+
													// результаты записываются в массив А
};