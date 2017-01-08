#include <iostream>
#include <conio.h>

using namespace std;

class loc{

	int lat, lon;

public: loc(){}

		loc(int x, int y){
			lat = x;
			lon = y;
		}

		friend loc operator+(loc l1,loc l2){
			loc temp;
			temp.lat = l1.lat + l2.lat;
			temp.lon = l1.lon + l2.lon;
			return temp;
		}

		void show(){
			cout << lat << " " << lon<<endl;
		}
};

int main(){

	loc ob1(10, 20), ob2(5, 30);
	loc ob3 = ob2 + ob1;
	ob1.show();
	ob2.show();
	ob3.show();
	_getch();
	return 0;
}

/*

Output :
-----------------
10 20
5 30
15 50

*/









