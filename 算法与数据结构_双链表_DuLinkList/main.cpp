#include "DuLinkList.h"

int main()
{
	DuLinkList L;
	int a[] = { 1,2,3,4,5 };
//	CreateListF(L, a, 5);
	CreateListR(L, a, 5);
	DispList(L);

	if (InsertList(L, 6, 4))
		cout << "����ɹ�" << endl;
	else
		cout << "����ʧ��" << endl;
	DispList(L);

	ElemType e;
	if (DeleteList(L, 3, e))
		cout << "�ɹ�ɾ����3��λ��" << "ֵΪ" << e << "��Ԫ��" << endl;
	else
		cout << "ɾ��ʧ��" << endl;
	DispList(L);

	return 0;
}