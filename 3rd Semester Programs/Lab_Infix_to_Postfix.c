#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int top = -1;
char stack[50];

void push(char e){
	stack[++top] = e;
}

char pop(){
	return stack[top--];
}

int precedence(char c){
	switch (c){
	case '#':
		return 0;
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	}
}

void main(){

	int i,j;
	char infix[50], postfix[50],ch;
	printf("Enter an Infix Expression : ");
	scanf("%s", infix);
	push('#');
	for (j=i=0; infix[i]; i++){
		ch = infix[i];
		if (isalnum(ch)){
			postfix[j++] = ch;
		}
		else if(ch==')'){
			while (stack[top] != '(')
				postfix[j++] = pop();
			pop();
		}
		else if (ch == '('){
			push(ch);
		}
		else{
			while (precedence(stack[top]) >= precedence(ch))
				postfix[j++] = pop();
			push(ch);
		}
	}
	while (top)
		postfix[j++] = pop();
	postfix[j++] = '\0';
	printf("The Postfix expression is : %s", postfix);
	_getch();
}
