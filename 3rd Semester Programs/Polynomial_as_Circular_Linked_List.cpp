#include<stdio.h>
#include<stdlib.h>

struct polynomial {
	int isHead;
	int x, y, z;		// Coeficents of x, y and z in a term
	struct polynomial *next;
};

void insertTerm(polynomial *p, int x, int y, int z) {

	// This function scans till the end and inserts a new node;

	polynomial *node = (polynomial*)malloc(sizeof(polynomial));	// Initializing the Node
	node->isHead = false;
	node->x = x;
	node->y = y;
	node->z = z;
	node->next = p;		// Since it will be entered at the end of the list it should point back to the head

	polynomial *cur = p;
	while (cur->next->isHead == false)
		cur = cur->next;

	// We are now at the last node in the list
	cur->next = node;


}

polynomial* addPolynomials(polynomial *p1, polynomial *p2) {

	polynomial	*res = (polynomial*)malloc(sizeof(polynomial));
	res->isHead = true;
	res->next = res;

	polynomial	*cur1 = p1->next, *cur2 = p2->next;

	while (cur1->isHead==false && cur2->isHead==false) {
		insertTerm(res, cur1->x + cur2->x, cur1->y + cur2->y, cur1->z + cur2->z);
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	
	// If p1 and p2 are not of equal length
	while (cur1->isHead==false) {
		insertTerm(res, cur1->x, cur1->y, cur1->z);
		cur1 = cur1->next;
	}

	while (cur2->isHead==false) {
		insertTerm(res, cur2->x, cur2->y, cur2->z);
		cur2 = cur2->next;
	}

	return res;

}

void printPoly(polynomial *p) {

	// Prints the polynomial in a single line
	p = p->next;
	while (p->isHead==false) {
		printf(" + ");
		if (p->x > 0)
			printf("%dx", p->x);
		if (p->y > 0)
			printf("%dy", p->y);
		if (p->z > 0)
			printf("%dz", p->z);
		p = p->next;
	}
	printf("\n");

}

int main() {

	int x, y, z;
	polynomial	*p1 = (polynomial*)malloc(sizeof(polynomial)), 
				*p2 = (polynomial*)malloc(sizeof(polynomial));

	// Read first polynomial
	p1->isHead = true;
	p1->next = p1;
	printf("Enter the polynomial P1 Enter 0 0 0 to stop :\n");
	while (true) {
		printf("\nEnter the term : ");
		scanf("%d %d %d", &x, &y, &z);	//Read a single term

		if (x==0 && y==0 && z==0)
			break;						// Stop reading polynomial if all coeffeicents are 0
		else 
			insertTerm(p1, x, y, z);
	}


	// Do the same thing for the second polynomial
	p2->isHead = true;
	p2->next = p2;
	printf("\n\nEnter a polynomial P2 Enter 0 0 0 to stop :\n");
	while (true) {
		printf("\nEnter the term : ");
		scanf("%d %d %d", &x, &y, &z);	//Read a single term
		if (x==0 && y==0 && z==0)
			break;						// Stop reading polynomial if all coeffeicents are 0
		else
			insertTerm(p2, x, y, z);
	}

	polynomial *sum = addPolynomials(p1, p2);

	printf("\nP1 :"); printPoly(p1);
	printf("\nP2 :"); printPoly(p2);
	printf("\nSUM :"); printPoly(sum);

	printf("End of Program\n");
	getchar();
	return 0;


}