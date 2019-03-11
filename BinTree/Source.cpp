#include "SBT.h"


int main()
{
	int *a, n;
	cout << "Input amount of elements: ";
	cin >> n;
	a = new int[n];
	cout << "Input elements: ";
	for (int i = 0; i<n; i++)
		cin >> a[i];
	//дерево с заданым масивом значений
	BinTree H(n, a);
	H.PrintTree(1, H.Root());

	//дерево рандомных чисел
	puts("");
	BinTree T(7);
	T.PrintTree(1, T.Root());
	//поиск мин макс 
	Node *q=T.FindMax(T.Root());
	int max=q->Key();
	cout<<"max key="<<max<<endl;
	
	q=T.FindMin(T.Root());
	int min=q->Key();
	cout<<"min key="<<min<<endl;

	int h=1;
	h=T.FindHight(T.Root());
	cout<<"Hight="<<h<<endl;
	
	T.Add(50, T.Root());
	cout<<"new tree:"<<endl;
	T.PrintTree(1, T.Root());

	T.Add(150, T.Root());
	cout<<"new tree:"<<endl;
	T.PrintTree(1, T.Root());

	h=T.FindHight(T.Root());
	cout<<"Hight="<<h<<endl;

	cout<<endl<<"Traversal of Tree (LCR):"<<endl;
	T.TreeTravel_LCR(T.Root());
	puts("");

	cout<<endl<<"Traversal of Tree (LRC):"<<endl;
	T.TreeTravel_LRC(T.Root());
	puts("");

	cout<<endl<<"Traversal of Tree (RLC):"<<endl;
	T.TreeTravel_RLC(T.Root());
	puts("");

	cout<<"tree without max:"<<endl;
	q=T.FindMax(T.Root());
	T.DelLeaf(q);
	T.PrintTree(1, T.Root());

	cout<<endl<<"tree without 5:"<<endl;
	q=T.FindKey(T.Root(), 18);
	if (q) T.DelLeaf(q);
	T.PrintTree(1, T.Root());

	cout<<endl<<"tree without 8:"<<endl;
	q=T.FindKey(T.Root(), 8);
	if (q) T.Del(q);
	T.PrintTree(1, T.Root());

	BinTree S=T;
	cout<<endl<<"tree S=T:"<<endl;
	S.PrintTree(1, S.Root());

	system("PAUSE");
	return 0;
}
/*
int main()
{
	int n, *A;
	cout << "Input amount of elements: ";
	cin >> n;
	A = new int[n];
	cout << "\nInput elements: ";
	for (int i = 0; i<n; i++)
		cin >> A[i];
	SBTree E(n, A);
	E.PrintTree(1, E.Root());

	SBTree T;
	T.CreateRoot(1);
	T.Add(2, T.Root());
	T.Add(3, T.Root());
	T.Add(4, T.Root());
	T.Add(5, T.Root());
	T.Add(6, T.Root());
	T.Add(7, T.Root());

	puts("");
	T.PrintTree(1, T.Root());

	SBTree H;
	T.CreateRoot(25);
	T.Add(15, T.Root());
	T.Add(17, T.Root());
	T.Add(7, T.Root());
	T.Add(10, T.Root());
	T.Add(35, T.Root());
	T.Add(45, T.Root());
	T.Add(2, T.Root());
	T.Add(12, T.Root());
	T.Add(11, T.Root());
	T.Add(19, T.Root());

	T.PrintTree(1, T.Root());

	int a[100], i;
	n = 0;
	cout<<endl<<"Traversal of Tree (LCR):"<<endl;
	T.TreeTravel_LRC(T.Root(), a, n);
	for (i=0; i<n; i++)
	cout<<a[i]<<' ';

	puts("");

	Node *q=T.FindMax(T.Root());
	int max=q->Key();
	cout<<endl<<"max key="<<max<<endl;


	q=T.FindMin(T.Root());
	int min=q->Key();
	cout<<"min key="<<min<<endl;

	int h=1;
	h=T.FindHight(T.Root());
	cout<<"Hight="<<h<<endl;

	SBTree S;
	cout<<"пустое дерево"<<endl;
	S.PrintTree(1, S.Root());

	puts("");

	S=T;
	S.PrintTree(1, S.Root());

	puts("");

	Node *p=S.FindKey(15, S.Root());
	if(p) S.Del(p);
	cout<<"дерево без узла 15"<<endl;
	S.PrintTree(1, S.Root());
	
	system("PAUSE");
	return 0;
}*/


