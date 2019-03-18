typedef int ElementType;
#include<stdio.h>
#include"Stack.h"
#include<string.h>


int Compute(char* a);


int main()
{
	int res;
	char a[100];
	printf("Please enter a postfix expression:\n");
	fgets(a,100,stdin); //The scanf function takes a space as the terminator of a string.So,must use the fgets function.
	res = Compute(a);
	printf("The result of the postfix expression is %d.\n",res);
	return 0;
}


/*Compute the value of a postfix expression.
 */
int Compute(char* a)
{
	Stack S;
	int sum,n1,n2,Tmp,res;
	S = CreateStack();
	while(*a != '\n'){ //'\n' as input terminators for strings.
		if(*a >= '0' && *a <= '9'){
			for(sum = 0;*a != ' '; a++){  //Spaces are the basis for judging a complete number
				Tmp = *a - '0';
				sum = sum*10 + Tmp;
			}
			Push(sum,S);
		}
		if(*a == '+' || *a == '-' || *a == '*' || *a == '/'){
			n1 = Top(S);
			if(!IsEmpty(S))
				Pop(S);
			else{
				Error("Please enter a valid postfix expression!!!");
				return 0;
			}
			n2 = Top(S);
			if(!IsEmpty(S))
				Pop(S);
			else{
				Error("Please enter a valid postfix expression!!!");
				 return 0;
			}
			switch(*a){
				case '+':
					Tmp = n1+n2;
					break;
				case '-':
					Tmp = n2-n1;
					break;
				case '*':
					Tmp = n1*n2;
					break;
				case '/':
					Tmp = n2/n1;
					break;
			}
			Push(Tmp,S);
		}
		a++;
	}
	res = Top(S);
	Pop(S);
	if(!IsEmpty(S)){
		Error("Please enter a valid postfix expression!!!");
		return 0;
	}
	return res;
}
