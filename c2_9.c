#include<stdio.h>
#include<time.h>

int IsEven(int n) //To determine whether n is odd or even.
{
	if(n%2 == 0)
		return 1;
	else
		return 0;
}

long int Pow1(long int x, unsigned int n) //algorithm of 2.9(a)
{
	int i;
	int temp = x;
	for(i = 0; i < n; i++)
		x = x*temp;
	return (x/temp);
}

long int Pow2(long int x, unsigned int n) //algorithm of 2.9(b)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return x;
	if(IsEven(n))
		return Pow2(x*x,n/2);
	else 
		return Pow2(x*x,n/2)*x;
}

int main()
{
	int n,x,res,begintime,endtime;
	printf("please input x = ");
	scanf("%d",&x);
	printf("please input n = ");
	scanf("%d",&n);
	begintime = clock();
	res = Pow1(x,n);
	endtime = clock();
	printf("the result of Pow1 is %d\nruntime = %d\n",res,endtime-begintime);
	begintime = clock();
	res = Pow2(x,n);
	endtime =clock();
	printf("the result of Pow2 is %d\nruntime = %d\n",res,endtime-begintime);
	return 0;
}
