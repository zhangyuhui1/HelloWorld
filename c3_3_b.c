#include <stdio.h>
#include "DoublyList.h"

List DoublyListSwap(List L);

int main()
{
	List L;
	int n,i;
	n = 2;
	printf("Please enter the element of L\n");
	L = CreateList(n);
	PrintList(L);
	L = DoublyListSwap(L);
	PrintList(L);
	return 0;
}


List DoublyListSwap(List L)
{
	Position P;
	P = L->Next;
	P = P->Next;
	P->Next = L->Next;
	L->Next = P;
	P->Prev = L;
	P = P->Next;
	P->Prev = L->Next;
	P->Next = NULL;
	return L;
}
