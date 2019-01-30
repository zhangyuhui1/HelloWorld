#include<stdio.h>
#include<stdlib.h>
#include"List.h"


List Intersection(List L1, List L2);
int main()
{
	int n1,n2;
	List L1,L2,L;
	printf("Please enter the number of L1,n1=");
	scanf("%d",&n1);
	L1 = CreateList(n1);
	printf("Please enter the number of L2,n2=");
	scanf("%d",&n2);
	L2 = CreateList(n2);
	printf("L1:");
	PrintList(L1);
	printf("L2:");
	PrintList(L2);
	L = Intersection(L1, L2);
	printf("The intersection of L1 and L2:");
	PrintList(L);
	return 0;
}


List Intersection(List L1, List L2)
{
	List L;
	Position P;
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
	P = malloc(sizeof(struct Node));
	if(P == NULL)
		FatalError("Out of space!!!");
	L1 = L1->Next;
	L2 = L2->Next;
	P = L;
	while(L1 != NULL && L2 != NULL){
		if(L1->Element < L2->Element)
			L1 = L1->Next;
		else if(L1->Element > L2->Element)
			L2 = L2->Next;
		else{
			Insert(L1->Element, L, P);
			L1 = L1->Next;
			L2 = L2->Next;
			P = P->Next;
		}
	}
	return L;
}	
