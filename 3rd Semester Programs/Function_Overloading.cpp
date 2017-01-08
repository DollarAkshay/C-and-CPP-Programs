#include <iostream>
#include <conio.h>

using namespace std;

int area(int s){
	return s*s;
}

int area(float r){
	return 3.14159*r*r;
}

int main(){

	int l, h, r;
	cout << "Enter side : ";
	cin >> l;
	cout << "Area of  Square = " << area(l,);
	cout << "\n\nEnter raduis : ";
	cin >> r;
	cout << "Area of Circle = " << area(r);
	_getch();
	return 0;
}









