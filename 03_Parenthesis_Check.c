//Name: Mir Mozin
#include <stdio.h>
#include <stdlib.h>
 
int top = -1;
char stack[50];
 
void push(char);
void pop();
void topnum();

//Main function
int main(){
	char a[50];
	printf("Enter an expression: ");
	gets(a); 
	for(int i=0; a[i]!='\0'; i++){
		if (a[i]=='(')
			push(a[i]);
		else if (a[i] == ')')
			pop();
	}
	topnum();
	return 0;
}

void push(char a){
	stack[top] = a;
	top++;
}

void pop(){
	if (top == -1){
		printf("Incorrectly parenthesized!\n");
		exit(0);
	}	
	else		
		top--;
}

void topnum(){
	if (top == -1)
		printf("Correctly parenthesized!");
	else
		printf("Incorrectly parenthesized!");
}