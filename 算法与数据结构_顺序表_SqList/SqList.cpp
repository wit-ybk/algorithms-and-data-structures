#include "SqList.h"

//创建顺序表，存放一个数组元素
void CreateList(SqList& L, ElemType a[], int n)	
{
//	L = (SqList*)malloc(sizeof(SqList));
	L.data = new ElemType[MAXSIZE];
	L.length = 0;
	for (int i = 0; i < n; ++i)
	{
		L.data[i] = a[i];
		L.length++;
	}
}

//初始化线性表
void InitList(SqList& L)
{
	L.data = new ElemType[MAXSIZE];
	L.length = 0;
}

//销毁线性表
void DestroyList(SqList& L)
{
//	free(L);									//当main()函数中创建的时线性表指针SqList*L，可直接释放L
	delete  L.data;
	L.data = nullptr;
//	cout << &L.data << endl;					//测试内存空间是否释放成功
}


//判断线性表是否为空
bool ListEmpty(SqList L)
{
	return (L.length == 0);
}

//获取线性表长度
int ListLength(SqList L)
{
	return (L.length);
}

 //打印线性表
void DispList(SqList L)
{
	for (int i = 0; i < L.length; ++i)
		cout << L.data[i] << " ";
	cout << endl;
//	cout << &L.data << endl;
}

//按位置查找（求线性表中的第i个元素的值）
bool GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length)
		return false;
	e = L.data[i - 1];
	return true;
}

//按数值查找
int  LocateElem(SqList L, ElemType e)
{
	int i = 0;
	while ( L.data[i] != e && i < L.length)
	{
		++i;
	}
	if (i >= L.length) return 0;
	else return i+1;
}

//插入元素
bool InsertList(SqList& L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1 || L.length == MAXSIZE)	
		return false;
	for (int j = L.length ; j >= i; --j)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//删除元素
bool DeleteList(SqList& L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) return false;
	e = L.data[i - 1];
	for (int j = i - 1; j < L.length - 1; ++j)
	{
		L.data[j] = L.data[j + 1];
	}
	L.length--;
	return true;
}


//合并两个顺序表，相同元素只保存一个
void UnionList(SqList& L1, SqList L2)
{
	for (int i = 1; i <= L2.length; ++i)
	{
		ElemType e;
		GetElem(L2, i, e);
		if (!LocateElem(L1, e))
			InsertList(L1, L1.length+1, e);
	}
}

//有序表的合并
void MergeList(SqList L1, SqList L2, SqList& L3)
{
	ElemType* p1 = L1.data, *p2 = L2.data;
	ElemType* p1_last = &L1.data[L1.length - 1], * p2_last = &L1.data[L1.length - 1];
	InitList(L3);
	int i = 0;
	while (p1 <= p1_last && p2 <= p2_last)
	{
		if (*p1 <= *p2)
		{
			L3.data[i] = *p1;
			++p1;
			++i;
		}
		else
		{
			L3.data[i] = *p2;
			++p2;
			++i;
		}
	}

	while (p1 <= p1_last)
	{
		L3.data[i] = *p1;
		++p1;
		++i;
	}

	while (p2 <= p2_last)
	{
		L3.data[i] = *p2;
		++p2;
		++i;
	}

	L3.length = i;
}