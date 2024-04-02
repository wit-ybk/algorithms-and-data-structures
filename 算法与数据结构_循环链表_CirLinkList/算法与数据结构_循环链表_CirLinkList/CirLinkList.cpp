#include "CirLinkList.h"

//用数组a[]创建循环链表(尾插法)
void CreatList(CirLinkList& L, ElemType a[], int n)
{
	L = new CLNode;
	L->next = L;
	CLNode* p = L;
	for (int i = 0; i < n; ++i)
	{	
		CLNode* newNode = new CLNode;
		newNode->data = a[i];
		p->next = newNode;
		p = p->next;
	}
	p->next = L;
}

//打印链表
void DispList(CirLinkList L)
{
	CLNode* p = L->next;
	while (p != L)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//销毁链表
void DestoryList(CirLinkList& L)
{
	CLNode* pre = L, * p = L->next;
	while (p != L)
	{	
		delete pre;
		pre = p;
		p = p -> next;
	}
	delete pre;
}


//获取尾指针
CirLinkList GetPrior(CirLinkList L)
{
	CLNode* prior = L;
	while (prior->next != L)
	{	
		prior = prior->next;
	}
	return prior;
}

//合并两个循环链表
CirLinkList ConnetList(CirLinkList& L1, CirLinkList& L2)
{
	CLNode* prior1 = GetPrior(L1), * prior2 = GetPrior(L2);
	CLNode* L = prior1->next;			//保存链表1的头指针，prior1 ->next = L1,此处也可写为L = L1
	prior1->next = prior2->next->next;	//prior->next即为L2,故此处也可写为prior1->next = L2->next;
	delete L2;
	prior2->next = L;
	return L;
}