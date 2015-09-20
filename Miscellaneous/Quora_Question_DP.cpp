/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.quora.com/In-a-staircase-of-four-steps-Sally-can-jump-1-step-2-steps-3-steps-or-all-4-steps-In-how-many-ways-can-she-reach-the-top

#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define sp system("pause")
#define ll long long

ll int DP[1000000];

ll int ways(int n) {

	if (n<0)
		return 0;
	if (DP[n])
		return DP[n];

	if (n==0)
		DP[n] = 1;
	else
		DP[n] = ways(n-1) + ways(n-2) + ways(n-3) + ways(n-4);

	return DP[n];

}

int main(){

	int n;
	printf("Enter number of steps : ");
	scanf("%d", &n);
	printf("Number of ways = %d\n", ways(n));

	for (int i = 1; i <=n; i++)
		printf(", %d", DP[i]);
	sp;
	return 0;
}

//