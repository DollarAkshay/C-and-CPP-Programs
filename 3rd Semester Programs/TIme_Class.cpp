#include<iostream>
#include<conio.h>

using namespace std;

class TIME{
	int ss, mm, hh;

public: TIME(){} // Default Empty Constructor

		TIME(int s,int m,int h){  // Constructor with Parameters
			ss = s;
			mm = m;
			hh = h;
		}

		void read(){
			cout << "Enter hours :";
			cin >> hh;
			cout << "Enter minutes :";
			cin >> mm;
			cout << "Enter seconds :";
			cin >> ss;
		}

		void display(){
			cout <<"Time is : " << hh << ":" << mm << ":" << ss << endl<<endl;
		}

		void addseconds(int n){ // Function that adds n seconds to teh time object calling it
			ss += n;
			mm += ss / 60;
			hh += mm / 60;
			ss %= 60;
			mm %= 60;
			hh %= 24;
		}

		friend TIME add2Times(TIME t1, TIME t2); // Function that adds 2 time objects and returns a 3rd one
			
};


TIME add2Times(TIME t1, TIME t2){ 
	TIME t3;
	t3.ss = t1.ss + t2.ss;
	t3.mm = t1.mm + t2.mm + t3.ss / 60;
	t3.hh = t1.hh + t2.hh + t3.mm / 60 + t3.ss / 3600;
	t3.ss %= 60;
	t3.mm %= 60;
	t3.hh %= 24;
	return t3;
}

int main(){

	TIME t1, t2, t3;
	
	// Read and Display t1
	t1.read();
	t1.display();

	// Read and Display t2
	t2.read();
	t2.display();

	// Adding t1 and t2 and storing it in t3
	t3 = add2Times(t1, t2);

	// Adding 500 seconds to t1 i.e Adding 8 min and 20 seconds and displaying it
	t1.addseconds(500);
	t1.display();

	// Adding 1 second to t2
	t2.addseconds(1);
	t2.display();

	_getch();

}


/* Output :
--------------------
Enter hours :5
Enter minutes :30
Enter seconds :25
Time is : 5:30:25

Enter hours :12
Enter minutes :59
Enter seconds :59
Time is : 12:59:59

Time is : 5:38:45

Time is : 13:0:0
*/