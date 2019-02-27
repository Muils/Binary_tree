#pragma once
#include <iostream>

class Node
{
	int key;
	Node *parent, *left, *right;

public:
	Node(int k = 0, Node *P = NULL, Node *L = NULL, Node *R = NULL){
		key = k; 
		parent = P;
		left = L;
		right = R;
	}
	int Key(){
	return key;
	}
friend class BinTree;
};

class BinTree
{
	Node *root;
	void Copy(Node *q, Node *p, int flag);
	Node *Tree(int n, Node *p);
	Node *Tree(int n, Node *p, int *mas, int count);
public:
	BinTree() { root = NULL; }
	BinTree(int n); 
	BinTree(int *a, int n); 
	BinTree(BinTree &);
	BinTree &operator= (BinTree &);
	~BinTree() { delete root; }
	void Add(int k, Node *p);
	void DelList(Node *p);
	void Del(Node *p);
	void TreeTravelsal_LCR(Node *p);
	void PrintTree(int k, Node *p);
	Node* Root() { return root; };
	void Clear();

};


