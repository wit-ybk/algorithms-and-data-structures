#include "DuLinkList.h"

//ͷ�巨����˫����
void CreateListF(DuLinkList& L, ElemType a[], int n)
{
	L = new DuLNode;
	L->prior =  L->next = NULL;
	for (int i = 0; i < n; ++i)
	{
		DuLNode* newNode = new DuLNode;
		newNode->data = a[i];
		newNode->next = L->next;
		if(L->next != NULL)
			L->next->prior = newNode;		//��˫�������н��ʱ���޸�L->next��ǰ��ָ�� *****
		L->next = newNode;
		newNode->prior = L; 
	}
}

//β�巨����˫����
void CreateListR(DuLinkList& L, ElemType a[], int n)
{
	L = new DuLNode;
	L->prior  = NULL;
	DuLNode* p = L;
	for (int i = 0; i < n; ++i)
	{
		DuLNode* newNode = new DuLNode;
		newNode->data = a[i];
		p->next = newNode;
		newNode->prior = p;
		p = newNode;
	}
	p->next = NULL;
}

//����Ԫ��
bool InsertList(DuLinkList& L, int i, ElemType e)
{
	DuLNode* p = L;
	int j = 0;
	while (p != NULL && j < i-1)
	{	
		j++;
		p = p->next;
	}
	if (p == NULL || j > i)
		return false;
	else
	{	
		DuLNode* newNode = new DuLNode;
		newNode->data = e;
		newNode->next = p->next;
		if(p->next != NULL)
			p->next->prior = newNode;		//ֻ�е�p���ں�̽��ʱ�����޸���ǰ��ָ��
		p->next = newNode;
		newNode->prior = p;
		return true;
	}
}

//ɾ��Ԫ��;
bool DeleteList(DuLinkList& L, int i, ElemType& e)
{
	DuLNode* p = L->next;
	int j = 1;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL || j > i)
		return false;
	else
	{
		e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		delete p;
		return true;
	}
}

//��ӡ������
void DispList(DuLinkList L)
{
	DuLNode* p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}