#include<stdio.h>
#include<time.h>
int BubbleSort(int *a, int n);
int InsetSort(int *a, int n);
int main()
{
	int a[1000];
	int n,i,res;
	int begintime,endtime,runtime;
	printf("n = ");
	scanf("%d",&n);		//the number of the input
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	begintime = clock();
	res = BubbleSort(a, n);
	endtime = clock();
	runtime = endtime-begintime;
	printf("Number n/2 is %d, runtime = %d ms\n",res,runtime);
	begintime = clock();
	res = InsetSort(a, n);
	endtime = clock();
	runtime = endtime-begintime;
	printf("Number n/2 is %d, runtime = %d ms\n",res,runtime);

}

int BubbleSort(int *a, int n)
{
	int k,i,j,temp;
	k = n/2;
	for(i = 0; i < n-1; i++){    //sort in ascending order
		for(j = 0; j < n-i-1; j++){
			if(*(a+j) > *(a+j+1)){
				temp = *(a+j);
				*(a+j)= *(a+j+1);
				*(a+j+1) = temp;
			}
		}
	}
	if(n%2 == 0)
		return (*(a+k-1));	//while n is even number
	else
		return (*(a+k));	//while n is odd numbwe
}

int InsetSort(int *a, int n)
{
	int k,i,j,temp,m;
	if(n%2 == 0)
		k = n/2;	//while n is even number
	else
		k = n/2+1;	//while n is odd number
	for(i = 0; i < k-1; i++){		//sort in ascending order whthin k
		for(j = 0; j < k-i-1; j++){
			if(*(a+j) > *(a+j+1)){
				temp = *(a+j);
				*(a+j)= *(a+j+1);
				*(a+j+1) = temp;
			}
		}	
	}
	for(i = k; i < n; i++){		//Compare the numbers greater than kone by one and determine whether insertion is necessary
		if(*(a+i) < *(a+k-1)){
			for(j = 0; j < k; j++){
				if(*(a+i) < *(a+j)){
					for(m = 0; m <= k-j-1; m++)	//Push back the corresponding number
						*(a+k-1-m) = *(a+k-2-m);
					*(a+j) = *(a+i);	//inset the number in proper location
				}
			}
		}
	}
	return (*(a+k-1));
}
