#include<stdio.h>
#include"Polynomial.h"

int main()
{
	Polynomial PolySum,Poly1,Poly2;
	int m,n;
	printf("M=");
	scanf("%d",&m);
	Poly1 = CreatePolynomial(m);
	printf("N=");
	scanf("%d",&n);
	Poly2 = CreatePolynomial(n);
	printf("Poly1 =");
	PrintPolynomial(Poly1);
	printf("Poly2 =");
	PrintPolynomial(Poly2);
	PolySum = AddPolynomial(Poly1,Poly2);
	printf("PolySum =");
	PrintPolynomial(PolySum);

}

