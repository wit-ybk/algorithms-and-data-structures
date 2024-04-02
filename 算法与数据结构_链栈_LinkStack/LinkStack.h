#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct StackNode
{
	ElemType data;
	StackNode* next;
}StackNode, * LinkStack;

void InitStack(LinkStack& s);
void DestroyStack(LinkStack& s);
bool StackEmpty(LinkStack s);
int  StackLength(LinkStack s);
void Push(LinkStack& s, ElemType e);			//	��ջ
bool Pop(LinkStack& s, ElemType& e);			//	��ջ
bool GetTop(LinkStack s, ElemType& e);