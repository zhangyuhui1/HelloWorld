#include<stdio.h>

int print_digit(int n)
{
	printf("%d",n);
	return 0;
}

int print_int(double n) //output integer
{
	int a;
	a = (int)n;
	if(a < 10)
		print_digit(a);
	else{
		print_int(a/10);
		print_digit(a%10);
	}
	
	return 0;
}

int print_out(double n,int accuracy)
{	
	double i,m,add;
	add =0.5;
	if(n < 0){
		printf("-");
		n = 0-n;
	}
	print_int(n);
	printf(".");
	n = n-(int)n;
	for(i = 1; i <= accuracy; i++){
		n = n*10;
	}
	n = n+add;
	print_int(n);
	printf("\n");
	return 0;
}	
	

int main()
{	
	print_out(-15.45693234,3);
	return 0;
}
