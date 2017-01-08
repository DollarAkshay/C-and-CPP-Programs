#include<stdio.h>
#include<conio.h>

#define MAX 5

int queue[MAX];
int rear = -1, front = -1;

void insert();
void del();
void display();

void main(){

	int choice, run = 1;
	printf("\n~~~~~ MENU ~~~~~ \n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	while (run){
		printf("\nEnter your choice :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: 
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			display();
			break;
		case 4:
			run = 0;
			break;
		default:
			printf("Invalid Choice\n");
		}
	}
}

void insert(){

	int item;
	if (rear == MAX - 1)
		printf("\n ~~~ Queue is Full ~~~ \n");
	else{
		if (front == -1)
			front++;
		printf("\nInsert the item :");
		scanf("%d", &item);
		queue[++rear] = item;
	}

}

void del(){
	
	if (front == -1 || front>rear)
		printf("\n ~~~ Queue is Empty ~~~ \n");
	else
		printf("\nElement %d has been deleted\n",queue[front++]);
}

void display(){

	if (front == -1 || front>rear)
		printf("\n ~~~ Queue is Empty ~~~ \n");
	else{
		printf("\nElements in the queue are :");
		for (int i = front; i <= rear; i++)
			printf(" %d,", queue[i]);
		printf("\b\n");
	}
}