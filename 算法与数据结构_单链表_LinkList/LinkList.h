#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode* next;
}LNode, *LinkList;

void CreatListF(LinkList& L, ElemType a[], int n);		//ͷ�巨����������
void CreatListR(LinkList& L, ElemType a[], int n);		//β�巨����������
void InitList(LinkList& L);								//��ʼ��������
void DestroyList(LinkList& L);							//���ٵ�����
bool ListEmpty(LinkList L);								//�жϵ������Ƿ�Ϊ��
int  ListLength(LinkList L);							//��ȡ������ĳ���
void DispLlist(LinkList L);								//��ӡ������
bool GetElem(LinkList L, int i, ElemType& e);			//��λ�ò���
int  LocateElem(LinkList L, ElemType e);				//��ֵ����
bool InsertList(LinkList L, int i, ElemType e);			//����Ԫ��
bool DeleteList(LinkList L, int i, ElemType& e);		//ɾ��Ԫ��
void UnionList(LinkList& L1, LinkList L2);				//�ϲ�������������ͬԪ��ֻ����һ��