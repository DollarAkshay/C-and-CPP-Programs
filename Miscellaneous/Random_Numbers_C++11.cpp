#include<stdio.h>
#include<stdlib.h>
#include<random>
#include<windows.h>

using namespace std;

int main() {

	mt19937 mt(26640195);
	uniform_int_distribution<int> dist(1, 1000000);
	for (int i = 0; i<100; i++) {
		printf("%7d\n", dist(mt));
		Sleep(500);
	}
	system("pause");
}

//Works :)