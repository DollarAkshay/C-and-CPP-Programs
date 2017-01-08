#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class complex{

	int a,b;
public: friend void disp(complex);

		complex(int x,int y){
			a = x;
			b = y;
		}
		~complex(){
			cout << "Destroying number " << a << "+ i " << b<<endl;
		}
		complex(complex &c){
			a = c.a;
			b = c.b;
		}

};

void disp(complex n){
	cout <<"\n"<<n.a << " + i " << n.b<<endl;
}


int main(){

	complex num1(10,5);

	complex num2(20,7);
	_getch();
	
}