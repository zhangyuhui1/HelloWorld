#include<stdlib.h>
#include<string.h>


void FatalError(char *str);
#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty(List L);
List CreateList(int n);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif	/* _List_H*/

/*Place in the implementation file*/
struct Node
{
	ElementType Element;
	Position Next;
};


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
			FatalError("create error\n");
			return L;
		}
		scanf("%d",&P->Element);
		P->Next = L->Next;
		L->Next = P;
	}
	return L;
}
		
	
		

/*Return true if L is empty*/
int IsEmpty(List L)
{
	return L->Next == NULL;
}


/*Return true if P is the last position in list L.
 *Parameter L is unused in this implementation.
 */
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}


/*Return Position of X in L; NULL if not found*/
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

/*Delete first occurrence of X form a list
 *Assume use of a heard node 
 */
void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X,L);
	if(!IsLast(P,L)){  //Assumption of header use.X is found;delete it.
		TmpCell = P->Next;
		P->Next = TmpCell->Next; //Bypass deleted cell
		free(TmpCell);
	}
}


/*If X is not found,then Next field of returned
 *Position is NULL
 *Assumes a header
 */
Position FindPrevious(ElementType X, List L)
{
	Position P;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}



/*Insert(after legal position P)
 *Header implementation assumed
 *Parameter L is unused in this implementation
 */
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL){
		FatalError("Out of space!!!");
		return;
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}


void DeleteList(List L)
{
	Position P,Tmp;
	P = L->Next;  // Hearder assumed
	L->Next = NULL;
	while(P != NULL){
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}


void FatalError(char *str)
{
	printf("%s\n",str);
}
