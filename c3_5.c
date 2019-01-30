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
<<<<<<< HEAD
	while(L->Next != NULL){
		L = L->Next;
		printf("%3d",L->Element);
	} 	
	printf("\n");
=======
	PrintList(L);	
	
>>>>>>> 953823cd98a1ed82d1417c5bd381f11a8437142e
}


List UnionList(List L1, List L2)
{
	List L;
<<<<<<< HEAD
	Position P;
=======
	Position P,Tem1,Tem2,Tem;
>>>>>>> 953823cd98a1ed82d1417c5bd381f11a8437142e
	P = malloc(sizeof(struct Node));
	if(P == NULL)
		FatalError("Out of space!!!");
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
<<<<<<< HEAD
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

=======
	Tem1 = malloc(sizeof(struct Node));
	if(Tem1 == NULL)
		FatalError("Out of space!!!");
	Tem2 = malloc(sizeof(struct Node));
	if(Tem2 == NULL)
		FatalError("Out of space!!!");
//	L1 = L1->Next;
//	L2 = L2->Next;
	L->Next = P;
	while(L1->Next != NULL && L2->Next != NULL){
		Tem1 = L1->Next;
		Tem2 = L2->Next;
		Tem = malloc(sizeof(struct Node));
		if(Tem == NULL)
			FatalError("Out of space!!!");
		if(Tem1->Element < Tem2->Element){
			L1 = L1->Next;
			P->Element = L1->Element;
		}
		else if(Tem1->Element > Tem2->Element){
			L2 = L2->Next;
			Insert(L2->Element, L, P);
//			P->Element = L2->Element;
		}
		else{
			L1 = L1->Next;
			L2 = L2->Next;
			Insert(L1->Element, L, P);
//			P->Element = L1->Element;
		}
		P =P->Next;
//		P->Next = Tem;
//		P = Tem;	
	}
	while(L1->Next == NULL){
		Tem = malloc(sizeof(struct Node));
		if(Tem == NULL)
			FatalError("Out of space!!!");
		L2 = L2->Next;
		Insert(L2->Element, L ,P);
//		P->Element = L2->Element;
		P = P->Next;
//		P->Next = Tem;
//		P = Tem;
	}
	while(L2->Next == NULL){
		Tem = malloc(sizeof(struct Node));
		if(Tem == NULL)
			FatalError("Out of space!!!");
		L1 = L1->Next;
//		Insert(L1->Element, L, P);

		P->Element = L1->Element;
		P =P->Next;
//		P->Next = Tem;
//		P = Tem;
	}
	return L;
}
>>>>>>> 953823cd98a1ed82d1417c5bd381f11a8437142e
