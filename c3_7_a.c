#include<stdio.h>
#include"Polynomial.h"
#include<stdlib.h>

Polynomial MultPolynomial(Polynomial Poly1, Polynomial Poly2);
Polynomial SortPoly(Polynomial Poly,int n);
void Swap(Polynomial Poly, PtrToNode P1, PtrToNode P2);
void Union(PtrToNode P1, PtrToNode P2);


int main()
{
	Polynomial PolyMult,Poly1,Poly2;
	int m,n;
	printf("Please enter the number of Poly1,M=");
	scanf("%d",&m);
	Poly1 = CreatePolynomial(m);
	printf("Please enter the number of Poly2,N=");
	scanf("%d",&n);
	Poly2 = CreatePolynomial(n);
	printf("Poly1=");
	PrintPolynomial(Poly1);
	printf("Poly2=");
	PrintPolynomial(Poly2);
	PolyMult = MultPolynomial(Poly1,Poly2);
	printf("PolyMult=");
	PrintPolynomial(PolyMult);
	return 0;
}


/*Input two polynomial Poly1 and Poly2, return the result of 
 *multiplication of two polynomials.
 */
Polynomial MultPolynomial(Polynomial Poly1, Polynomial Poly2)
{
	int n = 0; // n is the sizeof of the PolyMult.
	PtrToNode Tem;
	Polynomial PolyMult,P,TemPoly;
	PolyMult = malloc(sizeof(struct Node));
	if(PolyMult == NULL)
		printf("Out of space!!!");
	TemPoly = PolyMult;
	while(Poly1->Next != NULL){ //Insert every result at the end of Polynomial PolyMult.
		Poly1 = Poly1->Next;
		P = Poly2;
		while(P->Next != NULL){
			P = P->Next;
			Tem = malloc(sizeof(struct Node));
			if(Tem == NULL)
				printf("Out of space!!!");
			Tem->Coefficient = Poly1->Coefficient*P->Coefficient;
			Tem->Exponent = Poly1->Exponent+P->Exponent;
			Tem->Next = NULL;
			TemPoly->Next = Tem;
			TemPoly = TemPoly->Next;
			n++;
		}
	}
	PolyMult = SortPoly(PolyMult,n); //Sort the Polynomial
	return PolyMult;
}

Polynomial SortPoly(Polynomial Poly,int n)
{
	PtrToNode P;
	int i;
	for(i = 0; i < n-1; i++){
		P = Poly->Next;
		while(P->Next != NULL && P->Next != NULL){
			if(P->Exponent < P->Next->Exponent)
				Swap(Poly,P,P->Next);
			else if(P->Exponent == P->Next->Exponent)
				Union(P,P->Next);
			else
				P = P->Next;
		}
	}
	return Poly;
}


void Swap(Polynomial Poly, PtrToNode P1, PtrToNode P2)
{
	PtrToNode Tem;
	Tem = FindPrevious(P1,Poly);
	P1->Next = P2->Next;
	P2->Next = P1;
	Tem->Next = P2;
	return;
}


void Union(PtrToNode P1, PtrToNode P2)
{
	if(P1->Exponent == P2->Exponent){
		P1->Coefficient = P2->Coefficient + P1->Coefficient; 
		P1->Next = P2->Next;
		free(P2);
	}
}
				
