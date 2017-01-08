#include <iostream>
#include <conio.h>

using namespace std;

class Employee {
	float no, salary, allowances, IT, net_salary;
	char name[100];
public: void readEmp();
		void printData();
		void calculate();
};

void Employee::readEmp(){
	cout << "\n\nEnter the following details \nName   :";
	cin >> name;
	cout << "Number : ";
	cin >> no;
	cout << "Salary : ";
	cin >> salary;
}
void Employee::calculate(){
	allowances = 1.25*salary;
	IT = (allowances + salary)*0.3;
	net_salary = salary + allowances - IT;
}

void Employee::printData(){
	cout << "\nHello " << name << ", here are your details :\n";
	cout << " Number     : " << no << endl;
	cout << "Salary     : Rs." << salary << endl;
	cout << "Allowances : Rs." << allowances << endl;
	cout << "Income Tax : Rs." << IT << endl;
	cout << "Net Salary : Rs." << net_salary << endl;
}

int main(){

	Employee e1, e2;
	//Employee 1
	e1.readEmp();
	e1.calculate();
	e1.printData();
	//Employee 2
	e2.readEmp();
	e2.calculate();
	e2.printData();
	_getch();
	return 0;
}

/*
Output :
---------------------------------------------------------
Enter the following details
Name   :Akshay
Number : 09
Salary : 500000

Hello Akshay, here are your details :
Number     : 9
Salary     : Rs.500000
Allowances : Rs.625000
Income Tax : Rs.337500
Net Salary : Rs.787500


Enter the following details
Name   :Aradhya
Number : 10
Salary : 100

Hello Aradhya, here are your details :
Number     : 10
Salary     : Rs.100
Allowances : Rs.125
Income Tax : Rs.67.5
Net Salary : Rs.157.5

*/



