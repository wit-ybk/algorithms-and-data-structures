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
		cout << "������Ϊ��" << endl;
	else {
		cout << "������Ϊ��,�����ӡ���£�" << endl;
		DispLlist(L);
		cout << "��������Ϊ" << ListLength(L) << endl;
	}

	ElemType e;			//���ȡ����ֵ
	if (GetElem(L, 3, e))
		cout << "������Ԫ�ص�ֵΪ" << e << endl;
	else
		cout << "����ʧ��" << endl;

//	e = 10;
	int pos = LocateElem(L, e);

	if (pos)
		cout << "ֵΪ" << e << "��Ԫ���ڵ�" << pos << "��λ��" << endl;
	else
		cout << "δ�ҵ�ֵΪ" << e << "��Ԫ��" << endl;
	pos = 6;
	if (InsertList(L, pos, e + 1))
		cout << "����ɹ�" << endl;
	else
		cout << "����ʧ��" << endl;
	DispLlist(L);

	if (DeleteList(L, pos, e))
		cout << "�ɹ�ɾ����" << pos <<"��λ��" << "ֵΪ" << e << "��Ԫ��" << endl;
	else
		cout << "ɾ��ʧ��" << endl; 
	DispLlist(L);

	DispLlist(L1);
	UnionList(L, L1);
	DispLlist(L);

	DestroyList(L);
	return 0;
}