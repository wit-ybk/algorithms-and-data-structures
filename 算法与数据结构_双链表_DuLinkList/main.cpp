#include "DuLinkList.h"

int main()
{
	DuLinkList L;
	int a[] = { 1,2,3,4,5 };
//	CreateListF(L, a, 5);
	CreateListR(L, a, 5);
	DispList(L);

	if (InsertList(L, 6, 4))
		cout << "插入成功" << endl;
	else
		cout << "插入失败" << endl;
	DispList(L);

	ElemType e;
	if (DeleteList(L, 3, e))
		cout << "成功删除第3个位置" << "值为" << e << "的元素" << endl;
	else
		cout << "删除失败" << endl;
	DispList(L);

	return 0;
}