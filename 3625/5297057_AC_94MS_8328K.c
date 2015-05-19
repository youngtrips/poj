#include <stdio.h>
#include <math.h>
#include <string.h>
#define dist(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
#define oo 999999999999.999f
#define MAX 1002
double adj[MAX][MAX], key[MAX], x[MAX], y[MAX];
int has[MAX], n;
double prim()
{
	double res = 0.0, min;
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
		for(j = 1;j <= n; j++) if(key[j] > adj[k][j]) key[j] = adj[k][j];
	}
	return res;
}
int main()
{
	double res;
	int i, j, m;
	scanf("%d %d", &n, &m);
	for(i = 1;i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			if(i == j) adj[i][j] = 0.0;
			else adj[i][j] = dist(i, j);
		}
	}
	while(m--)
	{
		scanf("%d %d", &i, &j);
		adj[i][j] = 0.0;
		adj[j][i] = 0.0;
	}
	printf("%0.2f\n", prim());
	return 0;
}
