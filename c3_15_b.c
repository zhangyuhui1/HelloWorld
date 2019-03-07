#include<stdio.h>
#include"List.h"


int main()
{
	List L;
	Position P,T;
	int n,a;
	printf("Please enter the number of the list,n=");
	scanf("%d",&n);
	L = CreateList(n);
	PrintList(L);
	printf("Please enter the number that need find,a=");
	scanf("%d",&a);
	T = Find(a,L);
	if(T == NULL){
		printf("a is not in the list\n");
		return 0;
	}
	P = FindPrevious(a,L);
	P->Next = T->Next;
	T->Next = L->Next;
	L->Next = T;
	PrintList(L);
	return 0;
}
	
