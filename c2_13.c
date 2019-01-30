#include<stdio.h>
#include<math.h>
#include<time.h>


int IsPrime(int n)
{
	int i;
	if(n == 2)
		return 1;
	for(i = 2; i <= sqrt(n); i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int BinaryDigits(int n)
{
	int i = 1;
	while(n/2 != 0){
		n = n/2;
		i++;
	}
	return i;
}

int main()
{
	int n,B;
	int begintime,endtime;
	printf("Please enter the number n=");
	scanf("%d",&n);
	begintime = clock();
	if(IsPrime(n))
		printf("%d is prime.\n",n);
	else
		printf("%d isn't prime.\n",n);
	endtime = clock();
	printf("runtime = %d\n",endtime-begintime);
	B = BinaryDigits(n);
	printf("Binary digits of n is %d\n",B);
	return 0;
}
