#include <stdio.h>
#include <stdlib.h>
#define MAXM 10002
#define MAXN 2002
typedef struct
{
	int u;
	int v;
	int w;
}edge_t;
edge_t e[MAXM];
int parent[MAXN];
int rank[MAXN];
int tot, n, m;
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
int cmp(const void* p1, const void* p2)
{
	edge_t* a = (edge_t*)p1;
	edge_t* b = (edge_t*)p2;
	if(a->w > b->w) return 1;
	else if(a->w == b->w) return 0;
	else return -1;
}
void init()
{
	scanf("%d %d", &n, &m);
	for(tot = 1;tot <= m; tot++) scanf("%d %d %d", &e[tot].u, &e[tot].v, &e[tot].w);
}
int kruskal()
{
	int res, i;
	qsort((void*)&e[1], tot, sizeof(e[1]), cmp);
	make_set(n);
	res = 0;
	for(i = 1;i <= tot; i++)
	{
		if(union_set(e[i].u, e[i].v)) res = (e[i].w > res ? e[i].w : res);
	}
	printf("%d\n", res);
}
int main()
{
	init();
	kruskal();
	return 0;
}
