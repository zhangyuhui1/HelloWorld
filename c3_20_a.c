typedef char ElementType;
#include<stdio.h>
#include"Stack.h"
#include<string.h>

void InfixToPostfix(char* a);
int CheckPriority(char c);
ElementType Top1(Stack S);

int main()
{
	char a[50];
	printf("Please enter a infix expression:\n");
	fgets(a,50,stdin);
	printf("The postfix expression:");
	InfixToPostfix(a);
	printf("\n");
	return 0;
}

/*Chage infix expression to Postfix expression
 */
void InfixToPostfix(char* a)
{
	Stack S;
	char res[50];
	S = CreateStack();
	static int i = 0;
	int priority = 0;
	int flag = 0;
	int sum,tmp;
	char n;
	while(*a != '\n'){
		if(*a >= '0' && *a <= '9'){ //when *a is number.
			for(sum = 0; *a <= '9' && *a >= '0'; a++){
				tmp = *a - '0';
				sum = sum*10 + tmp;
			}
			printf("%d ",sum);
		}
		
		if(*a == '+' || *a == '-'){ //when *a is +/-
			if(priority < 1 || priority == 3){
				Push(*a,S);
				priority = 1;
			}else{
				while(priority >= 1 && priority != 3){
					n = Top1(S);
					Pop(S);
					printf("%c ",n);
					n = Top1(S);
					priority = CheckPriority(n);
				}
				Push(*a,S);
				priority = 1;
			}
		}
		if(*a == '*' || *a == '/'){ //when *a is *//
			if(priority < 2 || priority == 3){
				Push(*a,S);
				priority = 2;
			}else{
				while(priority >= 2 && priority != 3){
					n = Top(S);
					Pop(S);
					printf("%c ",n);
					n = Top1(S);
					priority = CheckPriority(n);
				}
				Push(*a,S);
				priority = 2;
			}
		}
		if(*a == '('){
			Push(*a,S);
			priority = 3;
		}
		if(*a == ')'){
			n = Top1(S);
			while(n != '('){
				Pop(S);
				printf("%c ",n);
				n = Top1(S);
			}
			Pop(S);
		}
		if(*a == '\n')
			break;
		a++;
		
	}
	while(!IsEmpty(S)){
		n = Top1(S);
		printf("%c ",n);
		Pop(S);
	}
}	
			
				
				
/*check the Priority of the stack top element
 */			
int CheckPriority(char c)
{
	if(c == '+' || c == '-')
		return 1;
	if(c == '*' || c == '/')
		return 2;
	if(c == '(' || c == ')')
		return 3;
	if(c == (char)0)
		return 0;
}

/*New Top function that will not output error information
 */
ElementType Top1(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	return 0;
}
