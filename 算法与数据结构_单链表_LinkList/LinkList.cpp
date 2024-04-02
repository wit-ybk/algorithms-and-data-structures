#include "LinkList.h"

//头插法创建单链表
void CreatListF(LinkList& L, ElemType a[], int n)
{
	L = new LNode;			//由头指针创造头节点
	L->next = NULL;
	for (int i = 0; i < n; ++i)
	{
		LNode* newNode = new LNode;
		newNode->data = a[i];
		newNode->next = L->next;
		L->next = newNode;
	}
}

//尾插法创建单链表
void CreatListR(LinkList& L, ElemType a[], int n)
{
	L = new LNode;			//由头指针创造头节点
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

//初始化单链表
void InitList(LinkList& L)
{
	L = new LNode;			
	L->next = NULL;
}

//销毁单链表
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

//判断单链表是否为空
bool ListEmpty(LinkList L)
{
	return (L->next == NULL);
}

//获取单链表的长度
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

//打印单链表
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

//按位置查找
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

//按值查找
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

//插入元素
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

//删除元素
bool DeleteList(LinkList L, int i, ElemType& e)
{
	LNode* p = L;
	int j = 0;
	while (p->next != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}

	if (p->next == NULL || j > i - 1)	// i>n 或 i<1都不合理 
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

//合并两个单链表，相同元素只保留一个
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