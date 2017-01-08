#include <iostream>
#include <conio.h>

using namespace std;

class STRING {
	char name[100];
public: STRING(){
			name[0] = '\0';
		}
		STRING(char s[]){
			strcpy(name, s);
		}
		STRING(STRING &s){
			strcpy(name, s.name);
		}
		friend STRING operator + (STRING, STRING);
		friend ostream& operator << (ostream&, STRING&);
};

ostream& operator << (ostream& out, STRING &s){
	out << s.name;
	return out;
}

STRING operator + (STRING s1, STRING s2){
	STRING t(s1);
	strcat(t.name, s2.name);
	return t;
}

int main(){
	STRING s1("VTU"), s2("BELGAUM");
	STRING s3 = s1 + s2;
	cout << "S1 = " << s1 << endl;
	cout << "S2 = " << s2 << endl;
	cout << "S3 = " << s3 << endl;
	_getch();
	return 0;
}


