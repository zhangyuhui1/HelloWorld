#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#ifndef _DoublyList_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List CreateList(int n);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif /* _DoublyList_H */

struct Node
{
	ElementType Element;
	Position Prev;
	Position Next;
}



List CreateList(int n)
{
	List L;
	Position P,TemCell;
	int i;
	L = malloc(sizeof(struct Node));
	for(i = 0; i < n; i++){
		P = malloc(sizeof(struct Node));
		if(i == 0){
			L->Next = P;
			P->Prev = L;
			scanf("%d",&P->Element);
			TemCell = P;
		}
		else{
			TemCell->Next = P;
			P->Prev = TemCell;
			scanf("%d",&P->Element);
			P->Next = NULL;
			TemCell = P;
		}
	}
	return L;
}
