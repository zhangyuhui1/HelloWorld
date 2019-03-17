#include<stdio.h>
#include"List.h"

List RevList2(List L);

int main()
{
	int n;
	List L;
	printf("Please enter the number of the list,n=");
	scanf("%d",&n);
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
	L = CreateList(n);
	PrintList(L);
	L = RevList2(L);
	PrintList(L);
	return 0;
}
	

/*Reverse the List
 */
List RevList2(List L)
{
	Position P,Tem;
	if(IsEmpty(L))
		printf("The List is empty!!!\n");
	else{
		Tem = L->Next;
		P = Tem->Next;
		while(P != NULL){
			Tem->Next = P->Next;
			P->Next = L->Next;
			L->Next = P;
			P = Tem->Next;
		}
	}
	return L;
}
	
