#include<stdio.h>



int MajorNumber(int a[],int lenth) //Find the value that are most likely be the major number.
{
	int i,j;
	if(lenth == 1)
		return a[0];
	int b[lenth/2];
	if(lenth%2 == 0){ //The number of array a is even number.
		for(i = 0,j = 0; i < lenth; i += 2)
			if(a[i] == a[i+1]){
				b[j] = a[i];
				j++;
			}
	}
	else{	//The number of array a is odd number.
		for(i = 0,j = 0; i < lenth-1; i += 2)
			if(a[i] == a[i+1]){
				b[j] = a[i];
				j++;
			}
		b[j] = a[lenth-1];
		j++;
	}
	lenth = j;
	if(j == 0)
		return 0;
	return (MajorNumber(b,lenth));
}

int main()
{
	int n,i,res,flag = 0;
	int a[100];
	printf("Please enter the number of the array n=");
	scanf("%d",&n);
	printf("Please enter the array\n");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	res = MajorNumber(a,n);
	for(i = 0; i < n; i++)	//judge the result of MajorNumber function whther MajorNumber.
		if(res == a[i])
			flag++;
	if(flag > n/2)
		printf("The major number of the array is %d.\n",res);
	else
		printf("The array have not major number.\n");
}
		
