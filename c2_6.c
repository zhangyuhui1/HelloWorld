#include<stdio.h>
#include<time.h>

int sum,i,j,k;

int fun1(int n)
{
	sum = 0;
	for(i = 0; i < n; i++)
		sum++;
	return 0;
}

int fun2(int n)
{
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			sum++;
	return 0;
}

int fun3(int n)
{
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n*n; j++)
			sum++;
	return 0;
}

int fun4(int n)
{
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < i; j++)
			sum++;
	return 0;
}

int fun5(int n)
{	
	sum = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < i*i; j++)
			for(k = 0; k < j; k++)
				sum++;
	return 0;
}

int fun6(int n)
{
	sum = 0;
	for(i = 1; i < n; i++)
		for(j = 1; j < i*i; j++)
			if(j%i == 0)
				for(k = 0; k < j; k++)
					sum++;
	return 0;
}

int main()
{	
	int n;
	printf("please input n =");
	scanf("%d",&n);
	int begintime,endtime;
	begintime = clock();
	fun1(n);
	endtime = clock();
	printf("runtime = %d\n",endtime-begintime);

	begintime = clock();
	fun2(n);
	endtime = clock();
	printf("runtime = %d\n",endtime-begintime);

	begintime = clock();
	fun3(n);
 	endtime = clock();
 	printf("runtime = %d\n",endtime-begintime);
	
	begintime = clock();
	fun4(n);
	endtime = clock();
	printf("runtime = %d\n",endtime-begintime);
	
	begintime = clock();
	fun5(n);
	endtime = clock();
	printf("runtime = %d\n",endtime-begintime);

	begintime = clock();
	fun6(n);
	endtime = clock();
	printf("runtime = %d\n",endtime-begintime);
}
