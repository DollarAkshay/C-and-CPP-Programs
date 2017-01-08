
#include <stdio.h>
#include <conio.h>

void main(){

	int i, a[4];
	for (i = 0; i <= 9999; i++){
		int x = i,j=0;
		while (x) a[j++]=x%10,x/=10;
		if (a[0]==2*a[3] && a[1]==a[2] && a[3]*20+2*a[2]==a[1]*10+a[0])
			printf("%d\n", i);
	}
	printf("Done Looping\n");
	_getch();
}