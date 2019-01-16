#include<stdio.h>

int dichotomy(int a[],int lenth,int num)
{
	int low,high,middle;
	low = 0;
	high = lenth-1;
	middle = (low+high)/2;
	while(low < high){
		if(num < a[middle] && high != middle){
			high = middle;
			middle = (low+high)/2;
		}
		else if(num > a[middle] && low != middle){
			low = middle;
			middle = (low+high+1)/2;
		}
		else if(num == a[middle])
			return middle;
		else
			return -1;
	}
	return -1;
}
		

int main()
{
	int a[11] = {2,4,6,8,10,12,14,16,18,20,22};
	int num,n,lenth;
	printf("Please enter the number you need to find:");
	scanf("%d",&num);
	lenth = sizeof(a)/sizeof(a[0]);
	n = dichotomy(a,lenth,num);
	if(n != -1)
		printf("a[%d] = %d\n",n,a[n]);
	else
		printf("the number is not in array a.\n");
	return 0;
}
