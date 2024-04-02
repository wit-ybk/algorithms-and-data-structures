#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DuLNode
{
	ElemType data;
	DuLNode* prior, *next;
}DuLNode, *DuLinkList;

void CreateListF(DuLinkList& L, ElemType a[], int n);			//ͷ�巨����˫����
void CreateListR(DuLinkList& L, ElemType a[], int n);			//β�巨����˫����
bool InsertList(DuLinkList& L, int i, ElemType e);				//����Ԫ��
bool DeleteList(DuLinkList& L, int i, ElemType& e);				//ɾ��Ԫ��
void DispList(DuLinkList L);									//��ӡ������

