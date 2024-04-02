#include "SqStack.h"

void InitStack(SqStack*& s)
{
	s = new SqStack;
	s->top = -1;
}

void ClearStack(SqStack*& s)
{
	s->top = -1;
}

void DestroyStack(SqStack*& s)
{
	delete s;
}

bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}

int  StackLength(SqStack* s)
{
	return (s->top + 1);
}

bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize - 1)			//·ÀÖ¹Õ»Âú£¬ÉÏÒç£»
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)					//·ÀÖ¹Õ»¿Õ
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}
