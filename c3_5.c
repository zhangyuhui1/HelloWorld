#include<stdio.h>
#include"List.h"
#include<stdlib.h>
List UnionList(List L1, List L2);

int main()
{
	List L1,L2,L;
	int n1,n2,n;
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
	L = UnionList(L1,L2);
	printf("The union of L1 and L2:");
	while(L->Next != NULL){
		L = L->Next;
		printf("%3d",L->Element);
	} 	
	printf("\n");
}


List UnionList(List L1, List L2)
{
	List L;
	Position P;
	P = malloc(sizeof(struct Node));
	if(P == NULL)
		FatalError("Out of space!!!");
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
	L1 = L1->Next;
	L2 = L2->Next;
	P = L;
	while(L1!= NULL || L2!= NULL){
		if(L1 == NULL){
			Insert(L2->Element, L ,P);
			L2 = L2->Next;
		}
		else if(L2 == NULL){
			Insert(L1->Element, L, P);
			L1 = L1->Next;
		}else{
			if(L1->Element < L2->Element){
				Insert(L1->Element, L, P);
				L1 = L1->Next;
			}
			else if(L1->Element > L2->Element){
				Insert(L2->Element, L, P);
				L2 = L2->Next;
			}	
			else{
				Insert(L1->Element, L, P);
				L1 = L1->Next;
				L2 = L2->Next;
			}
		}
		P = P->Next;	
	}
	return L;
}

