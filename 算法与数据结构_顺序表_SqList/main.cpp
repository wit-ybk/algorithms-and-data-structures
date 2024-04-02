#include "SqList.h"

int main()
{
	
/*	基本功能的验证
	ElemType a[5] = { 1, 2, 3, 4, 5 };
	//SqList *L;
	SqList L;
	InitList(L);
	CreateList(L, a, 5);
	if(ListEmpty(L))
		cout << "顺序表不为空" << endl;
	DispList(L);
	cout << "顺序表的长度为：" << ListLength(L) <<endl;
	ElemType elem;
	if (GetElem(L, 2, elem))
		cout << "顺序第2个元素为：" << elem;
	cout<< endl;
	int i = LocateElem(L, elem);
	if (i != 0)
		cout << "值为" << elem << "的元素在顺序表中第" << i << "位";
	cout << endl;
	if (InsertList(L, i, elem))
		cout << "在顺序表第" << i << "位" << "添加了元素" << elem ;
	cout << endl;
	DispList(L);
	if (DeleteList(L, i, elem))
		cout << "删除了顺序表中第" << i << "个元素，其值为" <<elem ;
	cout << endl;
	DispList(L);
	DestroyList(L);

*/
	//有序表的合并

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