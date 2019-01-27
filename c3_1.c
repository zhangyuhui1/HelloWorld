#include<stdio.h>
#include "List.h"

void PrintList(List L);

int main()
{
	int n;
	List L;
	printf("please enter the number of L,n=");
	scanf("%d",&n);
	L = CreateList(n);
	PrintList(L);
	return 0;
}

void PrintList(List L)
{
	Position P;
	P = L->Next;
	while(P != NULL){
		printf("%5d",P->Element);
		P = P->Next;
	}
	printf("\n");
}
