/*

Your task for this problem is simple. You will be given two numbers, 
you need to multiply them and output the result % 1012+39.
Input:
First line starts with t the test cases. The next t lines contain two space separated integers a b.
Output:
For each test case output (a*b)%(1012+39)
Constraints:
1<=a,b<=1015

Sample Input :
1
123456789 1234567891011

Sample Output :
620775807986


*/


#include<stdio.h>

const int size = 100;

int n[size], A[size], B[size], prod[size], fact[size], lena, lenb;


int T[size];
int clear[size];
int t2[size] = { 2, 0, 0, 0, 1 };
int prime[100] = { 9, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };




void scanA(){
	int c = getchar()-48,i,j;
	for (; c <= -1 || c >= 10; c = getchar() - 48);
	for (i = 0; c >= 0 && c <= 9; i++){
		A[i] = c;
		c = getchar() - 48;
	}
	lena = i;
	for (i = 0,j=lena-1; i<j ; i++,j--){
		int t = A[i];
		A[i] = A[j];
		A[j] = t;
	}
}

void scanB(){
	int c = getchar() - 48,i,j;
	for (; c <= -1 || c >= 10; c = getchar() - 48);
	for (i = 0; c >= 0 && c <= 9; i++){
		B[i] = c;
		c = getchar() - 48;
	}
	lenb = i;
	for (i = 0, j = lenb-1; i<j ; i++, j--){
		int t = B[i];
		B[i] = B[j];
		B[j] = t;
	}
}

int getDigit(int X[]){
	int i = size;
	while (!X[--i] && i>=0);
	if (i < 0)
		i = 0;
	return i;
}

void copyArray(int a[], int b[]){
	int i = size;
	while (i--)
		a[i] = b[i];
}



void add(int x,int res[]){
	int sum = 0, carry = 0, i, len = getDigit(prod);
	for (i = x;i <=len+x|| carry > 0 || i == x; i++){
		sum = res[i] + prod[i-x] + carry;
		carry = sum / 10;
		res[i] = sum % 10;
	}
}

void sub(int a[],int b[],int c[]){
	int i, j = 1, len = getDigit(a);
	for (i = 0; i <=len; i++){
		if (a[i]>=b[i])
			c[i] = a[i] - b[i];
		else{
			c[i] = a[i] - b[i] + 10;
			j = 1;
			while (--a[i + j] == -1){
				a[i + j] = 9;
				j++;
			}
		}
	}
}

void multiply(int a[],int b[],int res[]){
	
	int sum = 0, carry = 0, i, j, k, lena = getDigit(a), lenb = getDigit(b);
	for (i = 0; i <=lena; i++){
		for (j = 0; j<=lenb || carry>0 || j==0; j++){
			sum =a[i] * b[j] + carry;
			carry = sum / 10;
			prod[j] = sum % 10;
		}
		add(i,res);
		k = 20;
		while(k--)
			prod[k] = 0;
	}
}

void printArray(int X[]){
	for (int i = getDigit(X); i >= 0; i--){
		printf("%d", X[i]);
	}
	printf("\n");
}

int greater(int a[],int b[]){
	int la = getDigit(a), lb = getDigit(b);
	if (la > lb)
		return la-lb;
	else if (lb>la)
		return -1;
	else{
		for (int i = la; i >= 0; i--){
			if (a[i]>b[i])
				return 1;
			else if (b[i]>a[i])
				return -1;
		}
		return 0;
	}
}

void mod(int m[],int n[]){
	int diff = greater(m, n);
	while(diff!=-1){
		if (diff > 0){
			fact[diff ] = 1;
			multiply(fact, n, T);
			if (greater(m, T) != -1){
				sub(m, T, m);
				copyArray(T, clear);
				copyArray(fact, clear);
			}
			else{
				sub(m, n, m);
			}
		}
		else
			sub(m, n, m);
		diff = greater(m, n);
	}
}



int main()
{
	long long int a, b, r;
	int t;
	scanf("%d", &t);
	while (t--){
		scanA();
		scanB();
		mod(A, prime);
		mod(B, prime);
		multiply(A, B, n);
		mod(n, prime);
		printArray(n);
	}
	
}
