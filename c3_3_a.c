#include<stdio.h>
#include"List.h"

List SingleListSwap(List L);
void PrintList(List L);
int main()
{
	int n,i;
	List L;
	n = 2;
	printf("Please enter elements of the L\n");
	L = CreateList(n);
	PrintList(L);
	L = SingleListSwap(L);
	printf("\n");
	PrintList(L);
	return 0;
}

void PrintList(List L)
{
	while(L->Next != NULL){
		L = L->Next;
		printf("%3d",L->Element);
	}
	printf("\n");
}	

List SingleListSwap(List L)
{
	Position P;
	P = L->Next;
	P = P->Next;
	P->Next = L->Next;
	L->Next = P;
	P = P->Next;
	P->Next = NULL;
	return L;
}

