/* To find the LCM and HCF of 2 given numbers*/

#include<stdio.h>
#include<conio.h>

void main(){
	int m, n, a, b, temp;

	START:
	printf("\nEnter the numbers m and n :");
	scanf("%d%d",&m,&n);
	a = n; b = m;
	if (m*n == 0)
		printf("HCF and LCM cannot be enumerated for 0");
	else{
		while (n>0){
			temp = n;
			n = m % n;
			m = temp;
		}
		printf("HCF = %d\t LCM = %d\n",m,a*b/m);

		goto START; 
	}
	_getch();


}