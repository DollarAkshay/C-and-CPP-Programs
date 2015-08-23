#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<thread>

using namespace std;

void function_1() {
	for (int i = 0; i<100; i++)
		cout<<"Thread :"<<i<<endl;
}

int main() {

	thread t1(function_1);

	for (int i = 0; i<100; i++)
		cout<<"Main :"<<i<<endl;

	system("pause");
	return 0;
}