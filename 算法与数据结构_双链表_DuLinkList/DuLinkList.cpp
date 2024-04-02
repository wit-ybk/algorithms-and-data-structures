#include "DuLinkList.h"

//头插法创建双链表
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
			L->next->prior = newNode;		//当双链表中有结点时，修改L->next的前驱指针 *****
		L->next = newNode;
		newNode->prior = L; 
	}
}

//尾插法创建双链表
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

//插入元素
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
			p->next->prior = newNode;		//只有当p存在后继结点时，才修改其前驱指针
		p->next = newNode;
		newNode->prior = p;
		return true;
	}
}

//删除元素;
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

//打印单链表
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