#include<stdio.h>
#include<stdlib.h>


struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node{
	ElementType Element;
	Position Next;
	ElementType Bit;
};


void LazyDeletion(int n,List L);
void PrintList(List L);
List CreateList(int n);

int main()
{
	List L;
	int n,a;
	printf("Please enter the number of the List,n=");
	scanf("%d",&n);
	L = CreateList(n);
	PrintList(L);
	printf("Please enter the elements of the list that should be deleted.when the input is -1,the input ends.\n");
	while(a != -1){
		scanf("%d",&a);
	  	LazyDeletion(a,L);
		printf("List L:");
		PrintList(L);
	}
	return 0;
}


void LazyDeletion(int n,List L)
{
	static int k = 0;
	int i = 0;
	int lenth = 0;
	Position P,T;
	P = L->Next;
	T = L;
	while(P != NULL){
		if(P->Element == n && P->Bit != 1){
			P->Bit = 1;
			k++;
			break;
		}else{
			i++;
			P = P->Next;
		}
	}
	while(T->Next != NULL){
		T = T->Next;
		lenth++;
	}
	if(lenth < 1){
		printf("The List is empty.\n");
		return;
	}
	if(k > lenth/2){
		T = L;
		P = L->Next;
		while(P != NULL){
			if(P->Bit == 1){
				T->Next = P->Next;
				free(P);
				P = T->Next;
			}else{
				T = P;
				P = P->Next;	
			}
		}
	}
	return;					
}

/*Create a List with n element*/
List CreateList(int n)
{
	int i;
	List L;
	Position P;
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	for(i = 0; i < n ; i++){
		P = malloc(sizeof(struct Node));
		if(P == NULL){
			printf("create error\n");
			return L;
		}
		scanf("%d",&P->Element);
		P->Bit = 0;
		P->Next = L->Next;
		L->Next = P;
	}
	return L;
}

/*Output all element of the list*/
void PrintList(List L)
{
	while(L->Next != NULL){
		L = L->Next;
		printf("%3d",L->Element);
	}
	printf("\n");
}

