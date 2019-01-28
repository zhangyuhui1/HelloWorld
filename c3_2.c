#include<stdio.h>
#include"List.h"
void PrintLots(List L, List P);

int main()
{
	List L,P;
	int n,m;
	printf("Please enter the number of list L,n=");
	scanf("%d",&n);
	L = CreateList(n);
	printf("Please enter the number of list P,m=");
	scanf("%d",&m);
	P = CreateList(m);
	PrintLots(L,P);
	return 0;
}

void PrintLots(List L,List P)
{
	int i,tem;
	tem = 0;
	P = P->Next;
	while(P != NULL){
		for(i = 0; i < P->Element-tem; i++)
			if(L->Next != NULL)
				L = L->Next;
			else
				return;
		printf("%3d",L->Element);
		P = P->Next;
		tem =tem+i;
	}
	printf("\n");
	return;
}

