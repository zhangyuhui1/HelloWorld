#include<stdio.h>
#include"Polynomial.h"
#include<stdlib.h>

Polynomial MultPolynomial(Polynomial Poly1, Polynomial Poly2);
Polynomial SortPoly(Polynomial Poly,int n);
int BinarySearch(int a[], int b, int n);
void Insert(Polynomial TemPoly, PtrToNode Tem);
int a[100];
int n = 0;
int Mid = 0;

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
	PtrToNode Tem;
	Polynomial PolyMult,P,TemPoly;
	PolyMult = malloc(sizeof(struct Node));
	if(PolyMult == NULL)
		printf("Out of space!!!");
	TemPoly = PolyMult;
	while(Poly1->Next != NULL){ 
		Poly1 = Poly1->Next;
		P = Poly2;
		while(P->Next != NULL){
			P = P->Next;
			Tem = malloc(sizeof(struct Node));
			if(Tem == NULL)
				printf("Out of space!!!");
			Tem->Coefficient = Poly1->Coefficient*P->Coefficient;
			Tem->Exponent = Poly1->Exponent+P->Exponent;
			Insert(TemPoly,Tem);
		}
	}
	return PolyMult;
}

/*Insert the Tem in the right place of PolyMult.
 */
void Insert(Polynomial TemPoly, PtrToNode Tem)
{	
	int t,i;
	PtrToNode P,P1;
	if(n == 0){  //while no have item in the PolyMUlt.
		Tem->Next = NULL;
		TemPoly->Next = Tem;
		a[0] = Tem->Exponent;
		n++;
	}else{
		t = BinarySearch(a, Tem->Exponent, n);
		P = TemPoly;
		for(i = 0; i <= Mid; i++)
			P = P->Next;
		if(t == 1){  //while the result have same exponent whit one item in the PolyMult. only add.
			P->Coefficient += Tem->Coefficient;
		}else{
			if(a[Mid] < Tem->Exponent){  //while a[Mid] less than the exponent of the result,insert before the mid.
				P1 = FindPrevious(P,TemPoly);
				Tem->Next = P1->Next;
				P1->Next = Tem;
				n++;
				for(i = n-1; i >= Mid; i--)
					a[i+1] = a[i];
				a[Mid] = Tem->Exponent;
			}else{   //while a[Mid] more than the expoent of the result ,insert after the mid.
				Tem->Next = P->Next;
				P->Next = Tem;
				n++;
				a[n-1] = Tem->Exponent;
			}
		}
	}	
						
}

/*Binaray serch
 */		
int BinarySearch(int a[], int b, int n)
{	
	int Low,High;
	int flag = 1;
	Low = 0; High = n-1;
	while(Low <= High){
		Mid = (Low+High)/2;
		if(a[Mid] < b)
			High = Mid-1;
		else if(a[Mid] > b)
			Low = Mid+1;
		else
			return flag;
	}
	flag = 0;
	return flag;
}

