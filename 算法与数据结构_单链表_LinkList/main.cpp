#include "LinkList.h"

int main()
{
	LinkList L1, L;
	int a1[] = { 1, 2, 3, 4, 5 };
	int a2[] = { -1,0, 1, 2, 3, 4, 5 };
//	InitList(L);				
	CreatListF(L1, a2, 7);
	CreatListR(L, a1, 5);
	if (ListEmpty(L))
		cout << "单链表为空" << endl;
	else {
		cout << "单链表不为空,链表打印如下：" << endl;
		DispLlist(L);
		cout << "单链表长度为" << ListLength(L) << endl;
	}

	ElemType e;			//存放取出的值
	if (GetElem(L, 3, e))
		cout << "第三个元素的值为" << e << endl;
	else
		cout << "查找失败" << endl;

//	e = 10;
	int pos = LocateElem(L, e);

	if (pos)
		cout << "值为" << e << "的元素在第" << pos << "个位置" << endl;
	else
		cout << "未找到值为" << e << "的元素" << endl;
	pos = 6;
	if (InsertList(L, pos, e + 1))
		cout << "插入成功" << endl;
	else
		cout << "插入失败" << endl;
	DispLlist(L);

	if (DeleteList(L, pos, e))
		cout << "成功删除第" << pos <<"个位置" << "值为" << e << "的元素" << endl;
	else
		cout << "删除失败" << endl; 
	DispLlist(L);

	DispLlist(L1);
	UnionList(L, L1);
	DispLlist(L);

	DestroyList(L);
	return 0;
}