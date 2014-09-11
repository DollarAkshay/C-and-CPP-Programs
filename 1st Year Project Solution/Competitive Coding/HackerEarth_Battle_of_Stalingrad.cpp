//http://www.hackerearth.com/problem/algorithm/battle-of-stalingrad-1/

#include <stdio.h>
#include <math.h>

double area(int x1, int y1, int x2, int y2, int x3, int y3){

	return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);

}


int inside(int x1, int y1, int x2, int y2, int x3, int y3, int px, int py){

	double ABC = area(x1, y1, x2, y2, x3, y3);
	//ABC = round(ABC*10)/10;

	//if(ABC==0)
	//return 1;

	double ABP = area(x1, y1, x2, y2, px, py);
	//ABP = round(ABP*10)/10;

	double APC = area(x1, y1, px, py, x3, y3);
	//APC = round(APC*10)/10;

	double PBC = area(px, py, x2, y2, x3, y3);
	//PBC = round(PBC*10)/10;

	if (ABC == ABP + APC + PBC)
		return 1;
	else
		return 0;
}


int main()
{

	int t, x1, y1, x2, y2, x3, y3, px, py;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &px, &py);
		if (inside(x1, y1, x2, y2, x3, y3, px, py))
			printf("INSIDE\n");
		else
			printf("OUTSIDE\n");
	}
}
