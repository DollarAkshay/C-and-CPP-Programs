#include<stdio.h>
#include<string.h>

struct Employee {
	int id;			// 4 Digit Unique Key
	char name[10];
};

struct HashEntry {
	int isOccupied;
	int key;
	char name[10];
};

HashEntry table[100];	// Our hash table with 100 memory locations

// A simple modulo hash function
int getHashKey(Employee emp) {
	return emp.id % 100;
}

// Inserts a record into our global hashtable.
void insert(Employee emp) {

	int i, hashkey = getHashKey(emp);

	if (table[hashkey].isOccupied == false) {		// If key is not occupied then insert it into that key position
		table[hashkey].isOccupied = true;
		strcpy(table[hashkey].name, emp.name);
		printf("Inserted %10s at %2d\n\n\n", emp.name, hashkey);
	}
	else {											// If key is occupied look for next nearest empty entry a.k.a. Linear Probing
		printf("Hash Colission. [ %4d ]\n\n", emp.id);
		printf("KeyValue of %2d is occupied by %10s\n\n", hashkey, table[hashkey].name);

		for (i = hashkey+1; i != hashkey ; i=(i+1)%100) {
			if (table[i].isOccupied == false){
				table[i].isOccupied = true;
				strcpy(table[i].name, emp.name);
				printf("Inserted %10s at %2d\n\n\n", emp.name, i);
				break;
			}
			else {
				printf("KeyValue of %2d is occupied by %10s\n\n", i, table[i].name);
			}
		}

		if (i==hashkey) {
			printf("Hash Table is full.\n");
		}
	}

}

int main() {


	Employee emp_array[] = 
	{
		{ 1111, "Akshay"},
		{ 2222, "Meghana" },
		{ 3333, "Anagha" },
		{ 4444, "Aishwarya" },
		{ 1122, "Nidhi" },
		{ 1144, "Kiran" },
		{ 5522, "Smith" }
	};


	for (int i = 0; i< 7; i++) {
		insert(emp_array[i]);
	}

	getchar();
	return 0;

}