#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXM 500002
#define MAXN 1002
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXM];
int rank[MAXN], parent[MAXN], tot, n;
int adj[MAXN][MAXN], flag[MAXN], pre[MAXN];
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
	int i;
	scanf("%d %d", &n, &tot);
	for(i = 0;i < tot; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	memset(flag, 0, sizeof(flag));
	memset(adj, -1, sizeof(adj));
	memset(pre, -1, sizeof(pre));
}
void kruskal()
{
	int i;
	qsort((void*)e, tot, sizeof(e[0]), cmp);
	make_set(n);
	for(i = 0;i < tot; i++)
	{
		if(union_set(e[i].u, e[i].v))
		{
			adj[e[i].u][e[i].v] = e[i].w;
			adj[e[i].v][e[i].u] = e[i].w;
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
			if(i == n) break;
			dfs(i);
		}
	}
}
int main()
{
	int min, c, t, i, w;
	scanf("%d", &c);
	for(t = 1;t <= c; t++)
	{
		init();
		kruskal();
		dfs(1);
		i = n;
		min = 9000000;
		while(pre[i] != -1)
		{
			w = adj[pre[i]][i];
			if(min > w) min = w;
			i = pre[i];
		}
		printf("Scenario #%d:\n", t);
		printf("%d\n\n", min);
	}
	return 0;
}
