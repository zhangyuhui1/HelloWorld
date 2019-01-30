#include<stdio.h>
int MinSubSum(int[],int,int);
int MinPosSubSum(int[],int);

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

int Max3(int a,int b,int c)
{
	if(a > b)
		if(a >c)
			return a;
		else
			return c;
	else if(b < c)
		return c;
	else
		return b;
}


int MinSubSum(int a[],int left,int right) //algorithm for 2.12(a)
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


int MinPosSubSum(int a[],int n) //algorith for 2.12(b)
{	
	int i,k,sum,j,ThisSum;
	for(i = 0; i < n; i++){
		if(a[i] > 0){
			sum = a[i];
			break;
		}
		if(i == n-1){
			printf("There isn't postive number in the array\n");
			return 0;
		}
	}
	for (i = 0; i < n; i++)
		for(j = i; j < n; j++){
			ThisSum = 0;
			for(k = i; k <= j; k++)
				ThisSum += a[k];
			if(ThisSum < sum && ThisSum > 0)
				sum =ThisSum;
		}
	return sum;		
}

int MaxSubMul(int a[],int n) //algorithm for 2.13(c)
{
	int i,t,max;
	int p = a[0];
	int maxp = a[0];
	int minp = a[0];
	for(i = 1; i < n; i++){
		t = maxp;
		maxp = Max3(maxp*a[i],a[i],minp*a[i]);
		minp = Min3(t*a[i],a[i],minp*a[i]);
		if(maxp > minp)
			p = maxp;
		else
			p = minp;
	}
	return p;
}	
int main()
{
	int a[100];
	int n,i,min,left,right,max;
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
	printf("MinSubSum=%d\n",min);
	min = MinPosSubSum(a,n);
	printf("MinPosSubSum=%d\n",min);
	max = MaxSubMul(a,n);
	printf("MaxSubMul=%d\n",max);
}
