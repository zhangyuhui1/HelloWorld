#include<stdio.h>

int Pow(int x,int n)
{
	int i,j;
	int t1 = x,t2 = n;
	int a[100];
	for(i = 0; n/2 > 0; n = n/2){
		if(n%2 == 0)   //while n is even number.
			x = x*x;
		else{		//while n is odd number.
			a[i] = x;
			x = x*x;
			i++;
		}
	}
	for(j = 0; j < i; j++)
		x = x*a[j];
	printf("%d^%d=%d\n",t1,t2,x);
	return 0;	
}


int main()
{
	int x,n;
	printf("please enter base number x=");
	scanf("%d",&x);
	printf("please enter index number n=");
	scanf("%d",&n);
	Pow(x,n);
	return 0;
}
