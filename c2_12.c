#include<stdio.h>


int Min3(int a,int b,int c ) //putout the min number whitin a,b and c
{
	if(a < b)
		if(a < c)
			return a;
		else
			return c;
	else if(b < c)
		return b;
	else
		return c;
}

int MinSubSum(const int a[],int left,int right) //algorith for 2.12(a)
{	
	int MinLeftSum,MinRightSum;
	int MinLeftBorderSum,MinRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	if(left == right) //base case
		if(a[left] < 0)
			return a[left];
		else
			return 0;
	Center = (left+right)/2;
	MinLeftSum = MinSubSum(a,left,Center);
	MinRightSum = MinSubSum(a,Center+1,right);
	MinLeftBorderSum = 0;
	LeftBorderSum = 0;
	for(i = Center; i >= left; i--){
		LeftBorderSum += a[i];
		if(LeftBorderSum < MinLeftBorderSum)
			MinLeftBorderSum = LeftBorderSum;
	}
	
	MinRightBorderSum = 0;
	RightBorderSum = 0;
	for(i = Center+1; i <= right; i++){
		RightBorderSum += a[i];
		if(RightBorderSum < MinRightBorderSum)
			MinRightBorderSum = RightBorderSum;
	}
	
	return Min3(MinLeftSum,MinRightSum,MinLeftBorderSum+MinRightBorderSum);
}

int MinPosSubSum(int a[],int left,int right)
{
	int MinLeftSum,MinRightSum;
	int MinLeftBorderSum,MinRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	if(left == right) //base case
		if(a[left] < 0)
			return a[left];
		else
			return 0;
	Center = (left+right)/2;
	MinLeftSum = MinSubSum(a,left,Center);
	MinRightSum = MinSubSum(a,Center+1,right);
	MinLeftBorderSum = 0;
	LeftBorderSum = 0;
	for(i = Center; i >= left; i--){
		LeftBorderSum += a[i];
		if(LeftBorderSum < MinLeftBorderSum)
			MinLeftBorderSum = LeftBorderSum;
	}
	
	MinRightBorderSum = 0;
	RightBorderSum = 0;
	for(i = Center+1; i <= right; i++){
		RightBorderSum += a[i];
		if(RightBorderSum < MinRightBorderSum)
			MinRightBorderSum = RightBorderSum;
	}
	
	return Min3(MinLeftSum,MinRightSum,MinLeftBorderSum+MinRightBorderSum);
}

int main()
{
	int a[100];
	int n,i,min,left,right;
	printf("please enter the number of the array\nn=");
	scanf("%d",&n);
	printf("please enter the array\n");
	for(i = 0; i < n; i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	left = 0;
	right = n-1;
	min = MinSubSum(a,left,right);
	printf("MinSunSum=%d\n",min);
}
