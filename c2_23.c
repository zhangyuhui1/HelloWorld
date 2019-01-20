#include<stdio.h>

int BinarySearch(int a[],int n,int x)
{
	int low,high,mid;
	low = 0;
	high = n-1;
	mid = (low+high)/2;
	while( low <= high && x != a[mid]){
		if(x > a[mid]){
			low = mid+1;
			mid = (low + high)/2;
		}
		else if(x < a[mid]){
			high = mid-1;
			mid = (low+high)/2;
		}
	}
	if(a[mid] == x)
		return mid;
	else
		return -1;
}


int main()
{
	int n,i,x;
	int res;
	int a[100];
	printf("Please enter the number that need search n=");
	scanf("%d",&n);
	printf("Please enter the array ascend order\n");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	printf("Please enter the number that need search x=");
	scanf("%d",&x);
	res = BinarySearch(a,n,x);
	if(res != -1)
		printf("a[%d] = %d\n",res,a[res]);
	else
		printf("The number is not in the array.\n");
}
