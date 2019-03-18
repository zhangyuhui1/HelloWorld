#include<stdio.h>
#include<stdlib.h>

#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void FatalError(char *str);
void Error(char *str);

#endif /*_Stack_h*/


/*Place in implementation file*/
/*Stack implementation is a linked list with a header*/

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

/*Check if the stack is empty
 */
int IsEmpty(Stack S)
{
	return S->Next == NULL;
}


Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct Node));
	if(S == NULL)
		FatalError("Out of space!!!");
	S->Next == NULL;
	MakeEmpty(S);
	return S;
}


void MakeEmpty(Stack S)
{
	if(S == NULL)
		Error("Must use CreateStack first");
	else
		while(!IsEmpty(S))
			Pop(S);
}


void Push(ElementType X,Stack S)
{
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		FatalError("Out of space!!!");
	else{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}


ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	Error("Empty stack");
	return 0; /*Return value used to avoid warning*/
}


void Pop(Stack S)
{
	PtrToNode FirstCell;
	if(IsEmpty(S))
		Error("Empty stack");
	else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}


void FatalError(char *str)
{
	printf("Fatal Error:%s\n",str);
}


void Error(char *str)
{
	printf("Error:%s\n",str);
}

