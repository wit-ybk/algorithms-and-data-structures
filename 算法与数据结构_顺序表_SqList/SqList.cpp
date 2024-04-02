#include "SqList.h"

//����˳������һ������Ԫ��
void CreateList(SqList& L, ElemType a[], int n)	
{
//	L = (SqList*)malloc(sizeof(SqList));
	L.data = new ElemType[MAXSIZE];
	L.length = 0;
	for (int i = 0; i < n; ++i)
	{
		L.data[i] = a[i];
		L.length++;
	}
}

//��ʼ�����Ա�
void InitList(SqList& L)
{
	L.data = new ElemType[MAXSIZE];
	L.length = 0;
}

//�������Ա�
void DestroyList(SqList& L)
{
//	free(L);									//��main()�����д�����ʱ���Ա�ָ��SqList*L����ֱ���ͷ�L
	delete  L.data;
	L.data = nullptr;
//	cout << &L.data << endl;					//�����ڴ�ռ��Ƿ��ͷųɹ�
}


//�ж����Ա��Ƿ�Ϊ��
bool ListEmpty(SqList L)
{
	return (L.length == 0);
}

//��ȡ���Ա���
int ListLength(SqList L)
{
	return (L.length);
}

 //��ӡ���Ա�
void DispList(SqList L)
{
	for (int i = 0; i < L.length; ++i)
		cout << L.data[i] << " ";
	cout << endl;
//	cout << &L.data << endl;
}

//��λ�ò��ң������Ա��еĵ�i��Ԫ�ص�ֵ��
bool GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return false;
	e = L.data[i - 1];
	return true;
}

//����ֵ����
int  LocateElem(SqList L, ElemType e)
{
	int i = 0;
	while ( L.data[i] != e && i < L.length)
	{
		++i;
	}
	if (i >= L.length) return 0;
	else return i+1;
}

//����Ԫ��
bool InsertList(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1 || L.length == MAXSIZE)	
		return false;
	for (int j = L.length ; j >= i; --j)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//ɾ��Ԫ��
bool DeleteList(SqList& L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) return false;
	e = L.data[i - 1];
	for (int j = i - 1; j < L.length - 1; ++j)
	{
		L.data[j] = L.data[j + 1];
	}
	L.length--;
	return true;
}


//�ϲ�����˳�����ͬԪ��ֻ����һ��
void UnionList(SqList& L1, SqList L2)
{
	for (int i = 1; i <= L2.length; ++i)
	{
		ElemType e;
		GetElem(L2, i, e);
		if (!LocateElem(L1, e))
			InsertList(L1, L1.length+1, e);
	}
}

//�����ĺϲ�
void MergeList(SqList L1, SqList L2, SqList& L3)
{
	ElemType* p1 = L1.data, *p2 = L2.data;
	ElemType* p1_last = &L1.data[L1.length - 1], * p2_last = &L1.data[L1.length - 1];
	InitList(L3);
	int i = 0;
	while (p1 <= p1_last && p2 <= p2_last)
	{
		if (*p1 <= *p2)
		{
			L3.data[i] = *p1;
			++p1;
			++i;
		}
		else
		{
			L3.data[i] = *p2;
			++p2;
			++i;
		}
	}

	while (p1 <= p1_last)
	{
		L3.data[i] = *p1;
		++p1;
		++i;
	}

	while (p2 <= p2_last)
	{
		L3.data[i] = *p2;
		++p2;
		++i;
	}

	L3.length = i;
}