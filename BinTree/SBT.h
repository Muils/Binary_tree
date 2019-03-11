#pragma once
#include "BinTree.h"

using namespace std;

class SBTree : public BinTree
{
public:
	SBTree() : BinTree() {};
	SBTree(int n);	//n - ���-�� ������, ����� ��������	//+
	SBTree(int n, int *a);	//a - ������ ������	//+
	SBTree(SBTree &);
	~SBTree() {};
	SBTree &operator = (SBTree &);	//+

	void CreateRoot(int k);	// +
	virtual void Add(int k, Node *p);//���������� ���� � ������ k ����� ���� p	// +
	virtual	void Del(Node *p);		// +
	virtual	Node *FindKey(int k, Node *p);	// +
	virtual	Node *FindMin(Node *p);		// +
	virtual	Node *FindMax(Node *p);		// +
	void TreeTravel_LRC(Node *p, int *A, int &k);	//+
													// ���������� ������������ � ������ �
};