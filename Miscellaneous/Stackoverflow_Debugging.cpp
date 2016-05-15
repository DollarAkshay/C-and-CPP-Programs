#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

	vector<char> test("HelloWorld"), tmp;

	// method 1
	tmp = test;
	sort(tmp.begin(), tmp.begin() + strlen(tmp.begin()));
	cout << "result: " << tmp.data() << endl;

	// method 2
	tmp = test;
	sort(tmp.begin(), tmp.end());
	cout << "result: " << tmp.data() << endl;

	return 0;
}