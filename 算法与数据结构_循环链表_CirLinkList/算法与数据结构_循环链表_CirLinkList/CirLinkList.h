#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct CLNode
{
	ElemType data;
	CLNode* next;
}CLNode, *CirLinkList;

void CreatList(CirLinkList& L, ElemType a[], int n);	//������a[]����ѭ������
void DispList(CirLinkList L);							//��ӡ����
void DestoryList(CirLinkList& L);						//��������
CirLinkList GetPrior(CirLinkList L);					//��ȡβָ��
CirLinkList ConnetList(CirLinkList& L1, CirLinkList& L2);	//�ϲ�����ѭ������
