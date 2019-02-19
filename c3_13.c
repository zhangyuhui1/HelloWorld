#include<stdio.h>

#define N 1000  //Maximum number of allowable inputs
void RadixSort(int a[],int n,int m);

int main()
{
	int n,i,m;
	int a[N];
	printf("Please enter the number of students, n=");
	scanf("%d",&n);
	printf("Please enter the social security number less than 1000 for each student:");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	printf("Please enter the number of radix sort times,m=");
	scanf("%d",&m);
	for(i = 1; i <= m; i++)
		 RadixSort(a,n,i);
	for(i = 0; i < n; i++)
		printf("%d   ",a[i]);
	return 0;
}

void RadixSort(int a[],int n,int m)
{	
	int i,k,j;
	int flag0,flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8,flag9;
	flag0 = flag1 = flag2 = flag3 = flag4 = flag5 = flag6 = flag7 =flag8 = flag9 = 0;
	int zero[n],one[n],two[n],three[n],four[n],five[n],six[n],seven[n],eight[n],nine[n];
	for(i = 0; i < n; i++){
		k = a[i];
		for(j = 1; j < m; j++)
			k = k/10;
		switch (k%10){
			case 0:
				zero[flag0] = a[i];
				flag0++;
				break;
			case 1:
				one[flag1] = a[i];
				flag1++;
				break;
			case 2:
				two[flag2] = a[i];
				flag2++;
				break;
			case 3:
				three[flag3] = a[i];
				flag3++;
				break;
			case 4:
				four[flag4] = a[i];
				flag4++;
				break;
			case 5:
				five[flag5] = a[i];
				flag5++;
				break;
			case 6:
				six[flag6] = a[i];
				flag6++;
				break;
			case 7:
				seven[flag7] = a[i];
				flag7++;
				break;
			case 8:
				eight[flag8] = a[i];
				flag8++;
				break;
			case 9:
				nine[flag9] = a[i];
				flag9++;
				break;
		}
	}
	n = 0;
	for(i = 0; i < flag0; i++)
		a[n++] = zero[i];
	for(i = 0; i < flag1; i++)
		a[n++] = one[i];
	for(i = 0; i < flag2; i++)
		a[n++] = two[i];
	for(i = 0; i < flag3; i++)
		a[n++] = three[i];
	for(i = 0; i < flag4; i++)
		a[n++] = four[i];
	for(i = 0; i < flag5; i++)
		a[n++] = five[i];
	for(i = 0; i < flag6; i++)
		a[n++] = six[i];
	for(i = 0; i < flag7; i++)
		a[n++] = seven[i];
	for(i = 0; i < flag8; i++)
		a[n++] = eight[i];
	for(i = 0; i < flag9; i++)
		a[n++] = nine[i];
}
