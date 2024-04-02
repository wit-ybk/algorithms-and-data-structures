#include "SqList.h"

int main()
{
	
/*	�������ܵ���֤
	ElemType a[5] = { 1, 2, 3, 4, 5 };
	//SqList *L;
	SqList L;
	InitList(L);
	CreateList(L, a, 5);
	if(ListEmpty(L))
		cout << "˳���Ϊ��" << endl;
	DispList(L);
	cout << "˳���ĳ���Ϊ��" << ListLength(L) <<endl;
	ElemType elem;
	if (GetElem(L, 2, elem))
		cout << "˳���2��Ԫ��Ϊ��" << elem;
	cout<< endl;
	int i = LocateElem(L, elem);
	if (i != 0)
		cout << "ֵΪ" << elem << "��Ԫ����˳����е�" << i << "λ";
	cout << endl;
	if (InsertList(L, i, elem))
		cout << "��˳����" << i << "λ" << "�����Ԫ��" << elem ;
	cout << endl;
	DispList(L);
	if (DeleteList(L, i, elem))
		cout << "ɾ����˳����е�" << i << "��Ԫ�أ���ֵΪ" <<elem ;
	cout << endl;
	DispList(L);
	DestroyList(L);

*/
	//�����ĺϲ�

	int a1[] = { 1,3,5,7,7,8,9 };
	int a2[] = { 1,2,4,5,6 };
	SqList L1, L2;
	CreateList(L1, a1, 7);
	CreateList(L2, a2, 5);
	DispList(L1);
	DispList(L2);

	UnionList(L1, L2);
	DispList(L1);

	SqList L3;
	MergeList(L1, L2, L3);
	DispList(L3);


	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 0;
}