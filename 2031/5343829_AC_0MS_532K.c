#include <stdio.h>
#include <string.h>
#include <math.h>
#define dist(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))
#define oo 99999999999999.999f
#define eps 1e-20
#define MAX 102
double adj[MAX][MAX], key[MAX];
double x[MAX], y[MAX], z[MAX], r[MAX];
int has[MAX], n;
double prim()
{
	double res = 0.0;
	double min;
	int i, j, k;
	for(i = 1;i <= n; i++)
	{
		key[i] = adj[1][i];
		has[i] = 0;
	}
	has[1] = 1;
	for(i = 1;i < n; i++)
	{
		min = oo;
		k = 1;
		for(j = 1;j <= n; j++)
			if(has[j] == 0 && min > key[j])
			{
				min = key[j];
				k = j;
			}
		has[k] = 1;
		res += min;
		for(j = 1;j <= n; j++) 
			if(key[j] > adj[k][j]) key[j] = adj[k][j];
	}
	return res;
}
int init()
{
	double d1, d2, d;
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
	for(i = 1;i <= n; i++) scanf("%lf %lf %lf %lf", &x[i], &y[i], &z[i], &r[i]);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			if(i == j) { adj[i][j] = 0.0; continue;}
			d1 = dist(i, j);
			d2 = r[i] + r[j];
			if(d2 + eps < d1) d = d1 - d2;
			else d = 0.0;
			adj[i][j] = d;
		}
	}
	return 1;
}
int main()
{
	double ans;
	while(init())
	{
		ans = prim();
		printf("%0.3f\n", ans);
	}
	return 0;
}
