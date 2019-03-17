#include<stdio.h>
#include"List.h"

List RevList(List L);

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
	L = RevList(L);
	PrintList(L);
	return 0;
}
	

/*Reverse the List
 */
List RevList(List L)
{
	List T;
	Position P;
	T = malloc(sizeof(struct Node));
	if(T == NULL)
		printf("Out of space!!!");
	T->Next = NULL;
	while(L->Next != NULL){
		P = malloc(sizeof(struct Node));
		if(P == NULL)
			printf("Out of space!!!");
		P->Element = L->Next->Element;
		P->Next = T->Next;
		T->Next = P;
		L = L->Next;
	}
	return T;
}
	
