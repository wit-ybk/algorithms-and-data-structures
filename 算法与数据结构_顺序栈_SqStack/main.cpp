#include "SqStack.h"


int main()
{
	SqStack* s;
	InitStack(s);
	for (int i = 1; i <= 5; ++ i)
	{
		Push(s,i);
	}

	if(!StackEmpty(s))
		cout << StackLength(s) << endl;

	ElemType e;
	Pop(s, e);
	cout << e << endl 
		 << StackLength(s) << endl;

	if (GetTop(s, e))
		cout << e  << endl;

	ClearStack(s);

	cout << StackLength(s) << endl;
	DestroyStack(s);	
	return 0;
}