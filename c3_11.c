#include<stdio.h>
#include"List.h"
#include<time.h>


Position nonRecurisive_Find(List L, ElementType Element);
Position Recurisive_Find(List L, ElementType Element);
List CreateOrderList(int n);

int main()
{
	List L;
	Position P1,P2;
	int n,i;
	int begintime,endtime;
	printf("Create a list,please enter the number of the List,N=");
	scanf("%d",&n);
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
	L = CreateOrderList(n);
	//PrintList(L);
	printf("Please enter the element you need to find,i=");
	scanf("%d",&i);
	begintime = clock();
	P1 = nonRecurisive_Find(L, i);
	endtime = clock();
	printf("P1->Element=%d\nThe runtime of nonRecurisive_Find function is %d\n",P1->Element,endtime-begintime);
	begintime = clock();
	P2 = Recurisive_Find(L, i);
	endtime = clock();
	printf("P2->Element=%d\nThe runtime of Recurisive_Find function is %d\n",P2->Element,endtime-begintime);
}


Position nonRecurisive_Find(List L, int i)
{
	List Tem;
	Tem = L;
	if(IsEmpty(L))
		printf("The list is empty\n");
	else{
		while(Tem != NULL && Tem->Element != i)
			Tem = Tem->Next;	
		if(Tem != NULL)
			return Tem;
		else{
			printf("The element is not in the list\n");
			return NULL;
		}
	}
	return NULL;
}
	
	
Position Recurisive_Find(List L, int i)
{
	List Tem;	
	if(L->Element != i && L->Next != NULL)
		return Recurisive_Find(L->Next,i);
	else if(L->Element == i)
		return L;
	else{
		printf("The element is not in the list\n");
		return NULL;
	}
}
	
/*Create an incremental list
 */
List CreateOrderList(int n)
{
	int i;
	List L;
	Position P;
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		FatalError("Out of space!!!");
	L->Next = NULL;
	for(i = n; i > 0; i--){
		P = malloc(sizeof(struct Node));
		if(P == NULL)
			FatalError("Out of space!!!\n");
		P->Element = i;
		P->Next = L->Next;
		L->Next = P;
	}
	return L;
}
