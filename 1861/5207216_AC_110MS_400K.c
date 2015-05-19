#include <stdio.h>
#include <stdlib.h>
#define MAXM 15002
#define MAXN 1002
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXM];
int parent[MAXN], rank[MAXM], ans[MAXM];
int n, m;
int make_set(int n)
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
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	return e1->w - e2->w;
}
void kruskal()
{
	int max, i, j;
	qsort((void*)e, m, sizeof(e[0]), cmp);
	make_set(n);
	max = 0;
	j = 0;
	for(i = 0;i < m; i++) 
	{
		if(union_set(e[i].u, e[i].v))
		{
			ans[j++] = i;
			if(max < e[i].w) max = e[i].w;
		}
	}
	printf("%d\n", max);
	printf("%d\n", j);
	for(i = 0;i < j; i++) printf("%d %d\n", e[ans[i]].u, e[ans[i]].v);
}
int main()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0;i < m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	kruskal();
	return 0;
}
