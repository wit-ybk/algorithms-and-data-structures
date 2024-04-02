#include "CirLinkList.h"

int main()
{
	CirLinkList L1,  L2;
	int a1[] = { 1,2,3 }, a2[] = {4,5,6};

	CreatList(L1, a1, 3);
	CreatList(L2, a2, 3);
	DispList(L1);
	DispList(L2);

	L1 = ConnetList(L1, L2);
	DispList(L1);

	DestoryList(L1);
	DestoryList(L2);
	return 0;
}