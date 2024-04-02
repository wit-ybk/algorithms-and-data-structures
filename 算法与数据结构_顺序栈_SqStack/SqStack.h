#pragma once
#include <iostream>

using namespace std;

typedef int ElemType;
#define MaxSize 10

typedef struct 
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack*& s);
void ClearStack(SqStack*& s);
void DestroyStack(SqStack*& s);
bool StackEmpty(SqStack* s);
int  StackLength(SqStack* s);
bool Push(SqStack*& s, ElemType e);			//	��ջ
bool Pop(SqStack*& s, ElemType& e);			//	��ջ
bool GetTop(SqStack* s, ElemType& e);		//	��ȡջ��Ԫ��




