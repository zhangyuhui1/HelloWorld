#include<stdio.h>
#include"Polynomial.h"

Polynomial PolyPow(Polynomial Poly, int n);
Polynomial Caculate(Polynomial Poly1,Polynomial Poly2);
void RevPolynomial(Polynomial Poly);
void CarryBit(Polynomial Poly);

int main()
{
	Polynomial MultPoly,Poly,TemPoly;
	Poly = malloc(sizeof(struct Node));
	if(Poly == NULL)
		printf("Out of space!!!");
	MultPoly = malloc(sizeof(struct Node));
	if(MultPoly == NULL)
		printf("Out of space!!!");
	TemPoly = malloc(sizeof(struct Node));
	if(TemPoly == NULL)
		printf("Out of space!!!");
	TemPoly->Exponent = 0;
	TemPoly->Coefficient = 2;
	TemPoly->Next = NULL;
	Poly->Next = TemPoly;
	MultPoly = PolyPow(Poly,4000);
	PrintPolynomial(MultPoly);
}




Polynomial PolyPow(Polynomial Poly, int n)
{
		
	if(n == 0)
		return NULL;
	if(n == 1)
		return Poly;
	if(n%2 == 0)
		return PolyPow(Caculate(Poly,Poly),n/2);
	else
		return Caculate(PolyPow(Caculate(Poly,Poly),n/2),Poly);
}


Polynomial Caculate(Polynomial Poly1,Polynomial Poly2)
{
	Polynomial MultPoly,RevPoly;
	MultPoly = malloc(sizeof(struct Node));
	if(MultPoly == NULL)
		printf("Out of space!!!");
	MultPoly = MultPolynomial(Poly1,Poly2);
	RevPolynomial(MultPoly);
	CarryBit(MultPoly);
	RevPolynomial(MultPoly);
	return MultPoly;
}


void RevPolynomial(Polynomial Poly)
{
	PtrToNode P,P1,P2;
	P = Poly;
	if(Poly->Next == NULL)
		return;
	else{
		P1 = P->Next;
		while(P1->Next !=NULL){
			P2 = P1->Next;
			P1->Next = P;
			P = P1;
			P1 = P2;
		}
		P1->Next = P;
		Poly = NULL;
		Poly->Next = P1;
	}
}

void CarryBit(Polynomial Poly)
{
	int n = 0;
	Polynomial TemPoly;
	PtrToNode Tem;
	TemPoly = Poly->Next;
	while(TemPoly->Next != NULL){
		n = TemPoly->Coefficient/10;
		TemPoly->Coefficient = TemPoly->Coefficient%10;
		TemPoly = TemPoly->Next;
		TemPoly->Coefficient += n;
	}
	while(TemPoly->Next == NULL && TemPoly->Coefficient >= 10){
		n = TemPoly->Coefficient/10;
		TemPoly->Coefficient = TemPoly->Coefficient%10;
		Tem =malloc(sizeof(struct Node));
		if(Tem == NULL)
			printf("Out of space!!!");
		Tem->Coefficient = n;
		Tem->Exponent = TemPoly->Exponent+1;
		Tem->Next = NULL;
		TemPoly->Next = Tem;
		TemPoly = TemPoly->Next;
	}
}		
		
		



