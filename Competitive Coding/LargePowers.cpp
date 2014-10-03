#include <stdio.h>


using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define ll long long
#define DIG 4000


int num[DIG];

int getZero(){
	int i = DIG - 1;
	while (num[i] == 0 && i)i--;
	return i;

}

void pow(int a, int b){
	int carry = 0, prod;
	num[0] = 1;
	while (b){
		for (int i = 0; i <= getZero() || carry>0; i++){
			prod = num[i] * a + carry;
			carry = prod / 10;
			num[i] = prod % 10;
		}
		b--;
	}
}

void printArray(){
	int i = getZero() + 1;
	int sum = 0;
	while (i--) {
		sum += num[i];
		printf("%d", num[i]);
		num[i] = 0;
	}
	printf("\nSum of Digits = %d\n",sum);
}

int main(){

	int t, a, b;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &a, &b);
		pow(a, b);
		printArray();
	}
	return 0;
}
