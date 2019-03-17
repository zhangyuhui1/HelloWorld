#include<stdio.h>
#include"List.h"

int IsExist(int n);
int m = 0;
int a[100]; //Define an array to store elements sequentially.


int main()
{
	int n,i;
	List L;
	Position P,T;
	printf("Please enter the number of the List,n=");
	scanf("%d",&n);
	L = CreateList(n);
	PrintList(L);
	T = L->Next;
	P = L;
	while(T != NULL){
		if(IsExist(T->Element)){
			P->Next = T->Next;
			free(T);
			T = P->Next;
		}else{
			P = P->Next;
			T = T->Next;
		}
	}
	PrintList(L);
	return 0;
}


/*Determine whether the element is in the array.If so,return 1 and the 
 *element is deleted form the list;if not, return 0 and the element is 
 *added to the array.
 */
int IsExist(int n)
{
	int i;
	int Mid,Low,High;
	if(m == 0){
		a[0] = n;
		m++;
		return 0;
	}
	Low = 0;
	High = m-1;
	while(Low <= High){
		Mid = (Low+High)/2;
		if(a[Mid] < n)
			Low = Mid+1;
		else
			if(a[Mid] > n)
				High = Mid-1;
		else
			return 1;
	}
	for(i = m-1; i > Mid; i--)
		a[i+1] = a[i];
	if(a[Mid] < n)
		a[Mid+1] = n;
	else{
		a[Mid+1] = a[Mid];
		a[Mid] = n;
	}
	m++;
	return 0;
}



