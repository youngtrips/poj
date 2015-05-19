#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define dis(i,j) sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))
#define MAXM 20002
#define MAXN 202
#define eps 1e-20
typedef struct
{
	int u;
	int v;
	double w;
}Edge;
Edge e[MAXM];
int adj[MAXN][MAXN], tot, n;
int parent[MAXN], rank[MAXN];
int flag[MAXN], pre[MAXN];
double x[MAXN], y[MAXN], max, tmp;
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	if(e1->w < e2->w) return -1;
	return 1;
}
void make_set(int n)
{
	int i;
	for(i = 0;i <= n; i++) 
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
int init()
{
	int i, j;
	scanf("%d", &n);
	if(n == 0) return 0;
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
	memset(flag, 0, sizeof(flag));
	memset(pre, -1, sizeof(pre));
	return 1;
}
void kruskal()
{
	int i;
	qsort((void*)e, tot, sizeof(e[0]), cmp);
	make_set(n);
	memset(adj, -1, sizeof(adj));
	for(i = 0;i < tot; i++)
	{
		if(union_set(e[i].u, e[i].v))
		{
			adj[e[i].u][e[i].v] = i;
			adj[e[i].v][e[i].u] = i;
		}
	}
}
void dfs(int st)
{
	int i;
	flag[st] = 1;
	for(i = 1;i <= n; i++)
	{
		if(adj[st][i] > -1 && flag[i] == 0)
		{
			pre[i] = st;
			if(i == 2) break;
			dfs(i);
		}
	}
}
int main()
{
	int i, j = 1;
	while(init())
	{
		kruskal();
		dfs(1);
		max = 0.0;
		i = 2;
		while(pre[i] !=  -1)
		{
			tmp = e[adj[i][pre[i]]].w;
			if(max + eps < tmp) max = tmp;
			i = pre[i];
		}
		printf("Scenario #%d\n", j++);
		printf("Frog Distance = %0.3lf\n\n", max);
	}
	return 0;
}
