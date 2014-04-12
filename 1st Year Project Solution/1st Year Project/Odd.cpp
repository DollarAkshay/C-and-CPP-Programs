//http://www.codechef.com/problems/DCE05

#include<stdio.h>
#include<math.h>

int main(){
	int s, n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++){
		scanf("%d", &s);
		printf("%d\n", (int)pow((double)2, (double)((int)log2((double)s))));
	}
	return 0;
}