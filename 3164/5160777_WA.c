#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define CLS(x) memset(x,0,sizeof(x))
#define SQR(x) (x)*(x)
#define MAXM 10002
#define MAXN 102
typedef struct
{
	int u;
	int v;
	double w;
}Edge;
Edge e[MAXM];
double x[MAXN], y[MAXN];
int adj[MAXN][MAXN], v[MAXN];
int rank[MAXN];
int parent[MAXN];
int tot, n, m;
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	return e1->w - e2->w;
}
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
	return 1;
}
void init()
{
	int i, j;
	for(i = 1;i <= n; i++) scanf("%lf %lf", &x[i], &y[i]);
	CLS(adj);
	CLS(v);
	tot = 0;
	while(m--)
	{
		scanf("%d %d", &i, &j);
		adj[i][j] = 1;
		e[tot].u = i;
		e[tot].v = j;
		e[tot].w = sqrt(SQR(x[i] - x[j]) + SQR(y[i] - y[j]));
		tot++;
	}
}
void dfs(int st)
{
	int i;
	v[st] = 1;
	for(i = 1;i <= n; i++) if(adj[st][i] && v[i] == 0) dfs(i);
}
int check()
{
	int i;
	dfs(1);
	for(i = 1;i <= n; i++) if(v[i] == 0) return 0;
	return 1;
}
double kruskal()
{
	double cost;
	int i;
	make_set(n);
	cost = 0.0;
	qsort((void*)e, tot, sizeof(e[0]), cmp);
	for(i = 0;i < tot; i++)
		if(union_set(e[i].u, e[i].v)) cost += e[i].w;
	return cost;
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		init();
		if(check() == 0) printf("poor snoopy\n");
		else
		{
			printf("%0.2lf\n", kruskal());
		}
	}
	return 0;
}
