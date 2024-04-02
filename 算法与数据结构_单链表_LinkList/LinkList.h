#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode* next;
}LNode, *LinkList;

void CreatListF(LinkList& L, ElemType a[], int n);		//头插法创建单链表
void CreatListR(LinkList& L, ElemType a[], int n);		//尾插法创建单链表
void InitList(LinkList& L);								//初始化单链表
void DestroyList(LinkList& L);							//销毁单链表
bool ListEmpty(LinkList L);								//判断单链表是否为空
int  ListLength(LinkList L);							//获取单链表的长度
void DispLlist(LinkList L);								//打印单链表
bool GetElem(LinkList L, int i, ElemType& e);			//按位置查找
int  LocateElem(LinkList L, ElemType e);				//按值查找
bool InsertList(LinkList L, int i, ElemType e);			//插入元素
bool DeleteList(LinkList L, int i, ElemType& e);		//删除元素
void UnionList(LinkList& L1, LinkList L2);				//合并两个单链表，相同元素只保留一个