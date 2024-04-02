#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
#define MAXSIZE 50

typedef struct
{
//	ElemType data[MAXSIZE];		//静态分配数组空间
	ElemType *data;				//动态分配数组空间
	int length;
}SqList;

void CreateList(SqList& L, ElemType a[], int n); //创建一个顺序表，存放一个数组元素
void InitList(SqList& L);						 //初始化线性表
void DestroyList(SqList& L);					 //销毁线性表
bool ListEmpty(SqList L);						 //判断线性表是否为空
int  ListLength(SqList L);						 //获取线性表长度
void DispList(SqList L);						 //打印线性表
bool GetElem(SqList L, int i, ElemType &e);	     //按位置查找（求线性表中的第i个元素的值）
int  LocateElem(SqList L, ElemType e);			 //按数值查找
bool InsertList(SqList& L, int i, ElemType e);	 //插入元素
bool DeleteList(SqList& L, int i, ElemType& e);	 //删除元素
void UnionList(SqList& L1, SqList L2);			 //合并两个顺序表，两表相同元素只保存一个
void MergeList(SqList L1, SqList L2,SqList& L3); //有序表的合并