#include <iostream>
#include <process.h>
#include <conio.h>

using namespace std;

struct NOD {
	int info;
	struct NOD *next;
};

typedef struct NOD node;

class LinkList {
	node *f;
public: LinkList(){
			f = NULL;
		}
		void insert(int);
		void del();
		void disp();
};

void LinkList::insert(int num){
	node *p = new node;
	p->info = num;
	p->next = f;
	f = p;
}


void LinkList::del(){
	node *temp = f;
	if (f == NULL)
		cout << "\nList is Empty\n";
	else {
		cout << "\nThe deleted element is :" << f->info<<"\n";
		f = f->next;
		delete temp;
	}
}

void LinkList::disp(){
	node *temp = f;
	if (f == NULL)
		cout << "\nList is Empty\n";
	else {
		cout << "\nThe elements in the List are :";
		while (temp != NULL){
			cout <<" "<< temp->info;
			temp = temp->next;
		}
		cout << endl;
	}
}

int main(){
	int num, ch = 1;
	LinkList list;
	cout << " ~~~~~ LINKED LIST ~~~~~ \n";
	cout << " ----- MENU ----- \n";
	cout << "1.Insert\n" << "2.Delete\n" << "3.Display\n" << "4.Exit\n";
	
	while (ch){
		cout << "\nEnter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1 : 
			cout << "Enter the element : ";
			cin >> num;
			list.insert(num);
			break;
		case 2 : 
			list.del();
			break;
		case 3 :
			list.disp();
			break;
		case 4 :
			exit(0);
		default:
			cout << "\nInvalid choice\n";
		}
	}
}

/*
Output :
-------------------------------------------
~~~~~ LINKED LIST ~~~~~
----- MENU -----
1.Insert
2.Delete
3.Display
4.Exit

Enter your choice : 1
Enter the element : 10

Enter your choice : 1
Enter the element : 20

Enter your choice : 1
Enter the element : 30

Enter your choice : 3

The elements in the List are : 30 20 10

Enter your choice : 2

The deleted element is :30

Enter your choice : 2

The deleted element is :20

Enter your choice : 2

The deleted element is :10

Enter your choice : 2

List is Empty

Enter your choice : 5

Invalid choice

Enter your choice : 4

*/

