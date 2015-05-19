#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define dist(i,j) (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])))
#define eps 1e-20
#define MAXN 502
#define MAXM 250002
typedef struct
{
	int u;
	int v;
	double w;
}edge_t;
edge_t e[MAXM];
int parent[MAXN], rank[MAXN], tot, n, s, p;
double x[MAXN], y[MAXN];
int cmp(const void* p1, const void* p2)
{
	edge_t* a = (edge_t*)p1;
	edge_t* b = (edge_t*)p2;
	if(a->w + eps < b->w) return -1;
	return 1;
}
void make_set(int n)
{
	int i;
	for(i = 1;i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
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
	return 1;
}
void init()
{
	int i, j;
	scanf("%d %d", &s, &n);
	for(i = 1;i <= n; i++) scanf("%lf %lf", x + i, y + i);
	tot = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = i + 1;j <= n; j++)
		{
			e[tot].u = i;
			e[tot].v = j;
			e[tot].w = dist(i, j);
			tot++;
		}
	}
	qsort((void*)e, tot, sizeof(e[0]), cmp);
}
void kruskal()
{
	int i;
	make_set(n);
	p = 0;
	for(i = 0;i < tot; i++) if(union_set(e[i].u, e[i].v)) x[p++] = e[i].w;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		kruskal();
		printf("%0.2f\n", x[p - s]);
	}
	return 0;
}
