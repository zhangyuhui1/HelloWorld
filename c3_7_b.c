#include<stdio.h>
#include"Polynomial.h"
#include<stdlib.h>

Polynomial MultPolynomial(Polynomial Poly1, Polynomial Poly2);

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
	PtrToNode P,Tem;
	Polynomial PolyMult,TemPoly,TemPoly1;
	P = malloc(sizeof(struct Node));
	if(P == NULL)
		printf("Out of space!!!");
	PolyMult = malloc(sizeof(struct Node));
	if(PolyMult == NULL)
		printf("Out of space!!!");
	PolyMult->Next = NULL;
	TemPoly = malloc(sizeof(struct Node));
	if(TemPoly == NULL)
		printf("Out of space!!!");
	TemPoly1 = malloc(sizeof(struct Node));
	if(TemPoly1 == NULL)
		printf("Out of space!!!");
	for(;Poly1->Next != NULL;){
		Poly1 = Poly1->Next;
		for(P = Poly2; P->Next != NULL;){
			P = P->Next;
			Tem = malloc(sizeof(struct Node));
			if(Tem == NULL)
				printf("Out of space!!!");
			Tem->Coefficient = Poly1->Coefficient*P->Coefficient;
			Tem->Exponent = Poly1->Exponent+P->Exponent;
			for(TemPoly = PolyMult; TemPoly != NULL;){
				TemPoly1 = TemPoly->Next;
				if(TemPoly1 != NULL && Tem->Exponent == TemPoly1->Exponent){  //if the result is in the list,only add.
					TemPoly1->Coefficient += Tem->Coefficient;
					break;
				}
				else if(TemPoly1 != NULL && Tem->Exponent < TemPoly1->Exponent){ //if the exponent of the result less than the item, check the next item of the list.
					TemPoly = TemPoly->Next;
				}
				else{  //if the exponent of the result more than the item, insert before the item.
					Tem->Next = TemPoly->Next;
					TemPoly->Next = Tem;
					break;
				}			
			}
		}
	}	
	return PolyMult;
}			
