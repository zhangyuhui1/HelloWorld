#include<stdio.h>
#include<math.h>

int AllPrime(int n)
{
	int i,j,t;
	int a[n-1];
	for(i = 0; i < n-1; i++)
		a[i] = i+2;
	for(i = 0; a[i] < n; i++){
		if(a[i] != 0){
			printf("%d\n",a[i]);
			if(a[i] <= sqrt(n))
				for(j = 2; j*a[i] <= n; j++){
					t = j*a[i];
					a[t-2] = 0;
				}
		}
	}
	return 0;
}

int main()
{
	int n;
	printf("Please enter the n=");
	scanf("%d",&n);
	AllPrime(n);
	return 0;
}
