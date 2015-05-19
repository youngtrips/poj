#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-20
#define MAXM 499502
#define MAXN 1002
#define dis(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
typedef struct
{
	int u;
	int v;
	double w;
}Edge;
Edge e[MAXM];
char flag[MAXN][MAXN];
int rank[MAXN] ,parent[MAXN], tot, n;
double x[MAXN], y[MAXN];
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	return e1->w > e2->w ? 1 : -1;
}
int find_set(int x)
{
	if(x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}
int union_set(int r1, int r2)
{
	int x = find_set(r1);
	int y = find_set(r2);
	if(x == y) return 0;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	return 1;
}
int main()
{
	double cost;
	int m, i, j;
	scanf("%d %d", &n, &m);
	memset(flag, '0', sizeof(flag));
	for(i = 1;i <= n; i++)
	{
		rank[i] = 0;
		parent[i] = i;
		scanf("%lf %lf", &x[i], &y[i]);
	}
	while(m--)
	{
		scanf("%d %d", &i, &j);
		flag[i][j] = '1';
		flag[j][i] = '1';
	}
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			e[tot].u = i;
			e[tot].v = j;
			if(flag[i][j] == '1' || flag[j][i] == '1') e[tot].w = 0.0;
			else e[tot].w = dis(i, j);
			tot++;
		}
	}
	cost = 0.0;
	qsort((void*)e, tot, sizeof(e[0]), cmp);
	//for(i = 0;i < tot; i++) if(union_set(e[i].u, e[i].v)) cost += e[i].w;
	printf("%0.2lf\n", cost);
	return 0;
}
