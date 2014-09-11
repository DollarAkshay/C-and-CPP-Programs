//http://www.codechef.com/problems/DCE05

#include<stdio.h>

int main(){
	int s, n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++){
		scanf("%d", &s);
		int c = 0;
		while (s ^ 1){ s = s >> 1; c++; }
		while (c--)s = s << 1;
		printf("%d\n", s);
	}
	return 0;
}