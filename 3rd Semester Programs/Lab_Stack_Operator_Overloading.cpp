#include <iostream>
#include <conio.h>

using namespace std;

class Stack {
	int items[99], top, size;
public: Stack(int n){
			top = -1;
			size = n;
		}
		friend Stack operator +(Stack, int);
		friend Stack operator --(Stack);
		friend ostream& operator << (ostream&, Stack);
};

Stack operator +(Stack s, int num){
	if (s.top == s.size - 1)
		cout << "Stack is full" << endl;
	else
		s.items[++s.top] = num;
	return s;
}

Stack operator -- (Stack s){
	if (s.top == -1)
		cout << "Stack is Empty" << endl;
	else
		cout << "The deleted element is " << s.items[s.top--] << endl;
	return s;
}

ostream& operator <<(ostream& print, Stack s){
	if (s.top == -1)
		print << "Stack is Empty" << endl;
	else {
		print << "The Stack is : ";
		for (int i = s.top; i >= 0; i--)
			print << s.items[i] << " ";
		cout << endl;
	}
	return print;
}

int main(){
	int num, ch = 1, n;
	cout << "Enter the size of the stack : ";
	cin >> n;
	Stack s(n);
	cout << "\n ~~~~ STACK ~~~~ \n";
	cout << "1.Push\n";
	cout << "2.Pop\n";
	cout << "3.Display\n";
	cout << "4.Exit\n";
	while (ch){
		cout << "\nEnter your choice : ";
		cin >> ch;
		switch (ch){
		case 1:
			cout << "Enter the item : ";
			cin >> num;
			s = s + num;
			break;
		case 2:
			s = s--;
			break;
		case 3:
			cout << s;
			break;
		case 4:
			ch = 0;
			break;
		default:
			cout << "Invalid Choice\n";
			break;
		}
	}
}
