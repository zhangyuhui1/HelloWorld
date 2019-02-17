#include<stdio.h>
#include"Polynomial.h"

Polynomial PolyPow(Polynomial Poly, int n);
Polynomial Caculate(Polynomial Poly1,Polynomial Poly2);
void RevPolynomial(Polynomial Poly);
void CarryBit(Polynomial Poly);

int main()
{	
	int total,zero,one,two,three,four,five,six,seven,eight,nine;
	total = zero = one = two = three = four = five = six = seven = eight = nine = 0;
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
	while(MultPoly->Next != NULL){
		total++;
		MultPoly = MultPoly->Next;
		switch(MultPoly->Coefficient){
			case 0:
				zero++;
				break;
			case 1:
				one++;
				break;
			case 2:
				two++;
				break;
			case 3:
				three++;
				break;
			case 4:
				four++;
				break;
			case 5:
				five++;
				break;
			case 6:
				six++;
				break;
			case 7:
				seven++;
				break;
			case 8:
				eight++;
				break;
			case 9:
				nine++;
				break;
			default:
				break;
		}
	}
//	total = zero+one+two+three+four+five+six+seven+eight+nine;
	printf("The result of 2^4000 has %d bits altogether\n",total);
	printf("Three are %d 0,the ratio of 0 is %f.\n",zero,(float)zero/total);
	printf("Three are %d 1,the ratio of 1 is %f.\n",one,(float)one/total);
	printf("Three are %d 2,the ratio of 2 is %f.\n",two,(float)two/total);
	printf("Three are %d 3,the ratio of 3 is %f.\n",three,(float)three/total);
	printf("Three are %d 4,the ratio of 4 is %f.\n",four,(float)four/total);
	printf("Three are %d 5,the ratio of 5 is %f.\n",five,(float)five/total);
	printf("Three are %d 6,the ratio of 6 is %f.\n",six,(float)six/total);
	printf("Three are %d 7,the ratio of 7 is %f.\n",seven,(float)seven/total);
	printf("Three are %d 8,the ratio of 8 is %f.\n",eight,(float)eight/total);
	printf("Three are %d 9,the ratio of 9 is %f.\n",nine,(float)nine/total);			
}


/*Computation of expoential function
 */
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

/*Multiplication of two polynomials whih coefficients greater than 10 carry
 */
Polynomial Caculate(Polynomial Poly1,Polynomial Poly2)
{
	Polynomial P,RevPoly;
	P = malloc(sizeof(struct Node));
	if(P == NULL)
		printf("Out of space!!!");
	P = MultPolynomial(Poly1,Poly2);
	RevPolynomial(P);
	CarryBit(P);
	RevPolynomial(P);
	return P;
}

/*Inversion of the Polynomials
 */
void RevPolynomial(Polynomial Poly)
{
	PtrToNode P,P1,P2,P3;
	P = Poly;
	if(Poly->Next == NULL)
		return;
	else{
		P1 = P->Next;
		P3 = P1;
		while(P1->Next !=NULL){
			P2 = P1->Next;
			P1->Next = P;
			P = P1;
			P1 = P2;
		}
		P1->Next = P;
		P3->Next = NULL;
		Poly->Next = P1;
	}
}

/*Carry fuction.While the coefficient greater than 10,carry
 */
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
	while(TemPoly->Next == NULL && TemPoly->Coefficient >= 10){ //when the maximum bit coefficient is greater than 10,a new number is created.
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
		
		



