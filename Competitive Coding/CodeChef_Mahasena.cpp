
//https://www.codechef.com/ACMAMR15/problems/AMR15A

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){

	int n, a[101], max, min;
	scanf("%d", &n);

	for (int i = 1; i<=n; i++)
		scanf("%d", &a[i]);

	int i = 1; max = 0; min = 0;

	while (i<=n) {
		if (a[i]%2==0)
			max++;
		else
			min++;
		i++;
	}

	if (max>min)
		printf("READY FOR BATTLE");
	else
		printf("NOT READY");
	return 0;
}

//Solved by Vindhya :)