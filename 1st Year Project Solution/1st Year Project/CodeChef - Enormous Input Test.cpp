//http://www.codechef.com/problems/INTEST

#include<stdio.h>

int main(){
	int n,k,t,c=0;
	scanf("%d %d", &n,&k);
	while (n--){
		scanf("%d", &t);
		if (t%k == 0)
			c++;
	}
	printf("%d",c);
	return 0;
}