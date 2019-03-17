#include<stdio.h>

void Delete(int* a,int j,int n);
void PrintAll(int* a, int n);

int main()
{
	int A[100];
	int n,i,j;
	int LastPosition;
	printf("Please enter the number of the array,n=");
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&A[i]);
	PrintAll(A,n);
	LastPosition = n-1;
	for(i = 0; i < LastPosition; i++){
		j = i+1;
		while(j < LastPosition)
			if(A[i] == A[j]){
				Delete(A,j,n);
				n--;
				LastPosition--;
			}else
				j++;
	}
	PrintAll(A,n);
	return 0;
}

/*Print all element in the array
 */
void PrintAll(int* a,int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d   ",a[i]);
	printf("\n");
}

/*Delete a element in the array
 */
void Delete(int *a, int j,int n)
{
	while(j < n){
		a[j] = a[j+1];
		j++;
	}
}
