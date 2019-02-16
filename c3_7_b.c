#include<stdio.h>
#include"Polynomial.h"
#include<stdlib.h>


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
