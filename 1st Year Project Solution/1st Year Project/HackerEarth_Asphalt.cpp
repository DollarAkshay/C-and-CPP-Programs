/*Lala is an Asphalt champ.His car is stuck in an infinite city at(0, 0).
The city has vertical streets located at every integer X value and horizontal streets
located at every Y value.He has to reach finishing spot in minimum time.
There are nitro boosters in the city and their locations are(NX[i], NY[i]).
The boosters are infinite i.e.they last forever.It takes normalTime seconds to drive 
along the street to proceed to a horizontally or vertically adjacent intersection without 
booster and it takes nitroTime seconds with boosters.

Print the least amount of time it will take him to reach finishing spot located at(fx, fy).

Input:
t : testcases
	Each testcase contains 5 lines
n : number of boosts
	A line containing array NX[]
	A line containing array NY[]
	fx and fy
	normalTime and nitroTime.

Output:
	As specified in problem statement
	Constraints :
	1 <= t <= 1000
	1 <= n <= 10 ^ 5
	1 <= nitroTime, normalTime <= 1000
	- 10 ^ 6 <= fx, NX[i] <= 10 ^ 6
	- 10 ^ 6 <= fy, NY[i] <= 10 ^ 6

Sample Input :
1
2
- 2 0
- 2 - 2
- 4 - 2
15 3
		
Sample Output :
42

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>


#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void main(){
	int t, n, *nx, *ny, fx, fy, nitro, normal, i;
	long int imabitch;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		nx = (int*)malloc(n*sizeof(int));
		ny = (int*)malloc(n*sizeof(int));
		for (i = 0; i < n; i++)
			scanf("%d", nx + i);
		for (i = 0; i < n; i++)
			scanf("%d", ny + i);
		scanf("%d%d%d%d", &fx, &fy, &normal, &nitro);
		imabitch = abs(fx)*normal + abs(fy)*normal;
		for (i = 0; i < n; i++){
			long int bitch = abs(*(nx + i))*normal + abs(*(ny + i))*normal;
			if (bitch >= imabitch)
				continue;

			bitch = bitch + abs(fx - *(nx + i))*nitro + abs(fy - *(ny + i))*nitro;
			if (bitch < imabitch)
				imabitch = bitch;
		}
		printf("%ld\n", imabitch);
		free(nx);
		free(ny);
	}
}

//Solved


/*
Without malloc - Much faster 0.37 sec

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void main(){
	int t, n, nx[100000], ny[100000], fx, fy, nitro, normal, i;
	long int imabitch;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &nx[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &ny[i]);
		scanf("%d%d%d%d",&fx,&fy,&normal,&nitro);
		imabitch = abs(fx)*normal + abs(fy)*normal;
		for (i = 0; i < n; i++){
			long int bitch = abs(nx[i])*normal + abs(ny[i])*normal;
			if (bitch >= imabitch)
				continue;

			bitch = bitch + abs(fx - nx[i])*nitro + abs(fy - ny[i])*nitro;
			if (bitch < imabitch)
				imabitch = bitch;
		}
		printf("%ld\n", imabitch);
	}
}


*/







