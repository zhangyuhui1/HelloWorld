#include<stdio.h>
#include<string.h>
#include"Stack.h"

void CheckBalanceSign(char* str);

int main()
{
	char str[100];
	printf("Please enter a string:\n");
	scanf("%s",str);
	CheckBalanceSign(str);
	return 0;
}
	

void CheckBalanceSign(char* str)
{
	Stack S;
	char Tmp;
	S = CreateStack();	
	while(*str != '\0'){
		if(*str == '/'){
			Tmp = *str;
			if(*(++str) == '*'){
				Push(Tmp,S);
				Push(*str,S);
			}
		}
		if(*str == '(' || *str == '[' || *str == '{')
			Push(*str,S);
		if(*str == '*' && *(++str) == '/')
			if(S->Next != NULL && S->Next->Next != NULL && S->Next->Element == '*' && S->Next->Next->Element == '/'){
				Pop(S);
				Pop(S);
			}
			else{
				Error("Miss '/*' or '*/'");
				return;
			}
		if(*str == ')')
			if(S->Next != NULL &&S->Next->Element == '(')
				Pop(S);
			else{
				Error("Miss '(' or ')'");
				return;
			}
		if(*str == ']')
			if(S->Next != NULL && S->Next->Element == '[')
				Pop(S);
			else{
				Error("Miss '[' or ']'");
				return;
			}
		if(*str == '}')
			if(S->Next != NULL &&S->Next->Element == '{')
				Pop(S);
			else{
				Error("Miss '{' or '}'");
				return;
			}
		str++;
	}
	if(!IsEmpty(S))
		switch (S->Next->Element){
			case '*':
				Error("Miss '/*' or '*/'");
				break;
			case '(':
				Error("Miss '(' or ')'");
				break;
			case '[':
				Error("Miss '[' or ']'");
				break;
			case '{':
				Error("MIss '{' or '}'");
				break;		
		}
}		
