#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>

using namespace std;

class Node
{
public:
	int key;
	Node *parent, *left, *right;
	Node(int k = 0, Node *P = NULL, Node *L = NULL, Node *R = NULL)
	{
		key = k;
		parent = P;
		left = L;
		right = R;
	}
	int Key()
	{
		return key;
	}
	friend class BinTree;
};

class BinTree
{
protected:
	Node *root;
	void Copy(Node *q, Node *p, int flag);	//	+
											//копирование дерева с корнем q
											//p - предок нового дерева
											//flag=0 - копируем левого потомка р
											//flag=1 - копируем правого потомка р
	Node *Tree(int n, Node *p);		//	+
									//построение поддерева из n узлов с корнем p
									//ключи случайны
	Node *Tree(int n, Node *p, int *A, int &i);		//+-
													//A - массив ключей
public:
	BinTree()
	{
		root = NULL;
	}
	BinTree(int n);//n - count of keysc
	BinTree(int n, int *A);//a - array of keys	//+-
	BinTree(BinTree &);		//	+
	BinTree & operator = (BinTree &);		//	+
	~BinTree();		//	+

	void Add(int k, Node *p);//добавление узла с ключом k после узла p		//	+
	void DelLeaf(Node *p);		//	+
	void Del(Node *p);		//	+

	void TreeTravel_LCR(Node *p);		//	+
										//LCR - лево-корень-право
	void TreeTravel_LRC(Node *p);		//	+
										//LCR - лево-право-корень
	void TreeTravel_RLC(Node *p);		//	+
										//RLC - право-лево-корень

	Node *FindKey(Node *p, int k);
	//поиск по ключу
	Node *FindMin(Node *p);
	//поиск минимума
	Node *FindMax(Node *p);
	//поиск максимума
	int FindHight(Node *p);
	//поиск высоты

	void PrintTree(int k, Node *p);		//	+
										//вывод дерева с корнем p на консоль
	Node *Root()
	{
		return root;
	}
	void Clear();
};

