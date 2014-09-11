
#include <stdio.h>
#include <stdlib.h>

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n-1)

int comp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}



int main(){

	int n, m, i, j;
	int box[10000], trk[10000];
	static int load[10000];

	scanf("%d%d", &n, &m);
	REP(i, n)
		scanf("%d", &box[i]);
	REP(i, m)
		scanf("%d", &trk[i]);

	//Sorting 
	qsort(box, n, sizeof(int), comp);
	qsort(trk, m, sizeof(int), comp);



	int minload = trk[m - 1];
	for (i = 0; box[i]>minload; i++){
		for (j = m - 1; trk[j]<box[i]; j--);
		load[j]++;
	}
	int rem = n - i;

	printf("Remaining Boxes = %d\n", rem);

	while (rem){
		int least = n, index;
		REP(i, m){
			if (load[i]<least){
				least = load[i];
				index = i;
			}
		}
		load[index]++;
		rem--;
	}

	REP(i, m){
		printf("%d ", load[i]);
	}

	int max = 0;
	REP(i, m){
		if (load[i]>max)
			max = load[i];
	}

	printf("\n%d\n\n", max * 2 - 1);
	system("pause");
	return 0;
	

}