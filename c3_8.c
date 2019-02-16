#include<stdio.h>
#include"Polynomial.h"
#include<stdlib.h>

Polynomial PolyPow(Polynomial Poly, int P);

int main()
{
	int P,n;
	Polynomial Poly,MultPoly;
	Poly = malloc(sizeof(struct Node));
	if(Poly == NULL)
		printf("Out of space!!!");
	printf("Please enter the number of Polynomial,n=");
	scanf("%d",&n);
	Poly = CreatePolynomial(n);
	printf("F(X)=");
	PrintPolynomial(Poly);
	printf("Please enter P=");
	scanf("%d",&P);
	MultPoly = PolyPow(Poly,P);
	if(MultPoly == NULL)
		printf("(F(X))^P = 1");
	else{
		printf("(F(X))^P=");
		PrintPolynomial(MultPoly);
	}
	return 0;
}
	

Polynomial PolyPow(Polynomial Poly, int P)
{
	if(P == 0)
		return NULL;
	if(P == 1)
		return Poly;
	if(P%2 == 0)
		return PolyPow(MultPolynomial(Poly,Poly),P/2);
	else
		return MultPolynomial(PolyPow(MultPolynomial(Poly,Poly),P/2),Poly);
}
