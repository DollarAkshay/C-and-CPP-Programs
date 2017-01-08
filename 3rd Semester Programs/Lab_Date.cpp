#include <iostream>
#include <conio.h>

using namespace std;

int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };
int b[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };

class date {
	int dd, mm, yy, day;
public: date(int d, int m, int y){
			day = dd = d;
			mm = m;
			yy = y;
			for (int i = 1; i < m; i++)
				day += y % 4 ? a[i] : b[i];
		}

		friend ostream & operator << (ostream&, date);
		int operator - (date);
		date operator +(int);

};

int date::operator - (date d2){

	int res = 0, i;
	for (i = d2.yy; i < yy;i++)
		res += i%4?365:366;
	return res + day - d2.day;

}

ostream& operator << (ostream &out, date d){
	out << d.dd << "/" << d.mm << "/" << d.yy;
	return out;
}

date date::operator+(int n){

	for (int i = 0; i < n; i++){
		dd++;
		if ((yy % 4 == 0 && dd>b[mm]) || (yy%4 && dd > a[mm]) ){
			dd = 1;
			if (++mm > 12){
				mm = 1;
				++yy;
			}
		}
	}
	date temp(dd, mm, yy);
	return temp;

}

void main(){

	int d, m, y, add;
	cout << "Enter a date : ";
	cin >> d >> m >> y;
	date d1(d, m, y);
	cout << "Enter a lesser date : ";
	cin >> d >> m >> y;
	date d2(d, m, y);
	cout << "The 1st date is : " << d1 << endl;
	cout << "The 2nd date is : " << d2 << endl;
	cout << "No od days between the 2 dates : " << d1 - d2 << endl;
	cout << "\nEnter a number to add to 1st date : ";
	cin >> add;
	cout << "The new date is " << (d1 + add) << endl;
	_getch();

}