#include<stdio.h>
#include"List.h"



int main()
{
	List L;
	int n,i;
	Position P,T,F;
	printf("Please enter the number of the list,n=");
	scanf("%d",&n);
	L = CreateList(n);
	PrintList(L);
	T = L->Next;
	while(T->Next != NULL){
		P = T->Next;
		F = T;
		while(P != NULL){
			if(T->Element == P->Element){
				F->Next = P->Next;
				free(P);
				P = F->Next;
			}else{
				F = P;
				P = P->Next;
			}
		}
	T = T->Next;
	}
	PrintList(L);
	return 0;
}
