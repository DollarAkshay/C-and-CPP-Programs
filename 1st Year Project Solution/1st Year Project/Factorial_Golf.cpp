
#include<stdio.h>

void main(){
	int n,f=scanf("%d",&n);
	while (n > 0) f *= n--;
	printf("%d", f);
}


