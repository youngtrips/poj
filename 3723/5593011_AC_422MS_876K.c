#include <stdio.h>
#include <stdlib.h>
#define MAXM 50002
#define MAXN 10002
typedef struct
{
	int u; int v; int w;
}edge_t;
edge_t e[MAXM];
int parent[MAXN + MAXN];
int rank[MAXN + MAXN];
int tot;
int n, m;
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
	if(x !=parent[x]) parent[x] = find_set(parent[x]);
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
void add(int u, int v, int w) { e[++tot].u = u; e[tot].v = v; e[tot].w = w;}
int cmp(const void* p1, const void* p2)
{
	edge_t* a = (edge_t*)p1;
	edge_t* b = (edge_t*)p2;
	return b->w - a->w;
}
void init()
{
	int r, u, v, w;
	tot = 0;
	scanf("%d %d %d", &n, &m, &r);
	while(r--)
	{
		scanf("%d %d %d", &u, &v, &w);
		u++; v += n + 1;
		add(u, v, w);
	}
}
void solve()
{
	int ans, sum, i;
	qsort((void*)&e[1], tot, sizeof(e[1]), cmp);
	make_set(n + m);
	ans = 10000 * (n + m); sum = 0;
	for(i = 1;i <= tot; i++) if(union_set(e[i].u, e[i].v)) sum += e[i].w;
	printf("%d\n", ans - sum);
}
int main()
{
	int ans, t;
	scanf("%d", &t);
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}
