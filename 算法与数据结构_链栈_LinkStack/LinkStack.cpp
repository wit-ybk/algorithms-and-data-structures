#include "LinkStack.h"

void InitStack(LinkStack& s)
{
	s = NULL;
}
void DestroyStack(LinkStack& s)
{
	StackNode* pre = s, * p ;
	while (pre)
	{
		p = pre;
		pre = pre->next;
		delete p;
	}
}
bool StackEmpty(LinkStack s)
{
	return (s == NULL);
}

int  StackLength(LinkStack s)
{
	int len = 0;
	StackNode* p = s;
	while (p!= NULL)
	{
		++len;
		p = p->next;
	}
	return len;
}

//	ÈëÕ»
void Push(LinkStack& s, ElemType e)
{
	StackNode* newNode = new StackNode;
	newNode->data = e;
	newNode->next = s;
	s = newNode;
}

//	³öÕ»
bool Pop(LinkStack& s, ElemType& e)
{
	if (s == NULL)
		return false;
	e = s->data;
	StackNode* p = s;
	s = s->next;
	delete p;
	return true;
}

bool  GetTop(LinkStack s, ElemType& e)
{
	if (s == NULL)
		return false;
	e = s->data;
	return true;
}