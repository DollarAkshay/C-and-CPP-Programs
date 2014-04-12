//http://www.codechef.com/problems/INTEST

#include<stdio.h>
#include <omp.h>

int main(){
	int n, k, t, c = 0, i;
	scanf("%d %d", &n, &k);
#pragma omp for private(t) shared(c) 
	{
	for (i = 0; i < n; i++){
		scanf("%d", &t);
		if (t%k == 0)
			c++;
	}
	}
	printf("%d",c);
	return 0;
}