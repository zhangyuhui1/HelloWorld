#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int add = 0;

int RandInt(int i,int j)
{
	int x;
	++add;
	srand(time(0)+add); //Using system time puls a different constant as seed,so a large number of different random numbers can be generated in a short time.
	x = i+(rand()%(j-i+1)); //Generated random numbers between i and j.
	return x;
}

int swap(int *a,int *b) //swap a and b.
{	
	int temp = *a;
	*a = *b;
	*b = temp;
}

int fun1(int i,int j,int n) //alogrithm of 2.7(1)
{	
	int k,t,m;
	int flag;
	int a[n];
	for(k = 0; k < n; k++){
		if(k == 0)
			a[k] = RandInt(i,j);
		else{
			flag = 1;
			while(flag == 1){
				t = RandInt(i,j);
				for(m = 0; m < k; m++){
					if(t == a[m])
						break;
				if(m == k-1)
					flag = 0;
				}
			}
			a[k] = t;
		}
		printf("a[%d]=%d\n",k,a[k]);
	}
	return 0;
}

int fun2(int i,int j,int n) //algorithm of 2.7(2) 
{
	int k,t;
	int a[n];
	int used[j+1];
	for(k = 0; k < n; k++){
		t = RandInt(i,j);
		while(used[t] == 1){
			t = RandInt(i,j);
		}
		a[k] = t;
		used[t] = 1;
		printf("a[%d] = %d\n",k,a[k]);
	}
	return 0;
}


int fun3(int i,int j,int n) //algorithm of 2.7(3)
{
	int k;
	int a[j-i+1];
	for(k = 0; k < j-i+1; k++)
		a[k] = i+k;
	for(k = 0; k < n; k++)
		swap(&a[k],&a[RandInt(0,j-i)]);
	for(k = 0; k < n; k++)
		printf("a[%d] = %d\n",k,a[k]);
	return 0;
}
		

int main()
{
	int i,j,n;
	printf("please input i.\n i = ");
	scanf("%d",&i);
	printf("please input j and j >= i.\n j = ");
	scanf("%d",&j);
	printf("please input n and n <= j-i+1.\n n = ");
	scanf("%d",&n);
	if(j < i || n > j-i+1){
		printf("input error\n");
		return 0;
	}
	printf("---------------------------------algorithm1---------------------\n");
	
	fun1(i,j,n);
	printf("---------------------------------algorithm2---------------------\n");

	fun2(i,j,n);
	printf("---------------------------------algorithm3---------------------\n");
	fun3(i,j,n);
	return 0;
}

