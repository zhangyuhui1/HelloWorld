#include<stdio.h>
#include"List.h"
#include<stdlib.h>

List CreateJosephusList(int n);
int JosephusAlogithm(List L,int m, int n);

int main()
{
	int M,N,result;
	List L;
	printf("Please enter M=");
	scanf("%d",&M);
	printf("Please enter N=");
	scanf("%d",&N);
	L = CreateJosephusList(N);	
	result = JosephusAlogithm(L,M,N);
	printf("The last number is %d.\n",result);	
}

/*Create the circular linked list
 */
List CreateJosephusList(int n)
{
	int i;
	Position P,Tem;
	List L;
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
	L->Next = NULL;
	for(i = n; i > 0; i--){
		P = malloc(sizeof(struct Node));
		if(P == NULL)
			FatalError("Out of space!!!");
		P->Element = i;
		P->Next = L->Next;
		L->Next = P;
		if(i == n)
			Tem = P;
	}
	Tem->Next = L->Next;
	return L;
}	
		
/*Josephus Alogithm
 */
int JosephusAlogithm(List L,int m, int n)
{
	int i;
	int k = n;
	Position T,Tem;
	T = L->Next;
	while(n > 1){
		for(i = 0; i < m; i++)
			T = T->Next;
		Tem = FindPrevious(T->Element, L);	
		Tem->Next = T->Next;
		printf("The number %d that is deleted is %d.\n",k-n+1,T->Element);
		free(T);
		T = Tem->Next;
		L->Next = Tem;
		n--;
	}
	return Tem->Element;
}	

