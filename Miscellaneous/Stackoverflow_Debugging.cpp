#include<stdio.h>


int isLeapYear(int year) {
	if ( ((year%4==0) && (year%100!=0)) || (year%400==0)) {
		return 1;
	}
	else
		return 0;
}

int getYear() {
	int year = 0;
	while (year==0 || year < 0) {
		printf("Enter year: ");
		scanf("%d", &year);
		if (year > 0) {
			break;
		}
		printf("Invalid input. Try again.\n\n");
	}
	return year;
}

void printWeekday(int w) {
	switch (w) {
	case 0:
		printf("Sun");
		break;
	case 1:
		printf("Mon");
		break;
	case 2:
		printf("Tue");
		break;
	case 3:
		printf("Wed");
		break;
	case 4:
		printf("Thu");
		break;
	case 5:
		printf("Fri");
		break;
	case 6:
		printf("Sat");
		break;
	}
}

void printMonth(int m) {
	switch (m) {
	case 1:
		printf("Jan");
		break;
	case 2:
		printf("       Feb");
		break;
	case 3:
		printf("       Mar");
		break;
	case 4:
		printf("       Apr");
		break;
	case 5:
		printf("       May");
		break;
	case 6:
		printf("       Jun");
		break;
	case 7:
		printf("       Jul");
		break;
	case 8:
		printf("       Aug");
		break;
	case 9:
		printf("       Sep");
		break;
	case 10:
		printf("       Oct");
		break;
	case 11:
		printf("       Nov");
		break;
	case 12:
		printf("       Dec\n");
		break;
	}
}

int dayofweek(int d, int m , int y){

	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void calendar(int year) {


	int days_in_month[14] = { 0,31,28,31,30,31,30,31,31,30,31,30,31,0 };

	if (isLeapYear(year)) {
		days_in_month[2] = 29;
	}
	for (int m = 1; m<=12; m++) {
		printMonth(m);
	}

	for (int d = 1; d<=31; d++) {
		for (int m = 1; m<=12; m++) {
			if (d <= days_in_month[m]) {
				int weekday = dayofweek(d, m, year);
				printf("%02d ", d);
				printWeekday(weekday);
				printf("    ");
			}
			else {
				printf("          ");
			}
		}
		printf("\n");
	}				

}

int main(){


	int end = 1;
	while (end) {
		int year = getYear();
		printf("                                                         %d\n", year);
		calendar(year);
		printf("\nEnter 0 to quit: ");
		scanf("%d", &end);
		//system("cls");
	}
	return 0;
}