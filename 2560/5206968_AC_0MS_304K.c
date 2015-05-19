#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define dis(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
#define MAXM 5002
#define MAXN 102
typedef struct
{
	int u;
	int v;
	double w;
}Edge;
Edge e[MAXM];
double x[MAXN], y[MAXN];
int parent[MAXN], rank[MAXN], tot, n;
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		rank[i] = 0;
		parent[i] = i;
	}
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
}
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	if(e1->w < e2->w) return -1;
	else return 1;
}
double kruskal()
{
	double cost = 0.0;
	int i;
	qsort((void*)e, tot, sizeof(e[0]), cmp);
	make_set(n);
	for(i = 0;i < tot; i++) if(union_set(e[i].u, e[i].v)) cost += e[i].w;
	return cost;
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1;i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++) 
		{
			e[tot].u = i;
			e[tot].v = j;
			e[tot].w = dis(i, j);
			tot++;
		}
	}
	printf("%0.2lf\n", kruskal());
	return 0;
}
