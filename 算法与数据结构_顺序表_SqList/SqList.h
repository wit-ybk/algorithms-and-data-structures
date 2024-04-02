#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;
#define MAXSIZE 50

typedef struct
{
//	ElemType data[MAXSIZE];		//��̬��������ռ�
	ElemType *data;				//��̬��������ռ�
	int length;
}SqList;

void CreateList(SqList& L, ElemType a[], int n); //����һ��˳������һ������Ԫ��
void InitList(SqList& L);						 //��ʼ�����Ա�
void DestroyList(SqList& L);					 //�������Ա�
bool ListEmpty(SqList L);						 //�ж����Ա��Ƿ�Ϊ��
int  ListLength(SqList L);						 //��ȡ���Ա���
void DispList(SqList L);						 //��ӡ���Ա�
bool GetElem(SqList L, int i, ElemType &e);	     //��λ�ò��ң������Ա��еĵ�i��Ԫ�ص�ֵ��
int  LocateElem(SqList L, ElemType e);			 //����ֵ����
bool InsertList(SqList& L, int i, ElemType e);	 //����Ԫ��
bool DeleteList(SqList& L, int i, ElemType& e);	 //ɾ��Ԫ��
void UnionList(SqList& L1, SqList L2);			 //�ϲ�����˳���������ͬԪ��ֻ����һ��
void MergeList(SqList L1, SqList L2,SqList& L3); //�����ĺϲ�