#include <stdio.h>
#include <stdlib.h>
#define MAXV 102
#define MAXE 10000
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
Edge e[MAXE];
int parent[MAXV];
int rank[MAXV];
int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;
	return e1->w - e2->w;
}
int findSet(int x)
{
	if(x != parent[x]) parent[x] = findSet(parent[x]);
	return parent[x];
}
int  unionSet(int root1, int root2)
{
	int x = findSet(root1);
	int y = findSet(root2);
	if(x == y) return 0;
	if(rank[x] > rank[y]) parent[y] = x;
	else
	{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	return 1;
}
void makeSet(int n)
{
	int i;
	for(i = 0;i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}
int kruskal(Edge* e, int n_edge, int n_v)
{
	int cost, i;
	qsort((void*)e, n_edge, sizeof(e[0]), cmp);
	cost = 0;
	for(i = 0;i < n_edge; i++)
	{
		if(unionSet(e[i].u, e[i].v)) cost += e[i].w;
	}
	return cost;
}
int build_graph(int n)
{
	int i, j, w, k = 0;
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			scanf("%d", &w);
			if(i < j)
			{
				e[k].u = i;
				e[k].v = j;
				e[k].w = w;
				k++;
			}
		}
	}
	return k;
}
int main()
{
	char w;
	int n_edge, n_v, res, q, a, b;
	while(scanf("%d", &n_v) != EOF)
	{
		n_edge = build_graph(n_v);
		makeSet(n_v);
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &a, &b);
			unionSet(a, b);
		}
		res = kruskal(e, n_edge, n_v);
		printf("%d\n", res);
	}
	return 0;
}
