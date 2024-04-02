#include "CirLinkList.h"

//������a[]����ѭ������(β�巨)
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

//��ӡ����
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

//��������
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


//��ȡβָ��
CirLinkList GetPrior(CirLinkList L)
{
	CLNode* prior = L;
	while (prior->next != L)
	{	
		prior = prior->next;
	}
	return prior;
}

//�ϲ�����ѭ������
CirLinkList ConnetList(CirLinkList& L1, CirLinkList& L2)
{
	CLNode* prior1 = GetPrior(L1), * prior2 = GetPrior(L2);
	CLNode* L = prior1->next;			//��������1��ͷָ�룬prior1 ->next = L1,�˴�Ҳ��дΪL = L1
	prior1->next = prior2->next->next;	//prior->next��ΪL2,�ʴ˴�Ҳ��дΪprior1->next = L2->next;
	delete L2;
	prior2->next = L;
	return L;
}