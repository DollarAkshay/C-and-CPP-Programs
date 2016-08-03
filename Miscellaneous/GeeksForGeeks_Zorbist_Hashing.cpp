/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

#include <stdio.h>
#include <limits>
#include <random>

using namespace std;

unsigned long long int randomInt() {

	mt19937 mt;
	uniform_int_distribution<unsigned long long int> dist(0, UINT64_MAX);

	return dist(mt);

}

int main(){

	char board[8][9] = { "--------", "--------", "--------", "--------", "--------", "--------", "--------", "--------" };

	return 0;
}

//