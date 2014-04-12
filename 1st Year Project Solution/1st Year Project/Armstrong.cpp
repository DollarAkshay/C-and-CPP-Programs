#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){

	int n,found=0,dig=1;
	printf("How many Armstrong numbers do you want to find ? : ");
	scanf("%d",&n);
	for (int i = 0; found < n;i++)
	{
		if (i >pow((double)10, (double)dig)-1) dig++;
		int sum = 0,j=i;
		while (j>0){
			sum += pow((double)(j%10), (double)dig);
			j/=10;
		}
		if (sum == i){
			found++;
			printf("Armstrong %d = %d \n",found, i);		
		}
	}
	_getch();
}