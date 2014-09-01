//http://www.hackerearth.com/HackTheSlack/algorithm/noodle-jump/

#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}


int main()
{

	int n, k, a[1000001], i;
	a[0] = 0;

	// Reading Inputs
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);


	qsort(a, n + 1, sizeof(int), compare);

	for (i = 1; i <= n; i++){
		if (a[i] - a[i - 1]>k)
			break;
	}
	printf("%d\n", a[i - 1] ? a[i - 1] : 0);
}

//Solved
