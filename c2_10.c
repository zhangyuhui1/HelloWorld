#include<stdio.h>

int main()
{
	int i,x,n;
	int a[1000];
	printf("please enter x =");
	scanf("%d",&x);
	printf("please enter n =");
	scanf("%d",&n);
	printf("please enter the value of A(i):\n");
	for(i = 0; i <= n; i++)
		scanf("%d",&a[i]);
	int poly = 0;
	for(i = n; i >= 0; i--)
		poly = x*poly+a[i];
	printf("F(X) = %d\n",poly);
	return 0;
}
