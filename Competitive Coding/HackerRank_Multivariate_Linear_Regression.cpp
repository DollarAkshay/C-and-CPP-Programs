/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/predicting-house-prices

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

struct house{
	double x[1000],y;
};

house h[100];
double b[1000][1000];
double X[1000][1000],XT[1000][1000],Y[1000][1000],inverse[1000][1000];

double res1[1000][1000], res2[1000][1000];



double determinant(double a[1000][1000], double k){
	double s = 1, det = 0, b[1000][1000];
	int i, j, m, n, c;
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (c = 0; c<k; c++)
		{
			m = 0;
			n = 0;
			for (i = 0; i<k; i++)
			{
				for (j = 0; j<k; j++)
				{
					b[i][j] = 0;
					if (i != 0 && j != c)
					{
						b[m][n] = a[i][j];
						if (n<(k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}
	return (det);
}

void transpose(double num[1000][1000], double fac[1000][1000], double r){
	int i, j;
	double b[1000][1000], d;

	for (i = 0; i<r; i++)
	{
		for (j = 0; j<r; j++)
		{
			b[i][j] = fac[j][i];
		}
	}
	d = determinant(num, r);
	for (i = 0; i<r; i++)
	{
		for (j = 0; j<r; j++)
		{
			inverse[i][j] = b[i][j] / d;
		}
	}
}


int MatrixInversion(double* A, int n, double* AInverse)
{
	// A = input matrix (n x n)
	// n = dimension of A 
	// AInverse = inverted matrix (n x n)
	// This function inverts a matrix based on the Gauss Jordan method.
	// The function returns 1 on success, 0 on failure.
	int i, j, iPass, imx, icol, irow;
	float det, temp, pivot, factor;
	float* ac = (float*)calloc(n*n, sizeof(float));
	det = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			AInverse[n*i + j] = 0;
			ac[n*i + j] = A[n*i + j];
		}
		AInverse[n*i + i] = 1;
	}

	// The current pivot row is iPass.  
	// For each pass, first find the maximum element in the pivot column.
	for (iPass = 0; iPass < n; iPass++)
	{
		imx = iPass;
		for (irow = iPass; irow < n; irow++)
		{
			if (fabs(A[n*irow + iPass]) > fabs(A[n*imx + iPass])) imx = irow;
		}
		// Interchange the elements of row iPass and row imx in both A and AInverse.
		if (imx != iPass)
		{
			for (icol = 0; icol < n; icol++)
			{
				temp = AInverse[n*iPass + icol];
				AInverse[n*iPass + icol] = AInverse[n*imx + icol];
				AInverse[n*imx + icol] = temp;

				if (icol >= iPass)
				{
					temp = A[n*iPass + icol];
					A[n*iPass + icol] = A[n*imx + icol];
					A[n*imx + icol] = temp;
				}
			}
		}

		// The current pivot is now A[iPass][iPass].
		// The determinant is the product of the pivot elements.
		pivot = A[n*iPass + iPass];
		det = det * pivot;
		if (det == 0)
		{
			free(ac);
			return 0;
		}

		for (icol = 0; icol < n; icol++)
		{
			// Normalize the pivot row by dividing by the pivot element.
			AInverse[n*iPass + icol] = AInverse[n*iPass + icol] / pivot;
			if (icol >= iPass) A[n*iPass + icol] = A[n*iPass + icol] / pivot;
		}

		for (irow = 0; irow < n; irow++)
			// Add a multiple of the pivot row to each row.  The multiple factor 
			// is chosen so that the element of A on the pivot column is 0.
		{
			if (irow != iPass) factor = A[n*irow + iPass];
			for (icol = 0; icol < n; icol++)
			{
				if (irow != iPass)
				{
					AInverse[n*irow + icol] -= factor * AInverse[n*iPass + icol];
					A[n*irow + icol] -= factor * A[n*iPass + icol];
				}
			}
		}
	}

	free(ac);
	return 1;
}

void mulMat(double a[1000][1000], double b[1000][1000], int m, int n, int p, int q, double c[1000][1000]){

	int i, j, k;
	for (i = 0; i < m; i++){
		for (j = 0; j < q; j++){
			c[i][j] = k = 0;
			while (k < n){
				c[i][j] += a[i][k] * b[k][j];
				k++;
			}
		}
	}

}

int main(){

	int f, n,t ;
	double intercept = 0, ymean = 0;
	scanf("%d%d",&f, &n);
	REP(i,n){
		X[i][0] = 1;
		REP(k, f){
			scanf("%lf", &h[i].x[k]);
			X[i][k+1] = h[i].x[k];
		}
		scanf("%lf", &h[i].y);
		Y[i][0] = h[i].y;
	}
	f++;
	REP(i, n)
		REP(j, f)
			XT[j][i] = X[i][j];

	mulMat(XT, X, f, n, n, f, res1);
	double *tres1 = (double*)calloc(f*f, sizeof(double));
	double *tinv = (double*)calloc(f*f, sizeof(double));
	REP(i, f)
		REP(j, f)
			tres1[i*f + j] = res1[i][j];
	MatrixInversion(tres1, f, tinv);
	REP(i, f)
		REP(j, f)
		inverse[i][j] = tinv[i*f + j];
	mulMat(XT, Y, f, n, n, 1,res2);
	mulMat(inverse, res2, f, f, f, 1, b);
	f--;

	scanf("%d", &t);
	REP(i, t){
		double price = b[0][0];
		FOR(k,1,f){
			double temp;
			scanf("%lf", &temp);
			price += temp*b[k][0];
		}
		printf("%lf\n", price);
	}
	sp;
	return 0;
}

//