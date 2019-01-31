#include<stdio.h>
#include<stdlib.h>

#ifndef _Polynomial_H

typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;

Polynomial CreatePolynomial(int n);
Polynomial AddPolynomial(Polynomial Poly1, Polynomial Poly2);
void PrintPolynomial(Polynomial Poly);

#endif  /*_Polynomial_H*/

struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};

/*Output all element of Polynomial poly*/
void PrintPolynomial(Polynomial Poly)
{	
	int flag = 0;
	while(Poly->Next != NULL){
		Poly = Poly->Next;
		if(flag == 0)
			if(Poly->Exponent == 0)
				printf("%d",Poly->Coefficient);
			else
				printf("%dX^%d",Poly->Coefficient,Poly->Exponent);
		else
			if(Poly->Exponent == 0)
				printf("+%d",Poly->Coefficient);
			else
				printf("+%dX^%d",Poly->Coefficient,Poly->Exponent);
		flag = 1;
	}
	printf("\n");
}
/*Create polynomial with n element*/
Polynomial CreatePolynomial(int n)
{
	int i;
	Polynomial L;
	PtrToNode P;
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	for(i = 0; i < n ; i++){
		P = malloc(sizeof(struct Node));
		if(P == NULL){
			printf("create error\n");
		}
		printf("Coefficient=");
		scanf("%d",&P->Coefficient);
		printf("Exponent=");
		scanf("%d",&P->Exponent);
		P->Next = L->Next;
		L->Next = P;
	}
	return L;
}	

/*Add up two polynomials*/
Polynomial AddPolynomial(Polynomial Poly1, Polynomial Poly2)
{
	Polynomial PolySum;
	PtrToNode Tem,P;
	P = malloc(sizeof(struct Node));
	if(P == NULL)
		printf("Out of space!!!");
	P->Next = NULL;
	PolySum = malloc(sizeof(struct Node));
	if(PolySum == NULL)
		printf("Out of space!!!");
	Poly1 = Poly1->Next;
	Poly2 = Poly2->Next;
	PolySum = P;
	while(Poly1 != NULL || Poly2 != NULL){
		Tem = malloc(sizeof(struct Node));
		if(Tem == NULL)
			printf("Out of space!!!");
		if(Poly1 == NULL){
			Tem->Coefficient = Poly2->Coefficient;
			Tem->Exponent = Poly2->Exponent;
			Poly2 = Poly2->Next; 
		}else if(Poly2 == NULL){
			Tem->Coefficient = Poly1->Coefficient;
			Tem->Exponent = Poly1->Exponent;
			Poly1 = Poly1->Next;
		}else{
			if(Poly1->Exponent > Poly2->Exponent){
				Tem->Coefficient = Poly1->Coefficient;
				Tem->Exponent = Poly1->Exponent;
				Poly1 = Poly1->Next;
			}else if(Poly1->Exponent < Poly2->Exponent){
				Tem->Coefficient = Poly2->Coefficient;
				Tem->Exponent = Poly2->Exponent;
				Poly2 = Poly2->Next;
			}else{
				Tem->Coefficient = Poly1->Coefficient+Poly2->Coefficient;
				Tem->Exponent = Poly1->Exponent;
				Poly1 = Poly1->Next;
				Poly2 = Poly2->Next;
			}
		}
		Tem->Next = P->Next;
		P->Next = Tem;
		P = P->Next;
	}
	return PolySum;
		
}

