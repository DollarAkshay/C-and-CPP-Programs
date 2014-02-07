#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
	float root1, root2;
	float a, b, c;
	float det;
	printf("Enter the coefficients for a,b and c : ");
	scanf("%f %f %f", &a, &b, &c);
	if (a*b*c == 0){
		printf("Cannot solve this equation");
	}
	else{
		det = b*b - 4 * a*c;
		if (det == 0){
			root1 = root2 = -b / (2 * a);
			printf("\nThe 2 roots are : %f  and  %f\n", root1, root2);
		}
		else if (det > 0){
			root1 = (-b + sqrt(det)) / (2 * a);
			root2 = (-b - sqrt(det)) / (2 * a);
			printf("\nThe 2 roots are : %f  and  %f\n", root1, root2);
		}
		else{
			float real,img;
			real = -b / (2 * a);
			img = sqrt(abs(det)) / (2 * a);
			printf("\nThe 2 roots are : %f + %fi  and  %f - %fi\n", real,img,real,img);
		}

	}
	_getch();

}