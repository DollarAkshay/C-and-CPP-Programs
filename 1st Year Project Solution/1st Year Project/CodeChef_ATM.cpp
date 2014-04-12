#include<stdio.h>

int main(){
	int w;
	float b;
	scanf("%d %f", &w, &b);
	if (w % 5 == 0 && b>(w + 0.5))
		printf("%f", b - w - 0.5);
	else
		printf("%.2f", b);
	return 0;

}