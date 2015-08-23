#include<stdlib.h>
#include<string>
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mu;

using namespace std;

void shared_print(string msg, int id) {
	lock_guard<mutex> guard(mu);
	//mu.lock();
	cout<<msg<<id<<endl;
	//mu.unlock();
}

void function_1() {
	for (int i = 0; i<100; i++)
		shared_print("Thread :", i);
}

int main() {

	thread t1(function_1);

	for (int i = 0; i<100; i++)
		shared_print("Main :", i);

	t1.join();

	system("pause");
	return 0;
}