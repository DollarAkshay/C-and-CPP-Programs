#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>

struct node {
	int data;
	struct node *link;
};

typedef struct node* NODE;

NODE getNewNode(){
	
	NODE temp = (NODE)malloc(sizeof(struct node));
	if (temp == NULL){
		printf("Insufficient Memory");
		exit(0);
	}
	return temp;
}

NODE push(NODE head, int ele){

	NODE temp = getNewNode();
	temp->data = ele;
	temp->link = NULL;
	if (head==NULL){
		return temp;
	}
	temp->link = head;
	return temp;

}

NODE pop(NODE head){

	NODE temp = head;
	if (head == NULL){
		printf("Stack is Empty\n");
		return head;
	}
	head = head->link;
	printf("Deleting %d\n", temp->data);
	free(temp);
	return head;

}

void display(NODE head){


	NODE temp = head;
	if (head == NULL){
		printf("Stack is Empty\n");
		return;
	}
	printf("The stack is :");
	while (temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");

}

void main(){

	NODE head = NULL;
	int n, ch;

	printf("1.Pop\n2.Push\n3.Display\n4.Exit\n");
	while (1){
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch){

		case 1:
			head = pop(head);
			break;
		case 2:
			printf("Enter item : ");
			scanf("%d", &n);
			head = push(head,n);
			break;
		case 3:
			display(head);
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid Choice\n");
		}
	}
}

