#include <stdio.h>
#include <stdlib.h>
#include <process.h>

int *stack;
int top = -1;
int size = 0;

void pop(){
	if (top == -1)
		printf("Stack Underflow\n");
	else
		printf("Poping %d\n", stack[top--]);
}

void push(int e){

	if (top == size - 1){
		printf("Stack Overflow.Increasing stack size\n");
		stack = (int*)realloc(stack,++size*sizeof(int));
	}
	stack[++top] = e;
}

void display(){
	
	int i;
	if (top == -1)
		printf("Stack is empty\n");
	else{
		printf("The Stack is : ");
		for (i = 0; i <= top;)
			printf("%d ",stack[i++]);
		printf("\n");
	}
}

void main(){

	int e, ch;

	stack = (int*)malloc(++size*sizeof(int));

	printf("1.Pop\n2.Push\n3.Display\n4.Exit\n");

	while (1){
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch){

		case 1:
			pop();
			break;
		case 2:
			printf("Enter item : ");
			scanf("%d", &e);
			push(e);
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid Choice\n");
		}
	}
}