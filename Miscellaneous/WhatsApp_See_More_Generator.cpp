#include<stdio.h>

void insertSeeMore(FILE *f) {

	for (int i = 0; i<32400; i++)
	fprintf(f, "\n");


}

int main() {

	FILE *f = fopen("msg.txt", "w");

	fprintf(f, "Tallest Whatsapp message. World Record\n");
		insertSeeMore(f);
	fprintf(f, "00100100\n");
	fclose(f);
	return 0;
}