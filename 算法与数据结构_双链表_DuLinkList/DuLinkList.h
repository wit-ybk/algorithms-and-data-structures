#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	DuLNode* prior, *next;
}DuLNode, *DuLinkList;

void CreateListF(DuLinkList& L, ElemType a[], int n);			//头插法创建双链表
void CreateListR(DuLinkList& L, ElemType a[], int n);			//尾插法创建双链表
bool InsertList(DuLinkList& L, int i, ElemType e);				//插入元素
bool DeleteList(DuLinkList& L, int i, ElemType& e);				//删除元素
void DispList(DuLinkList L);									//打印单链表

