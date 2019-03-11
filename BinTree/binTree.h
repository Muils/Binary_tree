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
											//����������� ������ � ������ q
											//p - ������ ������ ������
											//flag=0 - �������� ������ ������� �
											//flag=1 - �������� ������� ������� �
	Node *Tree(int n, Node *p);		//	+
									//���������� ��������� �� n ����� � ������ p
									//����� ��������
	Node *Tree(int n, Node *p, int *A, int &i);		//+-
													//A - ������ ������
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

	void Add(int k, Node *p);//���������� ���� � ������ k ����� ���� p		//	+
	void DelLeaf(Node *p);		//	+
	void Del(Node *p);		//	+

	void TreeTravel_LCR(Node *p);		//	+
										//LCR - ����-������-�����
	void TreeTravel_LRC(Node *p);		//	+
										//LCR - ����-�����-������
	void TreeTravel_RLC(Node *p);		//	+
										//RLC - �����-����-������

	Node *FindKey(Node *p, int k);
	//����� �� �����
	Node *FindMin(Node *p);
	//����� ��������
	Node *FindMax(Node *p);
	//����� ���������
	int FindHight(Node *p);
	//����� ������

	void PrintTree(int k, Node *p);		//	+
										//����� ������ � ������ p �� �������
	Node *Root()
	{
		return root;
	}
	void Clear();
};

