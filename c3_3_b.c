#include<stdio.h>
#include"DoublyList.h"

int main()
{
	List L;
	int n,i;
	printf("Please enter the number of L,n=");
	scanf("%d",&n);
	L = CreateList(n);
	for(i = 0; i < n; i++){
		while(L->Next != NULL){
			L = L->Next;
			printf("%3d",L->Element);
		}
	return 0;
}



