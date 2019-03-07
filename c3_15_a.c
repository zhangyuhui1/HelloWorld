#include<stdio.h>


int Find(int b,int *a);

int main()
{
	int a[100];
	int n,i,b,f,tem;
	printf("Please enter the number of array,n=");
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(i = 0; i < n; i++)
		printf("%d  ",a[i]);
	printf("Please enter the number that need find,b=");
	scanf("%d",&b);
	f = Find(b,a);
	if(f >= n){
		printf("b is not in the array\n");
		return 0;
	}
	tem = a[f];
	for(i = f; i > 0; i--)
		a[i] = a[i-1];
	a[0] = tem;
	for(i = 0; i < n; i++)
		printf("%d  ",a[i]);
	return 0;	
}

/*Find the locate of the b in the array*/
int Find(int b,int *a)
{
	int i = 0;
	while(a[i] != b)
		i++;
	return i;
}	
