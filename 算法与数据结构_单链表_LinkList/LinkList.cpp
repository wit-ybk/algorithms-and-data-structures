#include "LinkList.h"

//ͷ�巨����������
void CreatListF(LinkList& L, ElemType a[], int n)
{
	L = new LNode;			//��ͷָ�봴��ͷ�ڵ�
	L->next = NULL;
	for (int i = 0; i < n; ++i)
	{
		LNode* newNode = new LNode;
		newNode->data = a[i];
		newNode->next = L->next;
		L->next = newNode;
	}
}

//β�巨����������
void CreatListR(LinkList& L, ElemType a[], int n)
{
	L = new LNode;			//��ͷָ�봴��ͷ�ڵ�
	L->next = NULL;
	LNode* p = L;
	for (int i = 0; i < n; ++i)
	{
		LNode* newNode = new LNode;
		newNode->data = a[i];
		p->next = newNode;
		p = newNode;
	}
	p->next = NULL;
}

//��ʼ��������
void InitList(LinkList& L)
{
	L = new LNode;			
	L->next = NULL;
}

//���ٵ�����
void DestroyList(LinkList& L)
{
	LNode* pre, *p;
	pre = L; 
	p = pre->next;
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

//�жϵ������Ƿ�Ϊ��
bool ListEmpty(LinkList L)
{
	return (L->next == NULL);
}

//��ȡ������ĳ���
int  ListLength(LinkList L)
{
	LNode* p = L;
	int len = 0;
	while (p->next != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//��ӡ������
void DispLlist(LinkList L)
{
	LNode* p = L->next ;
	while (p != NULL)
	{
		cout << p->data <<" ";
		p = p->next;
	}
	cout << endl;
}

//��λ�ò���
bool GetElem(LinkList L, int i, ElemType& e)
{
	LNode* p = L->next;
	int j = 1;
	while (p != NULL && j < i )
	{	
		j++;
		p = p->next;
	}
	if (p != NULL) {
		e = p->data;
		return true;
	}
	else
		return false;
}

//��ֵ����
int  LocateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;
	int j = 1;
	while (p != NULL && p->data != e)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
		return 0;
	else 
		return j;
}

//����Ԫ��
bool InsertList(LinkList L, int i, ElemType e)
{
	LNode *p = L;
	int j = 0;
	while (p != NULL && j < i-1)
	{
		j++;
		p = p->next;
	}
	
	if (p == NULL || j>i-1)
		return false;
	else
	{
		LNode* newNode = new LNode;
		newNode->data = e;
		newNode->next = p->next;
		p->next = newNode;
		return true;
	}
}

//ɾ��Ԫ��
bool DeleteList(LinkList L, int i, ElemType& e)
{
	LNode* p = L;
	int j = 0;
	while (p->next != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}

	if (p->next == NULL || j > i - 1)	// i>n �� i<1�������� 
		return false;
	else
	{
		LNode* r = p->next;
		e = r->data;
		p->next = r->next;
		delete r;
		return true;
	}
}

//�ϲ�������������ͬԪ��ֻ����һ��
void UnionList(LinkList& L1, LinkList L2)
{
	int len1 = ListLength(L1), len2 = ListLength(L2);
	for (int i = 1; i <= len2; ++i)
	{
		ElemType e;
		GetElem(L2, i, e);
		if (!LocateElem(L1,e))
			InsertList(L1, ++len1, e);
	}
}