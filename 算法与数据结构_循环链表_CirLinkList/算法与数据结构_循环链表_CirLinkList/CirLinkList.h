#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct CLNode
{
	ElemType data;
	CLNode* next;
}CLNode, *CirLinkList;

void CreatList(CirLinkList& L, ElemType a[], int n);	//用数组a[]创建循环链表
void DispList(CirLinkList L);							//打印链表
void DestoryList(CirLinkList& L);						//销毁链表
CirLinkList GetPrior(CirLinkList L);					//获取尾指针
CirLinkList ConnetList(CirLinkList& L1, CirLinkList& L2);	//合并两个循环链表
