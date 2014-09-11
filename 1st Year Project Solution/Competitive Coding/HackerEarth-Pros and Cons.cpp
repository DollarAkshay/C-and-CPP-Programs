#include<stdio.h>

int main(){
	long long int t, n, i;
	long long int th = 0, ta = 0, g1h, g1a, g2h, g2a, score;
	scanf("%lld", &t);
	while (t--){
		th = ta = score = 0;
		scanf("%lld", &n);
		for (i = 0; i < n; i++){
			long long int gh, ga;
			scanf("%lld %lld", &gh, &ga);
			th += gh;
			ta += ga;
			if (i == 0){
				g1h = gh;
				g1a = ga;
			}
			else if (i == 1){
				g2h = gh;
				g2a = ga;
			}
			else{
				long long int h1, a1, h2, a2;
				h1 = g2h + gh;
				h2 = g1h + gh;
				a1 = ta - ga - g2a;
				a2 = ta - ga - g1a;
				score = g1h + g2h - ta + g1a + g2a;
				if (h1 - a1 > h2 - a2 && h1 - a1>score){
					g1h = gh;
					g1a = ga;
				}
				else if (h2 - a2 > score){
					g2h = gh;
					g2a = ga;
				}
			}
		}
		printf("%lld\n", g1h + g2h - ta + g1a + g2a);
	}

}


//Solved