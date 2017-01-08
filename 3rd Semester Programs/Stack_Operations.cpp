#include <stdio.h>
#include <process.h>
#define MAX 3

int stack[MAX];
int top = -1;


void pop(){
	if (top == -1)
		printf("Stack Underflow\n");
	else
		printf("Poping %d\n", stack[top--]);
}

void push(int e){

	if (top < MAX-1)
		stack[++top] = e;
	else
		printf("Stack Overflow\n");

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

	int n, ch;

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
			scanf("%d", &n);
			push(n);
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